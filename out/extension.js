'use strict';
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");

const HoverWords = [
	//	MACRO
	{
		symbol: "@DEFINE",
		name: "Macro",
		example: "@DEFINE name 10",
		operands: [["Name", "Macro"], ["Register", "Immediate", "Label", "Memory", "Macro"]],
		description: '"Macro"',
	},
	//	HEADERS
	{
		symbol: "BITS",
		name: "Bits",
		example: "BITS == 16",
		operands: [["Bits"], ["Immediate", "Macro"]],
		description: '"The required CPU word length supported by the program"',
	},
	{
		symbol: "MINREG",
		name: "Minimum registers",
		example: "MINREG 16",
		operands: [["Run"]],
		description: '"The minimum number of general purpose registers required by the program"',
	},
	{
		symbol: "MINHEAP",
		name: "Minimum heap",
		example: "MINHEAP 64",
		operands: [["Immediate"]],
		description: '"The minimum number of words of Heap required by the program"\n"The Heap is separate from the RAM used to store the program itself and the RAM used for the stack"',
	},
	{
		symbol: "MINSTACK",
		name: "Minimum stack",
		example: "MINSTACK 16",
		operands: [["Immediate"]],
		description: '"The minimum number of words in the stack"',
	},
	{
		symbol: "RUN",
		name: "Run mode",
		example: "RUN RAM",
		operands: [["Immediate"]],
		description: '"States whether or not the program must be stored in RAM"\n"Which can be read and written to during program execution"\n"This is for accessing .data values stored in the instructions"',
	},
	//	DEFINED IMMEDIATE VALUES
	{
		symbol: "@BITS",
		name: "Bits",
		example: "@BITS",
		operands: [],
		description: '"Equal to the value of the BITS header"',
	},
	{
		symbol: "@MINREG",
		name: "Minimum registers",
		example: "@MINREG",
		operands: [],
		description: '"Equal to the value of the MINREG header"',
	},
	{
		symbol: "@MINHEAP",
		name: "Minimum heap",
		example: "@MINHEAP",
		operands: [],
		description: '"Equal to the value of the MINHEAP header"',
	},
	{
		symbol: "@MINSTACK",
		name: "Minimum stack",
		example: "@MINSTACK",
		operands: [],
		description: '"Equal to the value of the MINSTACK header"',
	},
	{
		symbol: "@HEAP",
		name: "Heap",
		example: "@HEAP",
		operands: [],
		description: '"Equal to the maximum size of the heap"\n"Where the stack is empty, and the heap occupies all available space in the RAM"\n"Note this is specific to the target CPU instead of the URCL program"',
	},
	{
		symbol: "@MSB",
		name: "Most significant bit",
		example: "@MSB",
		operands: [],
		description: '"Equal to a binary value with only the most significant bit active"\n"128 in an 8 bit program"',
	},
	{
		symbol: "@SMSB",
		name: "Signed most significant bit",
		example: "@SMSB",
		operands: [],
		description: '"Equal to a binary value with only the second most significant bit active"\n"64 in an 8 bit program"',
	},
	{
		symbol: "@MAX",
		name: "Maximum",
		example: "@MAX",
		operands: [],
		description: '"Equal to a binary value with all bits active"\n"255 in an 8 bit program"',
	},
	{
		symbol: "@SMAX",
		name: "Signed maximum",
		example: "@SMAX",
		operands: [],
		description: '"Equal to a binary value with all bits active except the most significant bit"\n"127 in an 8 bit program"',
	},
	{
		symbol: "@UHALF",
		name: "Upper half",
		example: "@UHALF",
		operands: [],
		description: '"Equal to a binary value with all bits greater than or equal to 2^(BITS/2) active"\n"240 in an 8 bit program"',
	},
	{
		symbol: "@LHALF",
		name: "Lower half",
		example: "@LHALF",
		operands: [],
		description: '"Equal to a binary value with all bits less than 2^(BITS/2) active"\n"15 in an 8 bit program"',
	},
	//	INSTRUCTIONS
	{
		symbol: "ADD",
		name: "Add",
		example: "ADD R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Adds two values together, then it stores the result in a register."',
	},
	{
		symbol: "AND",
		name: "Bitwise AND",
		example: "AND R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Does a bitwise AND of two values, then it stores the result in a register."',
	},
	{
		symbol: "BEV",
		name: "Branch if even",
		example: "BEV .foo R2",
		operands: [["Relative", "Label", "Register", "Macro"], ["Register", "Macro"]],
		description: '"Branches to a specified address if a value is even."',
	},
	{
		symbol: "BGE",
		name: "Branch if greater than or equal to",
		example: "BGE .foo R2 R3",
		operands: [["Relative", "Label", "Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Branches to a specified address if one value is greater than or equal to another value."',
	},
	{
		symbol: "BLE",
		name: "Branch if less than or equal to",
		example: "BLE .foo R2 R3",
		operands: [["Relative", "Label", "Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Branches to a specified address if one value is less than or equal to another value."',
	},
	{
		symbol: "BNC",
		name: "Branch if no carry",
		example: "BNC .foo R2 R3",
		operands: [["Relative", "Label", "Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Branches to a specified address if one value added to another value does not activate the carryflag."',
	},
	{
		symbol: "BNE",
		name: "Branch if not equal to",
		example: "BNE .foo R2 R3",
		operands: [["Relative", "Label", "Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Branches to a specified address if one value is equal to another value."',
	},
	{
		symbol: "BNZ",
		name: "Branch if not zero",
		example: "BNZ .foo R2",
		operands: [["Relative", "Label", "Register", "Macro"], ["Register", "Macro"]],
		description: '"Branches to a specified address if a value is equal to zero."',
	},
	{
		symbol: "BOD",
		name: "Branch if odd",
		example: "BOD .foo R2",
		operands: [["Relative", "Label", "Register", "Macro"], ["Register", "Macro"]],
		description: '"Branches to a specified address if a value is odd."',
	},
	{
		symbol: "BRC",
		name: "Branch if carry",
		example: "BRC .foo R2 R3",
		operands: [["Relative", "Label", "Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Branches to a specified address if one value added to another value activates the carry flag."',
	},
	{
		symbol: "BRE",
		name: "Branch if equal to",
		example: "BRE .foo R2 R3",
		operands: [["Relative", "Label", "Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Branches to a specified address if one value is equal to another value."',
	},
	{
		symbol: "BRG",
		name: "Branch if greater than",
		example: "BRG .foo R2 R3",
		operands: [["Relative", "Label", "Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Branches to a specified address if one value is less than another value."',
	},
	{
		symbol: "BRL",
		name: "Branch if less than",
		example: "BRL .foo R2 R3",
		operands: [["Relative", "Label", "Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Branches to a specified address if one value is less than another value."',
	},
	{
		symbol: "BRN",
		name: "Branch if negative",
		example: "BRN .foo R2",
		operands: [["Relative", "Label", "Register", "Macro"], ["Register", "Macro"]],
		description: '"Branches to a specified address if a value is negative."',
	},
	{
		symbol: "BRP",
		name: "Branch if positive",
		example: "BRP .foo R2",
		operands: [["Relative", "Label", "Register", "Macro"], ["Register", "Macro"]],
		description: '"Branches to a specified address if a value is positive or zero."',
	},
	{
		symbol: "BRZ",
		name: "Branch if zero",
		example: "BRZ .foo R2",
		operands: [["Relative", "Label", "Register", "Macro"], ["Register", "Macro"]],
		description: '"Branches to a specified address if a value is equal to zero."',
	},
	{
		symbol: "BSL",
		name: "Barrel shift left",
		example: "BSL R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Does a specific number of bitwise left shifts of a value, then it stores the result in a register."',
	},
	{
		symbol: "BSR",
		name: "Barrel shift right",
		example: "BSR R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Does a specific number of bitwise right shifts of a value, then it stores the result in a register."',
	},
	{
		symbol: "BSS",
		name: "Barrel shift right signed",
		example: "BSS R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Does a specific number of signed right shifts of a value, then it stores the result in a register."',
	},
	{
		symbol: "CAL",
		name: "Call",
		example: "CAL .test",
		operands: [["Relative", "Label", "Register", "Macro"]],
		description: '"Pushes the address of the next instruction onto the stack then it branches to a specific address."',
	},
	{
		symbol: "CPY",
		name: "Copy",
		example: "CPY M1 M2",
		operands: [["Memory", "Label", "Register", "Macro"], ["Memory", "Label", "Register", "Macro"]],
		description: '"Copies a value from the RAM at a specified address into another RAM location at another specifiedaddress."',
	},
	{
		symbol: "DEC",
		name: "Decrement",
		example: "DEC R1 R2",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Subtracts 1 from a value then stores the result into a register."',
	},
	{
		symbol: "DIV",
		name: "Division",
		example: "DIV R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Divides one value by another, then it stores the result in a register."',
	},
	{
		symbol: "HLT",
		name: "Halt",
		example: "HLT",
		operands: [],
		description: '"Halts execution."',
	},
	{
		symbol: "IMM",
		name: "Immediate",
		example: "IMM R1 6",
		operands: [["Register", "Macro"], ["Immediate", "Label", "Macro"]],
		description: '"Copies an immediate value into a register."',
	},
	{
		symbol: "IN",
		name: "In",
		example: "IN R1 %RNG",
		operands: [["Register", "Macro"], ["Port", "Macro"]],
		description: '"Reads the value on a particular port and writes it into a register."',
	},
	{
		symbol: "INC",
		name: "Increment",
		example: "INC R1 R2",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Adds 1 to a value then stores the result into a register."',
	},
	{
		symbol: "JMP",
		name: "Jump",
		example: "JMP 5",
		operands: [["Relative", "Label", "Register", "Macro"]],
		description: '"Branches to a specified value."',
	},
	{
		symbol: "LLOD",
		name: "List load",
		example: "LLOD R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Memory", "Macro"], ["Immediate", "Label", "Register", "Macro"]],
		description: '"Copies a value from the RAM at a specified address + offset into a register."',
	},
	{
		symbol: "LOD",
		name: "Load",
		example: "LOD R1 M2",
		operands: [["Register", "PC", "Macro"], ["Memory", "Register", "Macro"]],
		description: '"Copies a value from the RAM at a specified address into a register."',
	},
	{
		symbol: "LSH",
		name: "Left shift",
		example: "LSH R1 R2",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Does a bitwise left shift of a value, then it stores the result in a register."',
	},
	{
		symbol: "LSTR",
		name: "List store",
		example: "LSTR R1 R2 R3",
		operands: [["Memory", "Register", "Macro"], ["Immediate", "Label", "Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Writes a value into the RAM at a specified address + offset."',
	},
	{
		symbol: "MLT",
		name: "Multiply",
		example: "MLT R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Multiplies two values together, then it stores the result in a register."',
	},
	{
		symbol: "MOD",
		name: "Modulus",
		example: "MOD R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Calculates the remainder left after one value is divided by another, then it stores the result in aregister."',
	},
	{
		symbol: "MOV",
		name: "Move",
		example: "MOV R1 R2",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Copies a value into a register."',
	},
	{
		symbol: "NAND",
		name: "Bitwise NAND",
		example: "NAND R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Does a bitwise NAND of two values, then it stores the result in a register."',
	},
	{
		symbol: "NEG",
		name: "Negate",
		example: "NEG R1 R2",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Calculates the negation of the value, interpreted as 2\'s compliment, then stores the result into aregister."',
	},
	{
		symbol: "NOP",
		name: "No operation",
		example: "NOP",
		operands: [],
		description: '"Does nothing."',
	},
	{
		symbol: "NOR",
		name: "Bitwise NOR",
		example: "NOR R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Does a bitwise NOR of two values, then it stores the result in a register."',
	},
	{
		symbol: "NOT",
		name: "Bitwise NOT",
		example: "NOT R1 R2",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Does a bitwise NOT of a value, then it stores the result in a register."',
	},
	{
		symbol: "OR",
		name: "Bitwise OR",
		example: "OR R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Does a bitwise OR of two values, then it stores the result in a register."',
	},
	{
		symbol: "OUT",
		name: "Out",
		example: "OUT %RNG R1",
		operands: [["Port", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Reads a value and outputs the result into a specific port."',
	},
	{
		symbol: "POP",
		name: "Pop",
		example: "POP R1",
		operands: [["Register", "Macro"]],
		description: '"Pops a value from the stack into a register."',
	},
	{
		symbol: "PSH",
		name: "Push",
		example: "PSH R1",
		operands: [["Register", "Immediate", "Label", "Macro"]],
		description: '"Pushes a value onto the stack."',
	},
	{
		symbol: "RET",
		name: "Return",
		example: "RET",
		operands: [],
		description: '"Pops a value from the stack then it branches to that value."',
	},
	{
		symbol: "RSH",
		name: "Right shift",
		example: "RSH R1 R2",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Does a bitwise right shift of a value, then it stores the result in a register."',
	},
	{
		symbol: "SETC",
		name: "Set if carry",
		example: "SETC R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Sets a register to all 1\'s in binary if one value added to another value activates the carry flag, otherwise it sets that register to 0."',
	},
	{
		symbol: "SETE",
		name: "Set if equal to",
		example: "SETE R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Sets a register to all 1\'s in binary if one value is equal to another value, otherwise it sets thatregister to 0."',
	},
	{
		symbol: "SETG",
		name: "Set if greater than",
		example: "SETG R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Sets a register to all 1\'s in binary if one value is greater than another value, otherwise it sets that register to 0."',
	},
	{
		symbol: "SETGE",
		name: "Set if greater than or equal to",
		example: "SETGE R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Sets a register to all 1\'s in binary if one value is greater than another value, otherwise it sets that register to 0."',
	},
	{
		symbol: "SETL",
		name: "Set if less than",
		example: "SETL R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Sets a register to all 1\'s in binary if one value is less than another value, otherwise it sets thatregister to 0."',
	},
	{
		symbol: "SETLE",
		name: "Set if less than or equal to",
		example: "SETLE R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Sets a register to all 1\'s in binary if one value is greater than another value, otherwise it sets thatregister to 0."',
	},
	{
		symbol: "SETNC",
		name: "Set if no carry",
		example: "SETNC R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Sets a register to all 1\'s in binary if one value added to another value does not activate the carryflag, otherwise it sets that register to 0."',
	},
	{
		symbol: "SETNE",
		name: "Set if not equal to",
		example: "SETNE R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Sets a register to all 1\'s in binary if one value is not equal to another value, otherwise it sets thatregister to 0."',
	},
	{
		symbol: "SRS",
		name: "Signed right shift",
		example: "SRS R1 R2",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Does a signed right shift of a value, then it stores the result in a register."',
	},
	{
		symbol: "STR",
		name: "Store",
		example: "STR M2 R1",
		operands: [["Memory", "Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Copies a value into the RAM at a specified address."',
	},
	{
		symbol: "SUB",
		name: "Subtract",
		example: "SUB R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Subtracts one values from another, then it stores the result in a register."',
	},
	{
		symbol: "XNOR",
		name: "Bitwise XNOR",
		example: "XNOR R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Does a bitwise XNOR of two values, then it stores the result in a register."',
	},
	{
		symbol: "XOR",
		name: "Bitwise XOR",
		example: "XOR R1 R2 R3",
		operands: [["Register", "Macro"], ["Register", "Macro"], ["Register", "Immediate", "Label", "Macro"]],
		description: '"Does a bitwise XOR of two values, then it stores the result in a register."',
	},
]


function insertChars(string, index, length, char) {
	const chars = new Array(length + 1).join(char)
	return string.substring(0, index) + chars + string.substring(index + length)
}


// replaces // line-comments and /* block-comments */ with spaces
// while taking "strings" and 'chars' into account
function sanitizeText(text, option) {
	let match = []
	let matchBlockComment = []
	// const regex = /(\/\/.*?$)|(\/\*.*?\*\/)|("[^"]*"|'[^']*')/gms	// s modifier allows . to match newlines \r\n
	const regex = /(\/\/.*?$)|(\/\*.*?\*\/)|(".*?"|'.*?')/gms	// s modifier allows . to match newlines \r\n
	const regexBlockComment = /.+/g	// . cannot match newlines
	
	while (match = regex.exec(text))
		if (match[1])	// remove //line comments
			text = insertChars(text, match.index, match[0].length, ' ')
		else if (match[2])	// remove /*block comments*/
			while (matchBlockComment = regexBlockComment.exec(match[2]))	// does not remove \n newlines
				text = insertChars(text, match.index + matchBlockComment.index, matchBlockComment[0].length, ' ')
		else if (option)	// remove "strings" and 'chars'
			text = insertChars(text, match.index + 1, match[0].length - 2, '_')

	// vscode.window.showInformationMessage(text)
	return text
}


function tokenizeDoc(document) {
	const text = document.getText()
	let tokens = []
	let match = []
	let regex = new RegExp([
		/(?<comment_line>\/\/.*$)/,
		/(?<comment_block>\/\*[\S\s]*?\*\/)/,	// match everything including newlines \r\n
		/(?<string>"[^"\r\n]*")/,
		/(?<char>'[^'\r\n]*')/,
		/(?<=^\s*)(?<instruction>ADD|AND|BEV|BGE|BLE|BNC|BNE|BNZ|BOD|BRC|BRE|BRG|BRL|BRN|BRP|BRZ|BSL|BSR|BSS|CAL|CPY|DEC|DIV|HLT|IMM|IN|INC|JMP|LLOD|LOD|LSH|LSTR|MLT|MOD|MOV|NAND|NEG|NOP|NOR|NOT|OR|OUT|POP|PSH|RET|RSH|SETC|SETE|SETG|SETGE|SETL|SETLE|SETNC|SETNE|SRS|STR|SUB|XNOR|XOR)/,
		/(?<=^\s*)(?<header>BITS|RUN|MINREG|MINHEAP|MINSTACK)/,
		/(?<=^\s*)(?<label_define>\.\w*)/,
		/(?<label>\.\w*)/,
		/(?<=^\s*)(?<define>@DEFINE)/,
		/(?<macro>@\w*)/,
		/(?<register>[R$]\d*)/,
		/(?<numeric>~?[-+]?\d\w*)/,
		/(?<memory>[#M]\d*)/,
		/(?<=^\s*)(?<instruction_unknown>\w+)/,
		/(?<port>%\w*)/,
		/(?<condiational>[=<>]=?)/,
		/(?<square_brackets>\[[^\]\r\n]*\])/,
		/(?<semi_colon>;)/,
		/(?<comma>,)/,
		/(?<word>\w+)/,
		/(?<invalid>(?!\/[\/\*])\S(?:(?!\/[/*])[^\s\w\[\]"'@#%$;,*=<>.+-])*)/,
		/(?<unknown>\S)/,
	].map(function (r) { return r.source }).join('|'), 'dgim');
		// 'd' enables `indices`; which allows extracting which named capture group matched the input
		// 'g' enables global; which is required for how Im using `.exec()`
		// 'i' enables case-insensitive `minheap` == `mINhEap` == `MINHEAP`
		// 'm' enables multiline mode; allowing `^` to match the start of a line and `$` to match the end of a line
		// ~~'s' enables the dot `.` to match new lines \r\n~~		// used `\r?\n` instead

	// vscode.window.showInformationMessage(regex.toString())
	while (match = regex.exec(text)) {
		const captureGroups = Object.entries(match.indices.groups)
		// find the name and matched text of the first (and only) matching capture group
		for (var index = 0; index < captureGroups.length; index++)
			if (captureGroups[index][1] != null)
				break
		// vscode.window.showInformationMessage(captureGroups[index][0])
		const name = captureGroups[index][0]
		const positionStart = document.positionAt(match.index)
		const positionEnd = document.positionAt(match.index + match[0].length)
		const range = new vscode.Range(positionStart, positionEnd)
		const token = { name: name, symbol: match[0], range: range }
		// vscode.window.showInformationMessage(JSON.stringify(token))
		tokens.push(token)
	}
	
	// vscode.window.showInformationMessage(JSON.stringify(tokens))
	return tokens
}


function getLabels(document, option) {
	let labels = []
	const tokens = tokenizeDoc(document)
	let token
	
	// option:0 all .labels
	// option:1 only reference .labels
	// option:2 only definition .labels
	while (token = tokens.pop())
		if ((option ^ 2 && token.name == 'label') || (option ^ 1 && token.name == 'label_define'))
			labels.push({ document: document, range: token.range, symbol: token.symbol })


	// vscode.window.showInformationMessage(JSON.stringify(labels))
	return labels
}

const HoverProvider = {
	provideHover(document, position, token) {
		const range = document.getWordRangeAtPosition(position)	//`Word` is defined by "wordPattern" in `urcl.language-configuration.json`
		let hoverWord = document.getText(range);
		var markdownString = new vscode.MarkdownString();
		
		const HoverWordObject = HoverWords.find(o => o.symbol === hoverWord.toUpperCase())
		if (HoverWordObject) {
			const operands = HoverWordObject.operands.length
			markdownString.appendCodeblock(HoverWordObject.example, '.urcl')
			markdownString.appendCodeblock(HoverWordObject.name + (operands ? ': ' + operands + ' Opperand' + (operands > 1 ? 's' : '') : ''), 'plaintext')
			markdownString.appendCodeblock(HoverWordObject.description, '.simple.urcl')
			
			// vscode.window.showInformationMessage(JSON.stringify(HoverWordObject))
			return { contents: [markdownString], range: range }
		}


		// var hoveredWord = document.getText(document.getWordRangeAtPosition(position));	//`Word` is defined by "wordPattern" in `urcl.language-configuration.json`
		var numericBase;
		var regexHex = /^(~?[+-])?0x[\dA-F]+$/i;
		var regexDec = /^(~?[+-])?\d+$/;
		var regexOct = /^(~?[+-])?0o[0-7]+$/i;
		var regexBin = /^(~?[+-])?0b[01]+$/i;
		var regexChar = /^'(\\u[\dA-F]{4}|\\?.)'+$/i;
		
		// test if the selected word is a number and assign a numeric base
		if ((regexChar.test(hoverWord.toString()))) numericBase = 128; //128 could be any number
		else if ((regexHex.test(hoverWord.toString()))) numericBase = 16;
		else if ((regexDec.test(hoverWord.toString()))) numericBase = 10;
		else if ((regexOct.test(hoverWord.toString()))) numericBase = 8;
		else if ((regexBin.test(hoverWord.toString()))) numericBase = 2;
		
		if (numericBase) {
			var numeric;
			hoverWord = hoverWord.replace(/^~[+-]?|^0[box]/, ''); //remove prefixes

			if (numericBase == 128)
			{
				if (hoverWord.charCodeAt(1) == 92)
					switch (hoverWord.charAt(2)) {
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
							numeric = parseInt(hoverWord.replace(/^'\\u|'$/, ''), 16);
							numericBase = 0xFFFF;
							break;
						default:
							numeric = hoverWord.charCodeAt(3);
							break;
					}
				else
					numeric = hoverWord.charCodeAt(1);
			}
			else
				numeric = parseInt(hoverWord, numericBase);
			
			let string = '';
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
		const labels = getLabels(document, 2)
		// vscode.window.showInformationMessage(JSON.stringify(labels))
		return labels

		// tokenizeDoc(document)

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
		// if (i == 0) {
		// 	while (label = codeLens.pop()) {
		// 		if (label.symbol == symbol) {
		// 			const location = new vscode.Location(document.uri, label.range)
		// 			locations.push(location)
		// 			i++
		// 		}
		// 	}
		// 	if (i == 1)
		// 		locations.pop()
		// }
		
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
		const range = document.getWordRangeAtPosition(position);	//`Word` is defined by "wordPattern" in `urcl.language-configuration.json`
		const hoveredWord = document.getText(range);
		const regexlabel = new RegExp(/^\.\w+$/m); // .label
		if (regexlabel.test(hoveredWord)) {	// test if selected word is a .label
			const tokens = tokenizeDoc(document)
			let locations = []
			
			while (token = tokens.pop())
				if (token.name.startsWith('label'))
					if (token.symbol == hoveredWord)
						locations.push(new vscode.Location(document.uri, token.range))
			
			if (!locations)
				locations.push(new vscode.Location(document.uri, range))

			return locations;
		}
	}
}


const DefinitionProvider = {
	provideDefinition(document, position, token) {
		const range = document.getWordRangeAtPosition(position);	//`Word` is defined by "wordPattern" in `urcl.language-configuration.json`
		const hoveredWord = document.getText(range);
		const regexlabel = new RegExp(/^\.\w+$/m); // .label
		
		if (regexlabel.test(hoveredWord)) {	// test if selected word is a .label
			let labels = getLabels(document, 2)	// get a list of all labels in doc
			let label
			let locations = []
			
			while (label = labels.pop())
				if (hoveredWord == label.symbol)	// test if .label in doc is same as selected .label
					locations.push(new vscode.Location(document.uri, label.range))
			
			if (!locations)
				locations.push(new vscode.Location(document.uri, range))

			return locations;
		}
	}
}


// const decorationType = vscode.window.createTextEditorDecorationType({
// 	// backgroundColor: 'green',
// 	// border: '2px solid white'
// 	after: {
// 		margin: "0 0 0 3em",
// 		textDecoration: "none"
// 	},
// 	rangeBehavior: vscode.DecorationRangeBehavior.ClosedOpen,
	
// })
// function decorate(editor) {
// 	let sourceCode = editor.document.getText()
// 	let regex = /(mov.*)/i

// 	let decorationsArray = []

// 	const sourceCodeArr = sourceCode.split('\n')

// 	for (let line = 0; line < sourceCodeArr.length; line++) {
// 		let match = sourceCodeArr[line].match(regex)

// 		if (match !== null && match.index !== undefined) {
// 			// vscode.window.showInformationMessage(JSON.stringify(match[0].length));
// 			let range = new vscode.Range(
// 				new vscode.Position(line, match.index + 0),
// 				new vscode.Position(line, match.index + (match[0].length > 50 ? match[0].length : 50))
// 			)
// 			let decoration = {
// 				renderOptions: {
// 					after: {
// 						"color": {
// 							"id": "sideDecorationForeground"
// 						},
// 						"contentText": "R1 = .label  // ERROR: .label underfined", // hard coded, don't tell anyone
// 					}
// 				},
// 				range: range
// 			}

// 			decorationsArray.push(decoration)
// 		}
// 	}
	
// 	editor.setDecorations(decorationType, decorationsArray)
// }

const RenameProvider = {

	provideRenameEdits(document, position, newName, token) {
		const workspaceEdit = new vscode.WorkspaceEdit()
		const tokens = tokenizeDoc(document)
		const oldName = getTokenAtPostion(position, tokens)
		
		for (const { name, symbol, range } of tokens)
			// vscode.window.showInformationMessage(JSON.stringify(oldName))
			if (symbol == oldName.symbol)
				// if (name == oldName.name)
					workspaceEdit.replace(document.uri, range, newName)
				

		// vscode.window.showInformationMessage(JSON.stringify(workspaceEdit))
		return workspaceEdit
	},
	prepareRename(document, position, token) {
		if (token.isCancellationRequested)
			return;
		const tokens = tokenizeDoc(document)
		const oldName = getTokenAtPostion(position, tokens)
		return oldName.range
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
	context.subscriptions.push(vscode.languages.registerRenameProvider(fileSelector, RenameProvider)); // rename related symbols
	context.subscriptions.push(vscode.languages.registerCodeLensProvider(fileSelector, CodelensProvider)); // overhead .label references
	context.subscriptions.push(vscode.languages.registerReferenceProvider(fileSelector, ReferenceProvider)); // shift+F12 .label locations
	context.subscriptions.push(vscode.languages.registerDefinitionProvider(fileSelector, DefinitionProvider)); // ctrl+click .label definition

	// vscode.workspace.onDidChangeTextDocument(event => {
	// 	const openEditor = vscode.window.visibleTextEditors.filter(
	// 		editor => editor.document.uri === event.document.uri
	// 	)[0];
	// 	decorate(openEditor);
	// })

	// vscode.window.showInformationMessage(JSON.stringify(context));
}


exports.activate = activate;
function deactivate() { }
exports.deactivate = deactivate;