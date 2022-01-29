'use strict';
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");


const HoverProvider = {
	provideHover(document, position, token) {
		var hoveredWord = document.getText(document.getWordRangeAtPosition(position));	//`Word` is defined by "wordPattern" in `urcl.language-configuration.json`
		var markdownString = new vscode.MarkdownString();
		var numericBase;
		
		var regexHex = /^(~?[+-])?0x[\dA-F]+$/i;
		var regexDec = /^(~?[+-])?\d+$/;
		var regexOct = /^(~?[+-])?0o[0-7]+$/i;
		var regexBin = /^(~?[+-])?0b[01]+$/i;
		var regexChar = /^'(\\u[\dA-F]{4}|\\?.)'+$/i;
		
		// test if the selected word is a number and assign a numeric base
		if ((regexChar.test(hoveredWord.toString()))) numericBase = 128; //128 could be any number
		else if ((regexHex.test(hoveredWord.toString()))) numericBase = 16;
		else if ((regexDec.test(hoveredWord.toString()))) numericBase = 10;
		else if ((regexOct.test(hoveredWord.toString()))) numericBase = 8;
		else if ((regexBin.test(hoveredWord.toString()))) numericBase = 2;
		
		if (numericBase) {
			var numeric;
			hoveredWord = hoveredWord.replace(/^~[+-]?|^0[box]/, ''); //remove prefixes

			if (numericBase == 128)
			{
				if (hoveredWord.charCodeAt(1) == 92)
					switch (hoveredWord.charAt(2)) {
						case 'a': 	numeric = 7;	break;
						case 'b': 	numeric = 8;	break;
						case 't': 	numeric = 9;	break;
						case 'n': 	numeric = 10;	break;
						case 'v': 	numeric = 11;	break;
						case 'f': 	numeric = 12;	break;
						case 'r': 	numeric = 13;	break;
						case 'e': 	numeric = 27;	break;
						case '\\': 	numeric = 92;	break;
						case 'u':
							numeric = parseInt(hoveredWord.replace(/^'\\u|'$/, ''), 16);
							numericBase = 0xFFFF;
							break;
						default:
							numeric = hoveredWord.charCodeAt(3);
							break;
					}
				else
					numeric = hoveredWord.charCodeAt(1);
			}
			else
				numeric = parseInt(hoveredWord, numericBase);
			
			var string = '';
			//only display chars that are within unicode range 0-0xFFFF
			if (numericBase != 128 && numeric >= 0 && numeric <= 0xFFFF)
			{
				string += '\'';	//instead of typing it for every case
				switch (numeric) {
					case 7: 	string += '\\a';	break;
					case 8: 	string += '\\b';	break;
					case 9: 	string += '\\t';	break;
					case 10: 	string += '\\n';	break;
					case 11: 	string += '\\v';	break;
					case 12: 	string += '\\f';	break;
					case 13: 	string += '\\r';	break;
					case 27: 	string += '\\e';	break;
					case 92: 	string += '\\\0';	break;
					case 127: 	string += '\u2421';	break;
					case 160: 	string += 'NBSP';	break;
					case 173: 	string += 'SHY';	break;
					default:
						string += String.fromCharCode(numeric + (numeric < 32 ? 0x2400 : 0))
				}
				string += '\'\n';	//instead of typing it for every case
			}
			//don't display the number in the same base as the input
			if (numericBase != 10)
				string += `${numeric}\n`;
			if (numericBase != 16)
				string += `${numeric < 0 ? '-' : ''}0x${Math.abs(numeric).toString(16).toUpperCase()}\n`;	//I don't like negatives
			if (numericBase != 8)
				string += `${numeric < 0 ? '-' : ''}0o${Math.abs(numeric).toString(8)}\n`;
			if (numericBase != 2)
				string += `${numeric < 0 ? '-' : ''}0b${Math.abs(numeric).toString(2)}\n`;
			
			markdownString.appendCodeblock(string, 'javascript');
			return { contents: [markdownString] };
		}
	}
}


