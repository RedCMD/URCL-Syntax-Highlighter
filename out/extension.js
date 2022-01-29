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

// main()
const fileSelector = [
	{ scheme: 'file', language: '.urcl' },
	{ scheme: 'file', language: '.simple.urcl' },
	{ scheme: 'file', pattern: '**/*.urcl' }
];
function activate(context) {
	context.subscriptions.push(vscode.languages.registerHoverProvider(fileSelector, HoverProvider));
	
	// vscode.window.showInformationMessage(JSON.stringify());
}


exports.activate = activate;
function deactivate() { }
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map