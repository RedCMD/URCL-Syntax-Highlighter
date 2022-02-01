'use strict';
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");




function replace(string, start, end) {
	const chars = new Array(end - start + 1).join(' ')
	return string.substring(0, start) + chars + string.substring(end)
}


function sanitizeText(text) {
	let j
	for (let i = 0; i < text.length; i++) {
		const element = text[i];
		switch (element) {
			case '/':
				switch (text[i + 1]) {
					case '/':
						for (j = i + 1; j < text.length; j++) {
							if (text[j] == '\r' || text[j] == '\n')
								break
						}
						text = replace(text, i, j)
						i = j
						break
					case '*':
						for (j = i + 1; j < text.length; j++) {
							if (text[j] == '\r' || text[j] == '\n') {
								text = replace(text, i, j)
								i = j + 1
							}
							if (text[j] == '*') {
								if (text[j + 1] == '/') {
									j += 2
									break
								}
							}
						}
						text = replace(text, i, j)
						i = j
						break
					default:
						i++
				}
				break
			case '"':
				for (j = i + 1; j < text.length; j++) {
					if (text[j] == '"') {
						text = replace(text, i + 1, j)
						i = j
						break
					}
					if (text[j] == '\r' || text[j] == '\n')
						break
				}
				break
			case "'":
				for (j = i + 1; j < text.length; j++) {
					if (text[j] == "'") {
						text = replace(text, i + 1, j)
						i = j
						break
					}
					if (text[j] == '\r' || text[j] == '\n')
						break
				}
				break
		}
	}
	// vscode.window.showInformationMessage(JSON.stringify(text))
	// vscode.window.showInformationMessage(text)
	return text
}


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
		var codeLenses = []
		const regex = /(?<=^[ \t]*)\.\w+\b/gm	// why can I not use \s* to match whitespace??
		// const text = document.getText()
		const text = sanitizeText(document.getText())
		let matches;
		// vscode.window.showInformationMessage(JSON.stringify(text));
		while ((matches = regex.exec(text)) !== null) {	// searches entire document and stops at each match
			const positionStart = document.positionAt(matches.index)
			const positionEnd = document.positionAt(matches.index + matches[0].length)
			const range = new vscode.Range(positionStart, positionEnd)
			// const lineIndex = document.positionAt(matches.index).line; // get line index relative to document
			// const characterIndex = document.lineAt(lineIndex).text.indexOf(matches[0]); // get character index relative to line
			// const range = new vscode.Range(lineIndex, characterIndex, lineIndex, characterIndex + matches[0].length); // create range around match
			// codeLenses.push(new vscode.CodeLens(range));
			codeLenses.push(new DocCodeLens(document, range, matches[0])) // need to pass document across
		}
		// vscode.window.showInformationMessage(JSON.stringify(codeLenses));
		return codeLenses;
	},
	resolveCodeLens(codeLens, token) {
		const doc = codeLens.document
		// const text = doc.getText()
		const text = sanitizeText(doc.getText())
		const position = codeLens.range.start
		const label = new RegExp('(?<!^[ 	]*)\\' + codeLens.symbol + '\\b', 'gm') // Why can't I use \s?
		
		var locations = [];
		
		var i = 0
		var matches;
		while ((matches = label.exec(text)) !== null) {
			const positionStart = doc.positionAt(matches.index)
			const positionEnd = doc.positionAt(matches.index + matches[0].length)
			const range = new vscode.Range(positionStart, positionEnd)
			const location = new vscode.Location(doc.uri, range)
			locations.push(location)
			// const lineIndex = doc.positionAt(matches.index).line; // get line index relative to document
			// const characterIndex = doc.lineAt(lineIndex).text.indexOf(matches[0]); // get character index relative to line
			// locations.push(new vscode.Location(doc.uri, new vscode.Range(lineIndex, characterIndex, lineIndex, characterIndex + matches[0].length))); // add the doc.uri and matched text range to the list of locations
			i++
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
		const hoveredWord = document.getText(document.getWordRangeAtPosition(position));	//`Word` is defined by "wordPattern" in `urcl.language-configuration.json`
		const regexlabel = new RegExp(/\.\w+/);
		if (regexlabel.test(hoveredWord)) {
			// const text = document.getText();
			const text = sanitizeText(document.getText())
			const regex = new RegExp('\\B' + hoveredWord + '\\b', 'gm');	// why can I not use \s* to match whitespace??
		
			var locations = [];
			var matches = [];
			while ((matches = regex.exec(text)) !== null) {
			
				// const lineIndex = document.positionAt(matches.index).line; // get line index of match relative to document
				// const characterIndex = document.lineAt(lineIndex).text.indexOf(matches[0]); // get character index of match relative to line
				// const range = new vscode.Range(lineIndex, characterIndex, lineIndex, characterIndex + matches[0].length);
				// const range = new vscode.Range(document.positionAt(matches.index), document.positionAt(matches.index + matches[0].length));
				const positionStart = document.positionAt(matches.index);
				const positionEnd = document.positionAt(matches.index + matches[0].length);
				const range = new vscode.Range(positionStart, positionEnd);
				locations.push(new vscode.Location(document.uri, range));
				vscode.window.showInformationMessage(JSON.stringify(locations));
			}
			return locations;
		}
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


const DefinitionProvider = {
	provideDefinition(document, position, token) {
		const text2 = sanitizeText(document.getText())
		const hoveredWord = document.getText(document.getWordRangeAtPosition(position));	//`Word` is defined by "wordPattern" in `urcl.language-configuration.json`
		// const hoveredWord = document.getText(document.getWordRangeAtPosition(position));	//`Word` is defined by "wordPattern" in `urcl.language-configuration.json`
		const regexlabel = new RegExp(/\B\.\w+\b/);
		
		if (regexlabel.test(hoveredWord)) {
			// const text = document.getText();
			const text = sanitizeText(document.getText())
			
			const regex = new RegExp('(?<=^[ 	]*)' + hoveredWord + '\\b', 'gm');	// why can I not use \s* to match whitespace?? hoveredWord
			var locations = [];
			var matches = [];
			while ((matches = regex.exec(text)) !== null) {
				// const lineIndex = document.positionAt(matches.index).line; // get line index of match relative to document
				// const characterIndex = document.lineAt(lineIndex).text.indexOf(matches[0]); // get character index of match relative to line
				// const range = new vscode.Range(lineIndex, characterIndex, lineIndex, characterIndex + matches[0].length);
				const positionStart = document.positionAt(matches.index);
				const positionEnd = document.positionAt(matches.index + matches[0].length);
				const range = new vscode.Range(positionStart, positionEnd);
				locations.push(new vscode.Location(document.uri, range));
			}
			// vscode.window.showInformationMessage(JSON.stringify(locations));
			return locations;
				const lineIndex = document.positionAt(match.index).line; // get line index of match relative to document
				const characterIndex = document.lineAt(lineIndex).text.indexOf(match[0]); // get character index of match relative to line
				const range = new vscode.Range(lineIndex, characterIndex, lineIndex, characterIndex + match[0].length);
				const location = new vscode.Location(document.uri, range);
			
				return location;
			}
		}
	}
}


const fileSelector = [
	{ scheme: 'file', language:	'urcl'			},
	{ scheme: 'file', language:	'.urcl'			},
	{ scheme: 'file', language:	'.simple.urcl'	},
	{ scheme: 'file', pattern:	'**/*.urcl'		},
	{ scheme: 'file', pattern:	'**/*.urclpp'	},
	{ scheme: 'file', pattern:	'**/urcl'		},
	{ scheme: 'file', pattern:	'**/urclpp'		}
];
// main()
function activate(context) {
	context.subscriptions.push(vscode.languages.registerHoverProvider(fileSelector, HoverProvider)); // Numeric hovers
	context.subscriptions.push(vscode.languages.registerCodeLensProvider(fileSelector, CodelensProvider)); // overhead .label references
	context.subscriptions.push(vscode.languages.registerReferenceProvider(fileSelector, ReferenceProvider)); // shift+F12 .label locations
	context.subscriptions.push(vscode.languages.registerDefinitionProvider(fileSelector, DefinitionProvider)); // ctrl+click .label definition
	// context.subscriptions.push(vscode.workspace.onDidChangeTextDocument()); // update while typing
	// context.subscriptions.push(vscode.languages.registerDocumentLinkProvider(fileSelector, DocumentLinkProvider));
	// context.subscriptions.push(vscode.window.registerFileDecorationProvider());

	// vscode.window.showInformationMessage(JSON.stringify(context));
}


exports.activate = activate;
function deactivate() { }
exports.deactivate = deactivate;