class DocCodeLens extends vscode.CodeLens {
	/**
	 * Adds doc to the code lens object.
	 *
	 * @param range The range to which this code lens applies.
	 * @param doc The command associated to this code lens.
	 * @param symbol The matchedText to which this code lens applies.
	 */
	constructor(doc, range, matchedText) {
		super(range);
		this.document = doc;
		this.symbol = matchedText;
	}
}
const CodelensProvider = {
	provideCodeLenses(document, token) {
		var codeLenses = [];
		const regex = /(?<=^[ \t]*)\.\w+/gm;	// why can I not use \s* to match whitespace??
		const text = document.getText();
		let matches;
		while ((matches = regex.exec(text)) !== null) {	// searches entire document and stops at first match
			const lineIndex = document.positionAt(matches.index).line; // get line index relative to document
			const characterIndex = document.lineAt(lineIndex).text.indexOf(matches[0]); // get character index relative to line
			const range = new vscode.Range(lineIndex, characterIndex, lineIndex, characterIndex + matches[0].length); // create range around match
			// codeLenses.push(new vscode.CodeLens(range));
			codeLenses.push(new DocCodeLens(document, range, matches[0])); // need to pass document across
		}
		// vscode.window.showInformationMessage(JSON.stringify(codeLenses));
		return codeLenses;
	},
	resolveCodeLens(codeLens, token) {
		const doc = codeLens.document;
		const text = doc.getText();
		const position = codeLens.range.start;
		const label = new RegExp('(?<!^[ 	]*)\\B' + codeLens.symbol + '\\b', 'gm'); // Why can't I use \s?
		
		var locations = [];
		
		var matches;
		var i = 0;
		while ((matches = label.exec(text)) !== null) {
			const lineIndex = doc.positionAt(matches.index).line; // get line index relative to document
			const characterIndex = doc.lineAt(lineIndex).text.indexOf(matches[0]); // get character index relative to line
			locations.push(new vscode.Location(doc.uri, new vscode.Range(lineIndex, characterIndex, lineIndex, characterIndex + matches[0].length)));
			// add the doc.uri and matched text range to the list of locations
			i++;
		}
		
		codeLens.command = {
			title: `Refs: ${i}`,
			tooltip: `Peek: ${codeLens.symbol}`,
			command: 'editor.action.showReferences',
			arguments: [
				doc.uri,
				position,
				locations
			]
		};
		return codeLens;
	}
}


const ReferenceProvider = {
	provideReferences(document, position, context, token) {
		// const searchWord = document.getText(document.getWordRangeAtPosition(position));
		// const searchRegex = new RegExp('(?<!\w)' + searchWord + '\\b', 'gm');
		const locations = [];
		locations.push(document.uri);
		locations.push(vscode.Range(new vscode.Position(10, 0), new vscode.Position(10, 7)));
		locations.push(vscode.Location(doc.uri, new vscode.Range(7, 7, 5, 10)));
		vscode.window.showInformationMessage(JSON.stringify(locations));
		return locations;
	}
}

const DocumentLinkProvider = {
	provideTextDocumentContent(uri) {
		vscode.window.showInformationMessage(JSON.stringify(uri));
		
	},
	provideDocumentLinks(document, token) {
		// const range = new vscode.Range(1, 1, 1, 4);
		// const link = new vscode.DocumentLink(range, document.uri);
		// return link;
		const doc = document.get(document.uri.toString());
		vscode.window.showInformationMessage(JSON.stringify(doc.links));
		if (doc) {
			return doc.links;
		}
	},
	resolveDocumentLink(link, token) {
		vscode.window.showInformationMessage(JSON.stringify(link));
	}
}


// main()
const fileSelector = [
	{ scheme: 'file', language: '.urcl' },
	{ scheme: 'file', language: '.simple.urcl' },
	{ scheme: 'file', pattern: '**/*.urcl' }
];
function activate(context) {
	context.subscriptions.push(vscode.languages.registerHoverProvider(fileSelector, HoverProvider));
	context.subscriptions.push(vscode.languages.registerCodeLensProvider(fileSelector, CodelensProvider));
	// context.subscriptions.push(vscode.languages.registerReferenceProvider(fileSelector, ReferenceProvider));
	context.subscriptions.push(vscode.languages.registerDocumentLinkProvider(fileSelector, DocumentLinkProvider));
	
	// vscode.window.showInformationMessage(JSON.stringify());
}


exports.activate = activate;
function deactivate() { }
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map