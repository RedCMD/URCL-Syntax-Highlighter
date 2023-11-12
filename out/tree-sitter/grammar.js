module.exports = grammar({
	name: "URCL",
	extras: $ => [$.comment, $._whitespace],

	rules: {
		source_file: $ => seq(
			optional($._newline),
			repeat(seq(choice(
				field("header", $._header),
				field("define_word", $.DW),
				field("inst", $.instruction),
			), $._newline)),
			optional(choice(
				field("header", $._header),
				field("define_word", $.DW),
				field("inst", $.instruction),
			))
		),
		macro: $ => /@\w+/,
		_whitespace: $ => /[\t\f\v \u00a0\u1680\u2000-\u200a\u2028\u2029\u202f\u205f\u3000\ufeff]+/, // /\s/ without \r\n
		_newline: $ => repeat1(seq(optional(alias($.single_comment, $.comment)), /[\r\n]/)),
		single_comment: $ => token(seq("//", /[^\r\n]*/)),
		comment: $ => token(seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/")),
		_header: $ => choice(
			$.BITS,
			$.MINREG,
			$.MINHEAP,
			$.MINSTACK,
			$.RUN,
		),
		BITS: $ => seq(
			"BITS",
			optional(field("comparison", choice("<=", "==", ">="))),
			field("value", $._immediate_literal)
		),
		MINREG: $ => seq("MINREG", field("value", $._immediate_literal)),
		MINHEAP: $ => seq("MINHEAP", field("value", $._immediate_literal)),
		MINSTACK: $ => seq("MINSTACK", field("value", $._immediate_literal)),
		RUN: $ => seq(
			field("header_type", "RUN"),
			field("value", choice("RAM", "ROM")),
		),
		DW: $ => seq(repeat(seq(field("label", $.label), $._newline)), "DW", field("value", $._dw_literal)),
		label: $ => seq(".", field("name", $.identifier)),
		_operand: $ => choice(
			$._immediate_literal,
			$.register,
			$.program_counter,
			$.stack_pointer,
		),
		register: $ => /[$Rr](([1-9]0*)+|0)/,
		memory: $ => /[#Mm](([1-9]0*)+|0)/,
		program_counter: $ => "PC",
		stack_pointer: $ => "SP",
		placeholder: $ => seq("<", $.identifier, ">"),
		identifier: $ => /\w+/,
		_dw_literal: $ => choice($._immediate_literal, $.array, $.string),
		array: $ => seq("[", choice($._newline, field("item", repeat($._dw_literal))), "]"),

		// string from C# grammar, allow its escape sequences because why not
		string: $ => seq(
			'"',
			repeat(field("content", choice(
				$.string_segment,
				$.escape_sequence,
			))),
			'"'
		),
		char: $ => seq(
			"'",
			field("content", choice($.char_value, $.escape_sequence)),
			"'"
		),
		string_segment: $ => token.immediate(/[^\\"\n]+/),
		char_value: $ => token.immediate(/[^'\\]/),
		escape_sequence: $ => choice(
			seq(token.immediate("\\x"), field("value", $.hex_escape)),
			seq(token.immediate("\\u"), field("value", alias($.unicode_escape_short, $.unicode_escape))),
			seq(token.immediate("\\u{"), field("value", $.unicode_escape), token.immediate("}")),
			seq(token.immediate("\\U"), field("value", alias($.unicode_escape_long, $.unicode_escape))),
			seq(token.immediate("\\U{"), field("value", $.unicode_escape), token.immediate("}")),
			seq(token.immediate("\\"), field("value", $.char_escape)),
		),
		hex_escape: $ => token.immediate(/[0-9a-fA-F]{2}/),
		unicode_escape: $ => token.immediate(/[0-9a-fA-F]+/),
		unicode_escape_short: $ => token.immediate(/[0-9a-fA-F]{4}/),
		unicode_escape_long: $ => token.immediate(/[0-9a-fA-F]{8}/),
		char_escape: $ => token.immediate(/[^xuU]/),
		_immediate_literal: $ => choice(
			$.number,
			$.char,
			$.label,
			$.relative,
			$.memory,
			$.macro,
			$.port,
			$.placeholder,
			$.identifier,
		),
		number: $ => token(seq(
			/[+-]?/,
			choice(
				/0b[0-1]+/,
				/0o[0-7]+/,
				/\d+/,
				/0x[A-Fa-f\d]+/,
			),
		)),
		relative: $ => /~[+-]([1-9]0*)+/,
		port: $ => /%\w+/,

		instruction: $ => seq(
			repeat(seq(field("label", $.label), $._newline)),
			field("name", choice($.macro, $.identifier)),
			repeat(field("operand", $._operand)),
		),
	},
});