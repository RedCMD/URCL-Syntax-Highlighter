'use strict';
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");

const HoverProvider = {
	provideHover(document, position, token) {
		var hoveredWord = document.getText(document.getWordRangeAtPosition(position));
		var markdownString = new vscode.MarkdownString();
		var numericBase = null;
		
		var regexHex = /^(~?[+-])?0x[\dA-F]+$/i;
		var regexDec = /^(~?[+-])?\d+$/;
		var regexOct = /^(~?[+-])?0o[0-7]+$/i;
		var regexBin = /^(~?[+-])?0b[01]+$/i;
		var regexChar = /^'(.|\\.)'+$/;
		
		// test if the selected word is a number and assign a numeric base
		if ((regexChar.test(hoveredWord.toString()))) numericBase = 128; //128 could be any number
		else if ((regexHex.test(hoveredWord.toString()))) numericBase = 16;
		else if ((regexDec.test(hoveredWord.toString()))) numericBase = 10;
		else if ((regexOct.test(hoveredWord.toString()))) numericBase = 8;
		else if ((regexBin.test(hoveredWord.toString()))) numericBase = 2;
		
		if (numericBase) {
			var numeric = hoveredWord.replace(/^~[+-]?|^0[box]/, ''); //remove prefixes
			
			if (numericBase == 128)
			{
				if (numeric.charCodeAt(1) == 92)
					switch (numeric.charAt(2)) {
						case 'a': 	numeric = 7;	break;
						case 'b': 	numeric = 8;	break;
						case 't': 	numeric = 9;	break;
						case 'n': 	numeric = 10;	break;
						case 'v': 	numeric = 11;	break;
						case 'f': 	numeric = 12;	break;
						case 'r': 	numeric = 13;	break;
						case 'e': 	numeric = 27;	break;
						case '\\': 	numeric = 92;	break;
						default:
							numeric = numeric.charCodeAt(2);
							break;
					}
				else
					numeric = numeric.charCodeAt(1);
			}
			else
				numeric = parseInt(numeric, numericBase);
			
			
			var string = '';
			//don't redisappear the number in the exact same base
			if (numericBase != 128)
			{
				string += '\'';
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
					case 255: 	string += 'NBSP';	break;
					default:
						string += String.fromCharCode(numeric + (numeric < 32 ? 0x2400 : 0))
				}
				string += '\'\n';
			}
			if (numericBase != 16)
				string += `${numeric < 0 ? '-' : ''}0x${Math.abs(numeric).toString(16).toUpperCase()}\n`;
			if (numericBase != 10)
				string += `${numeric}\n`;
			if (numericBase != 8)
				string += `${numeric < 0 ? '-' : ''}0o${Math.abs(numeric).toString(8)}\n`;
			if (numericBase != 2)
				string += `${numeric < 0 ? '-' : ''}0b${Math.abs(numeric).toString(2)}\n`;
			
			markdownString.appendCodeblock(string, 'javascript');
			return { contents: [markdownString] };
		}
	}
}

// main
function activate(context) {
	context.subscriptions.push(vscode.languages.registerHoverProvider({ language: '.urcl' }, HoverProvider));
	context.subscriptions.push(vscode.languages.registerHoverProvider({ language: '.simple.urcl' }, HoverProvider));
	context.subscriptions.push(vscode.languages.registerDefinitionProvider(DefinitionProvider));
	
}
exports.activate = activate;
function deactivate() { }
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map