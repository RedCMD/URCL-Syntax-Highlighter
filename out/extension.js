'use strict';
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");


function insertBlanks(string, index, length) {
	const chars = new Array(length + 1).join(' ')
	return string.substring(0, index) + chars + string.substring(index + length)
}


// replaces // line-comments and /* block-comments */ with spaces
// while taking "strings" and 'chars' into account
function sanitizeText(text, option) {
	let match = []
	let matchBlockComment = []
	const regex = /(\/\/.*?$)|(\/\*.*?\*\/)|(".*?"|'.*?')/gms	// s modifier allows . to match newlines \r\n
	const regexBlockComment = /.+/g	// . cannot match newlines
	
	while (match = regex.exec(text))
		if (match[1])	// remove //line comments
			text = insertBlanks(text, match.index, match[0].length)
		else if (match[2])	// remove /*block comments*/
			while (matchBlockComment = regexBlockComment.exec(match[2]))	// does not remove \n newlines
				text = insertBlanks(text, match.index + matchBlockComment.index, matchBlockComment[0].length)
		else if (option)	// remove "strings" and 'chars'
			text = insertBlanks(text, match.index + 1, match[0].length - 2)

	// vscode.window.showInformationMessage(text)
	return text
}


function getLabels(document, option) {
	let match = []
	let labels = []
	let regex
	const text = sanitizeText(document.getText(), true)

	switch (option) {
		default:	regex = /\B\.\w+/g;						break	// all .labels
		case 1:		regex = /(?<!^[\t\f\v ]*)\B\.\w+/gm;	break	// only reference .labels
		case 2:		regex = /(?<=^[\t\f\v ]*)\.\w+/gm;		break	// only definition .labels
	}

	while (match = regex.exec(text)) {
		const positionStart = document.positionAt(match.index)
		const positionEnd = document.positionAt(match.index + match[0].length)
		const range = new vscode.Range(positionStart, positionEnd)
		labels.push({ document: document, range: range, symbol: match[0] })
	}
	// vscode.window.showInformationMessage(JSON.stringify(labels))
	return labels
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

const CodelensProvider = {
	provideCodeLenses(document, token) {

		// vscode.window.showInformationMessage(JSON.stringify(getLabels(document, 2)))
		return getLabels(document, 2)
	},
	resolveCodeLens(codeLens, token) {
		const document = codeLens.document
		const position = codeLens.range.start
		const symbol = codeLens.symbol
		let labels = getLabels(document, 1)
		let label
		let locations = []
		let i = 0

		while (label = labels.pop()) {
			if (label.symbol == symbol) {
				const location = new vscode.Location(document.uri, label.range)
				locations.push(location)
				i++
			}
		}

		codeLens.command = {
			title: `Refs: ${i}`,
			tooltip: `${codeLens.symbol}`,
			command: 'editor.action.showReferences',
			arguments: [
				document.uri,
				position,
				locations
			]
		}
		return codeLens
	}
}


const ReferenceProvider = {
	provideReferences(document, position, context, token) {
		const hoveredWord = document.getText(document.getWordRangeAtPosition(position));	//`Word` is defined by "wordPattern" in `urcl.language-configuration.json`
		const regexlabel = new RegExp(/^\.\w+$/m); // .label

		if (regexlabel.test(hoveredWord)) {	// test if selected word is a .label
			let labels = getLabels(document, 0)	// get a list of all labels in doc
			let label
			let locations = []
			
			while (label = labels.pop())
				if (hoveredWord == label.symbol)	// test if .label in doc is same as selected .label
					locations.push(new vscode.Location(document.uri, label.range))
			
			return locations;
		}
	}
}


const DefinitionProvider = {
	provideDefinition(document, position, token) {
		const hoveredWord = document.getText(document.getWordRangeAtPosition(position));	//`Word` is defined by "wordPattern" in `urcl.language-configuration.json`
		const regexlabel = new RegExp(/^\.\w+$/m); // .label
		
		if (regexlabel.test(hoveredWord)) {	// test if selected word is a .label
			let labels = getLabels(document, 2)	// get a list of all labels in doc
			let label
			let locations = []
			
			while (label = labels.pop())
				if (hoveredWord == label.symbol)	// test if .label in doc is same as selected .label
					locations.push(new vscode.Location(document.uri, label.range))
			
			if (!locations)
				locations.push(new vscode.Location(document.uri, document.getWordRangeAtPosition(position)))

			return locations;
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