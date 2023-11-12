#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 104
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 70
#define ALIAS_COUNT 0
#define TOKEN_COUNT 46
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 11
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 34

enum {
  sym_macro = 1,
  sym__whitespace = 2,
  aux_sym__newline_token1 = 3,
  sym_single_comment = 4,
  sym_comment = 5,
  anon_sym_BITS = 6,
  anon_sym_LT_EQ = 7,
  anon_sym_EQ_EQ = 8,
  anon_sym_GT_EQ = 9,
  anon_sym_MINREG = 10,
  anon_sym_MINHEAP = 11,
  anon_sym_MINSTACK = 12,
  anon_sym_RUN = 13,
  anon_sym_RAM = 14,
  anon_sym_ROM = 15,
  anon_sym_DW = 16,
  anon_sym_DOT = 17,
  sym_register = 18,
  sym_memory = 19,
  sym_program_counter = 20,
  sym_stack_pointer = 21,
  anon_sym_LT = 22,
  anon_sym_GT = 23,
  sym_identifier = 24,
  anon_sym_LBRACK = 25,
  anon_sym_RBRACK = 26,
  anon_sym_DQUOTE = 27,
  anon_sym_SQUOTE = 28,
  sym_string_segment = 29,
  sym_char_value = 30,
  anon_sym_BSLASHx = 31,
  anon_sym_BSLASHu = 32,
  anon_sym_BSLASHu_LBRACE = 33,
  anon_sym_RBRACE = 34,
  anon_sym_BSLASHU = 35,
  anon_sym_BSLASHU_LBRACE = 36,
  anon_sym_BSLASH = 37,
  sym_hex_escape = 38,
  sym_unicode_escape = 39,
  sym_unicode_escape_short = 40,
  sym_unicode_escape_long = 41,
  sym_char_escape = 42,
  sym_number = 43,
  sym_relative = 44,
  sym_port = 45,
  sym_source_file = 46,
  aux_sym__newline = 47,
  sym__header = 48,
  sym_BITS = 49,
  sym_MINREG = 50,
  sym_MINHEAP = 51,
  sym_MINSTACK = 52,
  sym_RUN = 53,
  sym_DW = 54,
  sym_label = 55,
  sym__operand = 56,
  sym_placeholder = 57,
  sym__dw_literal = 58,
  sym_array = 59,
  sym_string = 60,
  sym_char = 61,
  sym_escape_sequence = 62,
  sym__immediate_literal = 63,
  sym_instruction = 64,
  aux_sym_source_file_repeat1 = 65,
  aux_sym_DW_repeat1 = 66,
  aux_sym_array_repeat1 = 67,
  aux_sym_string_repeat1 = 68,
  aux_sym_instruction_repeat1 = 69,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_macro] = "macro",
  [sym__whitespace] = "_whitespace",
  [aux_sym__newline_token1] = "_newline_token1",
  [sym_single_comment] = "comment",
  [sym_comment] = "comment",
  [anon_sym_BITS] = "BITS",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_MINREG] = "MINREG",
  [anon_sym_MINHEAP] = "MINHEAP",
  [anon_sym_MINSTACK] = "MINSTACK",
  [anon_sym_RUN] = "RUN",
  [anon_sym_RAM] = "RAM",
  [anon_sym_ROM] = "ROM",
  [anon_sym_DW] = "DW",
  [anon_sym_DOT] = ".",
  [sym_register] = "register",
  [sym_memory] = "memory",
  [sym_program_counter] = "program_counter",
  [sym_stack_pointer] = "stack_pointer",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [sym_identifier] = "identifier",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SQUOTE] = "'",
  [sym_string_segment] = "string_segment",
  [sym_char_value] = "char_value",
  [anon_sym_BSLASHx] = "\\x",
  [anon_sym_BSLASHu] = "\\u",
  [anon_sym_BSLASHu_LBRACE] = "\\u{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_BSLASHU] = "\\U",
  [anon_sym_BSLASHU_LBRACE] = "\\U{",
  [anon_sym_BSLASH] = "\\",
  [sym_hex_escape] = "hex_escape",
  [sym_unicode_escape] = "unicode_escape",
  [sym_unicode_escape_short] = "unicode_escape",
  [sym_unicode_escape_long] = "unicode_escape",
  [sym_char_escape] = "char_escape",
  [sym_number] = "number",
  [sym_relative] = "relative",
  [sym_port] = "port",
  [sym_source_file] = "source_file",
  [aux_sym__newline] = "_newline",
  [sym__header] = "_header",
  [sym_BITS] = "BITS",
  [sym_MINREG] = "MINREG",
  [sym_MINHEAP] = "MINHEAP",
  [sym_MINSTACK] = "MINSTACK",
  [sym_RUN] = "RUN",
  [sym_DW] = "DW",
  [sym_label] = "label",
  [sym__operand] = "_operand",
  [sym_placeholder] = "placeholder",
  [sym__dw_literal] = "_dw_literal",
  [sym_array] = "array",
  [sym_string] = "string",
  [sym_char] = "char",
  [sym_escape_sequence] = "escape_sequence",
  [sym__immediate_literal] = "_immediate_literal",
  [sym_instruction] = "instruction",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_DW_repeat1] = "DW_repeat1",
  [aux_sym_array_repeat1] = "array_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
  [aux_sym_instruction_repeat1] = "instruction_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_macro] = sym_macro,
  [sym__whitespace] = sym__whitespace,
  [aux_sym__newline_token1] = aux_sym__newline_token1,
  [sym_single_comment] = sym_comment,
  [sym_comment] = sym_comment,
  [anon_sym_BITS] = anon_sym_BITS,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_MINREG] = anon_sym_MINREG,
  [anon_sym_MINHEAP] = anon_sym_MINHEAP,
  [anon_sym_MINSTACK] = anon_sym_MINSTACK,
  [anon_sym_RUN] = anon_sym_RUN,
  [anon_sym_RAM] = anon_sym_RAM,
  [anon_sym_ROM] = anon_sym_ROM,
  [anon_sym_DW] = anon_sym_DW,
  [anon_sym_DOT] = anon_sym_DOT,
  [sym_register] = sym_register,
  [sym_memory] = sym_memory,
  [sym_program_counter] = sym_program_counter,
  [sym_stack_pointer] = sym_stack_pointer,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [sym_identifier] = sym_identifier,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [sym_string_segment] = sym_string_segment,
  [sym_char_value] = sym_char_value,
  [anon_sym_BSLASHx] = anon_sym_BSLASHx,
  [anon_sym_BSLASHu] = anon_sym_BSLASHu,
  [anon_sym_BSLASHu_LBRACE] = anon_sym_BSLASHu_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_BSLASHU] = anon_sym_BSLASHU,
  [anon_sym_BSLASHU_LBRACE] = anon_sym_BSLASHU_LBRACE,
  [anon_sym_BSLASH] = anon_sym_BSLASH,
  [sym_hex_escape] = sym_hex_escape,
  [sym_unicode_escape] = sym_unicode_escape,
  [sym_unicode_escape_short] = sym_unicode_escape,
  [sym_unicode_escape_long] = sym_unicode_escape,
  [sym_char_escape] = sym_char_escape,
  [sym_number] = sym_number,
  [sym_relative] = sym_relative,
  [sym_port] = sym_port,
  [sym_source_file] = sym_source_file,
  [aux_sym__newline] = aux_sym__newline,
  [sym__header] = sym__header,
  [sym_BITS] = sym_BITS,
  [sym_MINREG] = sym_MINREG,
  [sym_MINHEAP] = sym_MINHEAP,
  [sym_MINSTACK] = sym_MINSTACK,
  [sym_RUN] = sym_RUN,
  [sym_DW] = sym_DW,
  [sym_label] = sym_label,
  [sym__operand] = sym__operand,
  [sym_placeholder] = sym_placeholder,
  [sym__dw_literal] = sym__dw_literal,
  [sym_array] = sym_array,
  [sym_string] = sym_string,
  [sym_char] = sym_char,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym__immediate_literal] = sym__immediate_literal,
  [sym_instruction] = sym_instruction,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_DW_repeat1] = aux_sym_DW_repeat1,
  [aux_sym_array_repeat1] = aux_sym_array_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
  [aux_sym_instruction_repeat1] = aux_sym_instruction_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_macro] = {
    .visible = true,
    .named = true,
  },
  [sym__whitespace] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__newline_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_single_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_BITS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MINREG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MINHEAP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MINSTACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RUN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RAM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ROM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DW] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [sym_register] = {
    .visible = true,
    .named = true,
  },
  [sym_memory] = {
    .visible = true,
    .named = true,
  },
  [sym_program_counter] = {
    .visible = true,
    .named = true,
  },
  [sym_stack_pointer] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_string_segment] = {
    .visible = true,
    .named = true,
  },
  [sym_char_value] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_BSLASHx] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHu] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHu_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHU] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHU_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [sym_hex_escape] = {
    .visible = true,
    .named = true,
  },
  [sym_unicode_escape] = {
    .visible = true,
    .named = true,
  },
  [sym_unicode_escape_short] = {
    .visible = true,
    .named = true,
  },
  [sym_unicode_escape_long] = {
    .visible = true,
    .named = true,
  },
  [sym_char_escape] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_relative] = {
    .visible = true,
    .named = true,
  },
  [sym_port] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__newline] = {
    .visible = false,
    .named = false,
  },
  [sym__header] = {
    .visible = false,
    .named = true,
  },
  [sym_BITS] = {
    .visible = true,
    .named = true,
  },
  [sym_MINREG] = {
    .visible = true,
    .named = true,
  },
  [sym_MINHEAP] = {
    .visible = true,
    .named = true,
  },
  [sym_MINSTACK] = {
    .visible = true,
    .named = true,
  },
  [sym_RUN] = {
    .visible = true,
    .named = true,
  },
  [sym_DW] = {
    .visible = true,
    .named = true,
  },
  [sym_label] = {
    .visible = true,
    .named = true,
  },
  [sym__operand] = {
    .visible = false,
    .named = true,
  },
  [sym_placeholder] = {
    .visible = true,
    .named = true,
  },
  [sym__dw_literal] = {
    .visible = false,
    .named = true,
  },
  [sym_array] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_char] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym__immediate_literal] = {
    .visible = false,
    .named = true,
  },
  [sym_instruction] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_DW_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_array_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_instruction_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_comparison = 1,
  field_content = 2,
  field_define_word = 3,
  field_header = 4,
  field_header_type = 5,
  field_inst = 6,
  field_item = 7,
  field_label = 8,
  field_name = 9,
  field_operand = 10,
  field_value = 11,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_comparison] = "comparison",
  [field_content] = "content",
  [field_define_word] = "define_word",
  [field_header] = "header",
  [field_header_type] = "header_type",
  [field_inst] = "inst",
  [field_item] = "item",
  [field_label] = "label",
  [field_name] = "name",
  [field_operand] = "operand",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 3},
  [6] = {.index = 7, .length = 1},
  [7] = {.index = 8, .length = 2},
  [8] = {.index = 10, .length = 1},
  [9] = {.index = 11, .length = 2},
  [10] = {.index = 13, .length = 1},
  [11] = {.index = 14, .length = 1},
  [12] = {.index = 15, .length = 1},
  [13] = {.index = 16, .length = 1},
  [14] = {.index = 17, .length = 3},
  [15] = {.index = 20, .length = 1},
  [16] = {.index = 21, .length = 4},
  [17] = {.index = 25, .length = 4},
  [18] = {.index = 29, .length = 4},
  [19] = {.index = 33, .length = 6},
  [20] = {.index = 39, .length = 2},
  [21] = {.index = 41, .length = 2},
  [22] = {.index = 43, .length = 2},
  [23] = {.index = 45, .length = 2},
  [24] = {.index = 47, .length = 1},
  [25] = {.index = 48, .length = 4},
  [26] = {.index = 52, .length = 4},
  [27] = {.index = 56, .length = 4},
  [28] = {.index = 60, .length = 3},
  [29] = {.index = 63, .length = 2},
  [30] = {.index = 65, .length = 1},
  [31] = {.index = 66, .length = 1},
  [32] = {.index = 67, .length = 1},
  [33] = {.index = 68, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 0},
  [1] =
    {field_header, 0},
  [2] =
    {field_define_word, 0},
  [3] =
    {field_inst, 0},
  [4] =
    {field_define_word, 0, .inherited = true},
    {field_header, 0, .inherited = true},
    {field_inst, 0, .inherited = true},
  [7] =
    {field_operand, 0},
  [8] =
    {field_name, 0},
    {field_operand, 1, .inherited = true},
  [10] =
    {field_value, 1},
  [11] =
    {field_header_type, 0},
    {field_value, 1},
  [13] =
    {field_name, 1},
  [14] =
    {field_header, 1},
  [15] =
    {field_define_word, 1},
  [16] =
    {field_inst, 1},
  [17] =
    {field_define_word, 1, .inherited = true},
    {field_header, 1, .inherited = true},
    {field_inst, 1, .inherited = true},
  [20] =
    {field_label, 0},
  [21] =
    {field_define_word, 0, .inherited = true},
    {field_header, 0, .inherited = true},
    {field_header, 1},
    {field_inst, 0, .inherited = true},
  [25] =
    {field_define_word, 0, .inherited = true},
    {field_define_word, 1},
    {field_header, 0, .inherited = true},
    {field_inst, 0, .inherited = true},
  [29] =
    {field_define_word, 0, .inherited = true},
    {field_header, 0, .inherited = true},
    {field_inst, 0, .inherited = true},
    {field_inst, 1},
  [33] =
    {field_define_word, 0, .inherited = true},
    {field_define_word, 1, .inherited = true},
    {field_header, 0, .inherited = true},
    {field_header, 1, .inherited = true},
    {field_inst, 0, .inherited = true},
    {field_inst, 1, .inherited = true},
  [39] =
    {field_label, 0, .inherited = true},
    {field_name, 1},
  [41] =
    {field_label, 0, .inherited = true},
    {field_label, 1, .inherited = true},
  [43] =
    {field_operand, 0, .inherited = true},
    {field_operand, 1, .inherited = true},
  [45] =
    {field_comparison, 1},
    {field_value, 2},
  [47] =
    {field_content, 0},
  [48] =
    {field_define_word, 1, .inherited = true},
    {field_header, 1, .inherited = true},
    {field_header, 2},
    {field_inst, 1, .inherited = true},
  [52] =
    {field_define_word, 1, .inherited = true},
    {field_define_word, 2},
    {field_header, 1, .inherited = true},
    {field_inst, 1, .inherited = true},
  [56] =
    {field_define_word, 1, .inherited = true},
    {field_header, 1, .inherited = true},
    {field_inst, 1, .inherited = true},
    {field_inst, 2},
  [60] =
    {field_label, 0, .inherited = true},
    {field_name, 1},
    {field_operand, 2, .inherited = true},
  [63] =
    {field_label, 0, .inherited = true},
    {field_value, 2},
  [65] =
    {field_content, 1},
  [66] =
    {field_item, 1},
  [67] =
    {field_content, 1, .inherited = true},
  [68] =
    {field_content, 0, .inherited = true},
    {field_content, 1, .inherited = true},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static inline bool sym_string_segment_character_set_1(int32_t c) {
  return (c < 8192
    ? (c < ' '
      ? (c < 11
        ? c == '\t'
        : c <= '\f')
      : (c <= ' ' || (c < 5760
        ? c == 160
        : c <= 5760)))
    : (c <= 8202 || (c < 8287
      ? (c < 8239
        ? (c >= 8232 && c <= 8233)
        : c <= 8239)
      : (c <= 8287 || (c < 65279
        ? c == 12288
        : c <= 65279)))));
}

static inline bool sym_char_value_character_set_1(int32_t c) {
  return (c < 8232
    ? (c < 160
      ? (c < ' '
        ? (c >= '\t' && c <= '\f')
        : c <= ' ')
      : (c <= 160 || (c < 8192
        ? c == 5760
        : c <= 8202)))
    : (c <= 8233 || (c < 12288
      ? (c < 8287
        ? c == 8239
        : c <= 8287)
      : (c <= 12288 || c == 65279))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(43);
      if (lookahead == '"') ADVANCE(104);
      if (lookahead == '\'') ADVANCE(105);
      if (lookahead == '.') ADVANCE(60);
      if (lookahead == '/') ADVANCE(112);
      if (lookahead == '<') ADVANCE(71);
      if (lookahead == '>') ADVANCE(73);
      if (lookahead == '[') ADVANCE(102);
      if (lookahead == '\\') ADVANCE(120);
      if (lookahead == ']') ADVANCE(103);
      if (lookahead == '}') ADVANCE(117);
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(111);
      if (lookahead == 'U' ||
          lookahead == 'u' ||
          lookahead == 'x') ADVANCE(111);
      if (sym_char_value_character_set_1(lookahead)) ADVANCE(113);
      if (lookahead != 0) ADVANCE(111);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(104);
      if (lookahead == '/') ADVANCE(106);
      if (lookahead == '\\') ADVANCE(121);
      if (sym_string_segment_character_set_1(lookahead)) ADVANCE(109);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(110);
      END_STATE();
    case 2:
      if (lookahead == '*') ADVANCE(5);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(5);
      if (lookahead == '/') ADVANCE(47);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '/') ADVANCE(48);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(4);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '.') ADVANCE(60);
      if (lookahead == '/') ADVANCE(3);
      if (lookahead == '@') ADVANCE(38);
      if (lookahead == 'D') ADVANCE(95);
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(46);
      if (sym_char_value_character_set_1(lookahead)) ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 7:
      if (lookahead == '/') ADVANCE(112);
      if (lookahead == '\\') ADVANCE(121);
      if (sym_string_segment_character_set_1(lookahead)) ADVANCE(113);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(111);
      END_STATE();
    case 8:
      if (lookahead == '/') ADVANCE(2);
      if (lookahead == 'R') ADVANCE(19);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(27);
      if (sym_string_segment_character_set_1(lookahead)) ADVANCE(45);
      END_STATE();
    case 9:
      if (lookahead == '/') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(123);
      if (sym_string_segment_character_set_1(lookahead)) ADVANCE(45);
      END_STATE();
    case 10:
      if (lookahead == '/') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      if (sym_string_segment_character_set_1(lookahead)) ADVANCE(45);
      END_STATE();
    case 11:
      if (lookahead == '/') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(37);
      if (sym_string_segment_character_set_1(lookahead)) ADVANCE(45);
      END_STATE();
    case 12:
      if (lookahead == '/') ADVANCE(2);
      if (sym_string_segment_character_set_1(lookahead)) ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 13:
      if (lookahead == '/') ADVANCE(127);
      if (sym_string_segment_character_set_1(lookahead)) ADVANCE(128);
      if (lookahead != 0 &&
          lookahead != 'U' &&
          lookahead != 'u' &&
          lookahead != 'x') ADVANCE(126);
      END_STATE();
    case 14:
      if (lookahead == '0') ADVANCE(65);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(66);
      END_STATE();
    case 15:
      if (lookahead == '0') ADVANCE(129);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(132);
      END_STATE();
    case 16:
      if (lookahead == '0') ADVANCE(61);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(62);
      END_STATE();
    case 17:
      if (lookahead == '=') ADVANCE(51);
      END_STATE();
    case 18:
      if (lookahead == '=') ADVANCE(52);
      END_STATE();
    case 19:
      if (lookahead == 'A') ADVANCE(20);
      if (lookahead == 'O') ADVANCE(21);
      END_STATE();
    case 20:
      if (lookahead == 'M') ADVANCE(57);
      END_STATE();
    case 21:
      if (lookahead == 'M') ADVANCE(58);
      END_STATE();
    case 22:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(25);
      END_STATE();
    case 23:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(130);
      END_STATE();
    case 24:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(131);
      END_STATE();
    case 25:
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(134);
      END_STATE();
    case 26:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(133);
      END_STATE();
    case 27:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(122);
      END_STATE();
    case 28:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(124);
      END_STATE();
    case 29:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(125);
      END_STATE();
    case 30:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(28);
      END_STATE();
    case 31:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(29);
      END_STATE();
    case 32:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(30);
      END_STATE();
    case 33:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(31);
      END_STATE();
    case 34:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 35:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(34);
      END_STATE();
    case 36:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(35);
      END_STATE();
    case 37:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(36);
      END_STATE();
    case 38:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 39:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(135);
      END_STATE();
    case 40:
      if (eof) ADVANCE(43);
      if (lookahead == '"') ADVANCE(104);
      if (lookahead == '#') ADVANCE(14);
      if (lookahead == '%') ADVANCE(39);
      if (lookahead == '\'') ADVANCE(105);
      if (lookahead == '.') ADVANCE(60);
      if (lookahead == '/') ADVANCE(3);
      if (lookahead == '0') ADVANCE(96);
      if (lookahead == '<') ADVANCE(72);
      if (lookahead == '=') ADVANCE(17);
      if (lookahead == '>') ADVANCE(18);
      if (lookahead == '@') ADVANCE(38);
      if (lookahead == '[') ADVANCE(102);
      if (lookahead == ']') ADVANCE(103);
      if (lookahead == '~') ADVANCE(22);
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(46);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(15);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(74);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(99);
      if (sym_char_value_character_set_1(lookahead)) ADVANCE(45);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 41:
      if (eof) ADVANCE(43);
      if (lookahead == '#') ADVANCE(14);
      if (lookahead == '$') ADVANCE(16);
      if (lookahead == '%') ADVANCE(39);
      if (lookahead == '\'') ADVANCE(105);
      if (lookahead == '.') ADVANCE(60);
      if (lookahead == '/') ADVANCE(3);
      if (lookahead == '0') ADVANCE(96);
      if (lookahead == '<') ADVANCE(71);
      if (lookahead == '@') ADVANCE(38);
      if (lookahead == 'P') ADVANCE(79);
      if (lookahead == 'S') ADVANCE(90);
      if (lookahead == '~') ADVANCE(22);
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(46);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(15);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(74);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(75);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(99);
      if (sym_char_value_character_set_1(lookahead)) ADVANCE(45);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 42:
      if (eof) ADVANCE(43);
      if (lookahead == '\'') ADVANCE(105);
      if (lookahead == '.') ADVANCE(60);
      if (lookahead == '/') ADVANCE(3);
      if (lookahead == '>') ADVANCE(73);
      if (lookahead == '@') ADVANCE(38);
      if (lookahead == 'B') ADVANCE(84);
      if (lookahead == 'D') ADVANCE(95);
      if (lookahead == 'M') ADVANCE(85);
      if (lookahead == 'R') ADVANCE(94);
      if (lookahead == ']') ADVANCE(103);
      if (lookahead == '}') ADVANCE(117);
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(46);
      if (sym_char_value_character_set_1(lookahead)) ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_macro);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym__whitespace);
      if (sym_string_segment_character_set_1(lookahead)) ADVANCE(45);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym__newline_token1);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_single_comment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(47);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_BITS);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_MINREG);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_MINHEAP);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_MINSTACK);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_RUN);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_RAM);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_ROM);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_DW);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_register);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_register);
      if (lookahead == '0') ADVANCE(62);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(62);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_register);
      if (lookahead == '0') ADVANCE(63);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(63);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_register);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_memory);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_memory);
      if (lookahead == '0') ADVANCE(66);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(66);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_memory);
      if (lookahead == '0') ADVANCE(67);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(67);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_memory);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_program_counter);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_stack_pointer);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(50);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '0') ADVANCE(68);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(67);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '0') ADVANCE(64);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(63);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'C') ADVANCE(86);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'C') ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'G') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'H') ADVANCE(80);
      if (lookahead == 'R') ADVANCE(81);
      if (lookahead == 'S') ADVANCE(93);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'I') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'I') ADVANCE(87);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'K') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'N') ADVANCE(83);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'N') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'P') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'P') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'S') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'U') ADVANCE(88);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'W') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(97);
      if (lookahead == 'o') ADVANCE(98);
      if (lookahead == 'x') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(99);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(97);
      if (('2' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(98);
      if (lookahead == '8' ||
          lookahead == '9' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(99);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(100);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_string_segment);
      if (lookahead == '*') ADVANCE(108);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(110);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_string_segment);
      if (lookahead == '*') ADVANCE(107);
      if (lookahead == '/') ADVANCE(110);
      if (lookahead == '\n' ||
          lookahead == '"' ||
          lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(108);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_string_segment);
      if (lookahead == '*') ADVANCE(107);
      if (lookahead == '\n' ||
          lookahead == '"' ||
          lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(108);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_string_segment);
      if (sym_string_segment_character_set_1(lookahead)) ADVANCE(109);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(110);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_string_segment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(110);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_char_value);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_char_value);
      if (lookahead == '*') ADVANCE(5);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_char_value);
      if (sym_string_segment_character_set_1(lookahead)) ADVANCE(45);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_BSLASHx);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_BSLASHu);
      if (lookahead == '{') ADVANCE(116);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_BSLASHu_LBRACE);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_BSLASHU);
      if (lookahead == '{') ADVANCE(119);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_BSLASHU_LBRACE);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      if (lookahead == 'U') ADVANCE(118);
      if (lookahead == 'u') ADVANCE(115);
      if (lookahead == 'x') ADVANCE(114);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_hex_escape);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_unicode_escape);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(123);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_unicode_escape_short);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_unicode_escape_long);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_char_escape);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_char_escape);
      if (lookahead == '*') ADVANCE(5);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_char_escape);
      if (sym_string_segment_character_set_1(lookahead)) ADVANCE(45);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'b') ADVANCE(23);
      if (lookahead == 'o') ADVANCE(24);
      if (lookahead == 'x') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(132);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(130);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(131);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(132);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(133);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_relative);
      if (lookahead == '0') ADVANCE(134);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(134);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_port);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(135);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 42},
  [2] = {.lex_state = 42},
  [3] = {.lex_state = 40},
  [4] = {.lex_state = 41},
  [5] = {.lex_state = 41},
  [6] = {.lex_state = 42},
  [7] = {.lex_state = 42},
  [8] = {.lex_state = 41},
  [9] = {.lex_state = 41},
  [10] = {.lex_state = 41},
  [11] = {.lex_state = 41},
  [12] = {.lex_state = 42},
  [13] = {.lex_state = 41},
  [14] = {.lex_state = 40},
  [15] = {.lex_state = 40},
  [16] = {.lex_state = 40},
  [17] = {.lex_state = 40},
  [18] = {.lex_state = 40},
  [19] = {.lex_state = 40},
  [20] = {.lex_state = 40},
  [21] = {.lex_state = 41},
  [22] = {.lex_state = 40},
  [23] = {.lex_state = 41},
  [24] = {.lex_state = 41},
  [25] = {.lex_state = 41},
  [26] = {.lex_state = 40},
  [27] = {.lex_state = 40},
  [28] = {.lex_state = 42},
  [29] = {.lex_state = 42},
  [30] = {.lex_state = 40},
  [31] = {.lex_state = 40},
  [32] = {.lex_state = 40},
  [33] = {.lex_state = 42},
  [34] = {.lex_state = 42},
  [35] = {.lex_state = 42},
  [36] = {.lex_state = 40},
  [37] = {.lex_state = 40},
  [38] = {.lex_state = 40},
  [39] = {.lex_state = 40},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 1},
  [43] = {.lex_state = 1},
  [44] = {.lex_state = 1},
  [45] = {.lex_state = 1},
  [46] = {.lex_state = 7},
  [47] = {.lex_state = 7},
  [48] = {.lex_state = 6},
  [49] = {.lex_state = 6},
  [50] = {.lex_state = 6},
  [51] = {.lex_state = 6},
  [52] = {.lex_state = 6},
  [53] = {.lex_state = 42},
  [54] = {.lex_state = 42},
  [55] = {.lex_state = 42},
  [56] = {.lex_state = 42},
  [57] = {.lex_state = 42},
  [58] = {.lex_state = 42},
  [59] = {.lex_state = 42},
  [60] = {.lex_state = 42},
  [61] = {.lex_state = 42},
  [62] = {.lex_state = 42},
  [63] = {.lex_state = 42},
  [64] = {.lex_state = 42},
  [65] = {.lex_state = 42},
  [66] = {.lex_state = 42},
  [67] = {.lex_state = 42},
  [68] = {.lex_state = 42},
  [69] = {.lex_state = 42},
  [70] = {.lex_state = 42},
  [71] = {.lex_state = 42},
  [72] = {.lex_state = 42},
  [73] = {.lex_state = 42},
  [74] = {.lex_state = 42},
  [75] = {.lex_state = 42},
  [76] = {.lex_state = 42},
  [77] = {.lex_state = 42},
  [78] = {.lex_state = 8},
  [79] = {.lex_state = 42},
  [80] = {.lex_state = 8},
  [81] = {.lex_state = 10},
  [82] = {.lex_state = 9},
  [83] = {.lex_state = 11},
  [84] = {.lex_state = 42},
  [85] = {.lex_state = 42},
  [86] = {.lex_state = 42},
  [87] = {.lex_state = 13},
  [88] = {.lex_state = 42},
  [89] = {.lex_state = 42},
  [90] = {.lex_state = 12},
  [91] = {.lex_state = 42},
  [92] = {.lex_state = 42},
  [93] = {.lex_state = 12},
  [94] = {.lex_state = 42},
  [95] = {.lex_state = 42},
  [96] = {.lex_state = 8},
  [97] = {.lex_state = 10},
  [98] = {.lex_state = 11},
  [99] = {.lex_state = 13},
  [100] = {.lex_state = 42},
  [101] = {.lex_state = 12},
  [102] = {.lex_state = 12},
  [103] = {.lex_state = 9},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__whitespace] = ACTIONS(3),
    [aux_sym__newline_token1] = ACTIONS(1),
    [sym_comment] = ACTIONS(5),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_char_value] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_BSLASH] = ACTIONS(1),
    [sym_char_escape] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(91),
    [aux_sym__newline] = STATE(2),
    [sym__header] = STATE(64),
    [sym_BITS] = STATE(64),
    [sym_MINREG] = STATE(64),
    [sym_MINHEAP] = STATE(64),
    [sym_MINSTACK] = STATE(64),
    [sym_RUN] = STATE(64),
    [sym_DW] = STATE(63),
    [sym_label] = STATE(67),
    [sym_instruction] = STATE(57),
    [aux_sym_source_file_repeat1] = STATE(12),
    [aux_sym_DW_repeat1] = STATE(52),
    [ts_builtin_sym_end] = ACTIONS(7),
    [sym_macro] = ACTIONS(9),
    [sym__whitespace] = ACTIONS(5),
    [aux_sym__newline_token1] = ACTIONS(11),
    [sym_single_comment] = ACTIONS(13),
    [sym_comment] = ACTIONS(5),
    [anon_sym_BITS] = ACTIONS(15),
    [anon_sym_MINREG] = ACTIONS(17),
    [anon_sym_MINHEAP] = ACTIONS(19),
    [anon_sym_MINSTACK] = ACTIONS(21),
    [anon_sym_RUN] = ACTIONS(23),
    [anon_sym_DW] = ACTIONS(25),
    [anon_sym_DOT] = ACTIONS(27),
    [sym_identifier] = ACTIONS(29),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 20,
    ACTIONS(9), 1,
      sym_macro,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(15), 1,
      anon_sym_BITS,
    ACTIONS(17), 1,
      anon_sym_MINREG,
    ACTIONS(19), 1,
      anon_sym_MINHEAP,
    ACTIONS(21), 1,
      anon_sym_MINSTACK,
    ACTIONS(23), 1,
      anon_sym_RUN,
    ACTIONS(25), 1,
      anon_sym_DW,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      sym_identifier,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 1,
      aux_sym__newline_token1,
    STATE(6), 1,
      aux_sym_source_file_repeat1,
    STATE(28), 1,
      aux_sym__newline,
    STATE(52), 1,
      aux_sym_DW_repeat1,
    STATE(58), 1,
      sym_instruction,
    STATE(59), 1,
      sym_DW,
    STATE(67), 1,
      sym_label,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    STATE(65), 6,
      sym__header,
      sym_BITS,
      sym_MINREG,
      sym_MINHEAP,
      sym_MINSTACK,
      sym_RUN,
  [67] = 13,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(37), 1,
      aux_sym__newline_token1,
    ACTIONS(39), 1,
      anon_sym_DOT,
    ACTIONS(43), 1,
      anon_sym_LT,
    ACTIONS(45), 1,
      anon_sym_LBRACK,
    ACTIONS(47), 1,
      anon_sym_RBRACK,
    ACTIONS(49), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      anon_sym_SQUOTE,
    STATE(56), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(35), 3,
      sym_macro,
      sym_relative,
      sym_port,
    ACTIONS(41), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    STATE(15), 8,
      sym_label,
      sym_placeholder,
      sym__dw_literal,
      sym_array,
      sym_string,
      sym_char,
      sym__immediate_literal,
      aux_sym_array_repeat1,
  [119] = 9,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(59), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_SQUOTE,
    STATE(9), 1,
      aux_sym_instruction_repeat1,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(53), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
    ACTIONS(55), 3,
      sym_macro,
      sym_relative,
      sym_port,
    STATE(21), 5,
      sym_label,
      sym__operand,
      sym_placeholder,
      sym_char,
      sym__immediate_literal,
    ACTIONS(57), 6,
      sym_register,
      sym_memory,
      sym_program_counter,
      sym_stack_pointer,
      sym_identifier,
      sym_number,
  [161] = 9,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(59), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_SQUOTE,
    STATE(11), 1,
      aux_sym_instruction_repeat1,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(55), 3,
      sym_macro,
      sym_relative,
      sym_port,
    ACTIONS(63), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
    STATE(21), 5,
      sym_label,
      sym__operand,
      sym_placeholder,
      sym_char,
      sym__immediate_literal,
    ACTIONS(57), 6,
      sym_register,
      sym_memory,
      sym_program_counter,
      sym_stack_pointer,
      sym_identifier,
      sym_number,
  [203] = 17,
    ACTIONS(9), 1,
      sym_macro,
    ACTIONS(15), 1,
      anon_sym_BITS,
    ACTIONS(17), 1,
      anon_sym_MINREG,
    ACTIONS(19), 1,
      anon_sym_MINHEAP,
    ACTIONS(21), 1,
      anon_sym_MINSTACK,
    ACTIONS(23), 1,
      anon_sym_RUN,
    ACTIONS(25), 1,
      anon_sym_DW,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      sym_identifier,
    ACTIONS(65), 1,
      ts_builtin_sym_end,
    STATE(7), 1,
      aux_sym_source_file_repeat1,
    STATE(52), 1,
      aux_sym_DW_repeat1,
    STATE(61), 1,
      sym_DW,
    STATE(62), 1,
      sym_instruction,
    STATE(67), 1,
      sym_label,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    STATE(60), 6,
      sym__header,
      sym_BITS,
      sym_MINREG,
      sym_MINHEAP,
      sym_MINSTACK,
      sym_RUN,
  [261] = 17,
    ACTIONS(67), 1,
      ts_builtin_sym_end,
    ACTIONS(69), 1,
      sym_macro,
    ACTIONS(72), 1,
      anon_sym_BITS,
    ACTIONS(75), 1,
      anon_sym_MINREG,
    ACTIONS(78), 1,
      anon_sym_MINHEAP,
    ACTIONS(81), 1,
      anon_sym_MINSTACK,
    ACTIONS(84), 1,
      anon_sym_RUN,
    ACTIONS(87), 1,
      anon_sym_DW,
    ACTIONS(90), 1,
      anon_sym_DOT,
    ACTIONS(93), 1,
      sym_identifier,
    STATE(7), 1,
      aux_sym_source_file_repeat1,
    STATE(52), 1,
      aux_sym_DW_repeat1,
    STATE(67), 1,
      sym_label,
    STATE(70), 1,
      sym_DW,
    STATE(71), 1,
      sym_instruction,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    STATE(69), 6,
      sym__header,
      sym_BITS,
      sym_MINREG,
      sym_MINHEAP,
      sym_MINSTACK,
      sym_RUN,
  [319] = 9,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(59), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_SQUOTE,
    STATE(10), 1,
      aux_sym_instruction_repeat1,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(53), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
    ACTIONS(55), 3,
      sym_macro,
      sym_relative,
      sym_port,
    STATE(21), 5,
      sym_label,
      sym__operand,
      sym_placeholder,
      sym_char,
      sym__immediate_literal,
    ACTIONS(57), 6,
      sym_register,
      sym_memory,
      sym_program_counter,
      sym_stack_pointer,
      sym_identifier,
      sym_number,
  [361] = 9,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(59), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_SQUOTE,
    STATE(13), 1,
      aux_sym_instruction_repeat1,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(55), 3,
      sym_macro,
      sym_relative,
      sym_port,
    ACTIONS(96), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
    STATE(21), 5,
      sym_label,
      sym__operand,
      sym_placeholder,
      sym_char,
      sym__immediate_literal,
    ACTIONS(57), 6,
      sym_register,
      sym_memory,
      sym_program_counter,
      sym_stack_pointer,
      sym_identifier,
      sym_number,
  [403] = 9,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(59), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_SQUOTE,
    STATE(13), 1,
      aux_sym_instruction_repeat1,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(55), 3,
      sym_macro,
      sym_relative,
      sym_port,
    ACTIONS(96), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
    STATE(21), 5,
      sym_label,
      sym__operand,
      sym_placeholder,
      sym_char,
      sym__immediate_literal,
    ACTIONS(57), 6,
      sym_register,
      sym_memory,
      sym_program_counter,
      sym_stack_pointer,
      sym_identifier,
      sym_number,
  [445] = 9,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(59), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_SQUOTE,
    STATE(13), 1,
      aux_sym_instruction_repeat1,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(55), 3,
      sym_macro,
      sym_relative,
      sym_port,
    ACTIONS(98), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
    STATE(21), 5,
      sym_label,
      sym__operand,
      sym_placeholder,
      sym_char,
      sym__immediate_literal,
    ACTIONS(57), 6,
      sym_register,
      sym_memory,
      sym_program_counter,
      sym_stack_pointer,
      sym_identifier,
      sym_number,
  [487] = 17,
    ACTIONS(9), 1,
      sym_macro,
    ACTIONS(15), 1,
      anon_sym_BITS,
    ACTIONS(17), 1,
      anon_sym_MINREG,
    ACTIONS(19), 1,
      anon_sym_MINHEAP,
    ACTIONS(21), 1,
      anon_sym_MINSTACK,
    ACTIONS(23), 1,
      anon_sym_RUN,
    ACTIONS(25), 1,
      anon_sym_DW,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      sym_identifier,
    ACTIONS(100), 1,
      ts_builtin_sym_end,
    STATE(7), 1,
      aux_sym_source_file_repeat1,
    STATE(52), 1,
      aux_sym_DW_repeat1,
    STATE(53), 1,
      sym_instruction,
    STATE(54), 1,
      sym_DW,
    STATE(67), 1,
      sym_label,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    STATE(55), 6,
      sym__header,
      sym_BITS,
      sym_MINREG,
      sym_MINHEAP,
      sym_MINSTACK,
      sym_RUN,
  [545] = 9,
    ACTIONS(107), 1,
      anon_sym_DOT,
    ACTIONS(113), 1,
      anon_sym_LT,
    ACTIONS(116), 1,
      anon_sym_SQUOTE,
    STATE(13), 1,
      aux_sym_instruction_repeat1,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(102), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
    ACTIONS(104), 3,
      sym_macro,
      sym_relative,
      sym_port,
    STATE(21), 5,
      sym_label,
      sym__operand,
      sym_placeholder,
      sym_char,
      sym__immediate_literal,
    ACTIONS(110), 6,
      sym_register,
      sym_memory,
      sym_program_counter,
      sym_stack_pointer,
      sym_identifier,
      sym_number,
  [587] = 10,
    ACTIONS(122), 1,
      anon_sym_DOT,
    ACTIONS(128), 1,
      anon_sym_LT,
    ACTIONS(131), 1,
      anon_sym_LBRACK,
    ACTIONS(134), 1,
      anon_sym_RBRACK,
    ACTIONS(136), 1,
      anon_sym_DQUOTE,
    ACTIONS(139), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(119), 3,
      sym_macro,
      sym_relative,
      sym_port,
    ACTIONS(125), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    STATE(14), 8,
      sym_label,
      sym_placeholder,
      sym__dw_literal,
      sym_array,
      sym_string,
      sym_char,
      sym__immediate_literal,
      aux_sym_array_repeat1,
  [630] = 10,
    ACTIONS(39), 1,
      anon_sym_DOT,
    ACTIONS(43), 1,
      anon_sym_LT,
    ACTIONS(45), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      anon_sym_SQUOTE,
    ACTIONS(146), 1,
      anon_sym_RBRACK,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(142), 3,
      sym_macro,
      sym_relative,
      sym_port,
    ACTIONS(144), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    STATE(14), 8,
      sym_label,
      sym_placeholder,
      sym__dw_literal,
      sym_array,
      sym_string,
      sym_char,
      sym__immediate_literal,
      aux_sym_array_repeat1,
  [673] = 9,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(45), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_DQUOTE,
    ACTIONS(59), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(148), 3,
      sym_macro,
      sym_relative,
      sym_port,
    ACTIONS(150), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    STATE(75), 7,
      sym_label,
      sym_placeholder,
      sym__dw_literal,
      sym_array,
      sym_string,
      sym_char,
      sym__immediate_literal,
  [712] = 9,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(45), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_DQUOTE,
    ACTIONS(59), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(152), 3,
      sym_macro,
      sym_relative,
      sym_port,
    ACTIONS(154), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    STATE(68), 7,
      sym_label,
      sym_placeholder,
      sym__dw_literal,
      sym_array,
      sym_string,
      sym_char,
      sym__immediate_literal,
  [751] = 8,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(61), 1,
      anon_sym_SQUOTE,
    ACTIONS(162), 1,
      anon_sym_LT,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(156), 3,
      sym_macro,
      sym_relative,
      sym_port,
    ACTIONS(158), 3,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_GT_EQ,
    ACTIONS(160), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    STATE(74), 4,
      sym_label,
      sym_placeholder,
      sym_char,
      sym__immediate_literal,
  [786] = 3,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(166), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    ACTIONS(164), 12,
      ts_builtin_sym_end,
      sym_macro,
      aux_sym__newline_token1,
      sym_single_comment,
      anon_sym_DOT,
      anon_sym_LT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_relative,
      sym_port,
  [810] = 3,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(170), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    ACTIONS(168), 12,
      ts_builtin_sym_end,
      sym_macro,
      aux_sym__newline_token1,
      sym_single_comment,
      anon_sym_DOT,
      anon_sym_LT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_relative,
      sym_port,
  [834] = 3,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(174), 6,
      sym_register,
      sym_memory,
      sym_program_counter,
      sym_stack_pointer,
      sym_identifier,
      sym_number,
    ACTIONS(172), 9,
      ts_builtin_sym_end,
      sym_macro,
      aux_sym__newline_token1,
      sym_single_comment,
      anon_sym_DOT,
      anon_sym_LT,
      anon_sym_SQUOTE,
      sym_relative,
      sym_port,
  [858] = 3,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(178), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    ACTIONS(176), 12,
      ts_builtin_sym_end,
      sym_macro,
      aux_sym__newline_token1,
      sym_single_comment,
      anon_sym_DOT,
      anon_sym_LT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_relative,
      sym_port,
  [882] = 3,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(182), 6,
      sym_register,
      sym_memory,
      sym_program_counter,
      sym_stack_pointer,
      sym_identifier,
      sym_number,
    ACTIONS(180), 9,
      ts_builtin_sym_end,
      sym_macro,
      aux_sym__newline_token1,
      sym_single_comment,
      anon_sym_DOT,
      anon_sym_LT,
      anon_sym_SQUOTE,
      sym_relative,
      sym_port,
  [906] = 3,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(186), 6,
      sym_register,
      sym_memory,
      sym_program_counter,
      sym_stack_pointer,
      sym_identifier,
      sym_number,
    ACTIONS(184), 9,
      ts_builtin_sym_end,
      sym_macro,
      aux_sym__newline_token1,
      sym_single_comment,
      anon_sym_DOT,
      anon_sym_LT,
      anon_sym_SQUOTE,
      sym_relative,
      sym_port,
  [930] = 3,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(190), 6,
      sym_register,
      sym_memory,
      sym_program_counter,
      sym_stack_pointer,
      sym_identifier,
      sym_number,
    ACTIONS(188), 9,
      ts_builtin_sym_end,
      sym_macro,
      aux_sym__newline_token1,
      sym_single_comment,
      anon_sym_DOT,
      anon_sym_LT,
      anon_sym_SQUOTE,
      sym_relative,
      sym_port,
  [954] = 3,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(194), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    ACTIONS(192), 12,
      ts_builtin_sym_end,
      sym_macro,
      aux_sym__newline_token1,
      sym_single_comment,
      anon_sym_DOT,
      anon_sym_LT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_relative,
      sym_port,
  [978] = 3,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(198), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    ACTIONS(196), 12,
      ts_builtin_sym_end,
      sym_macro,
      aux_sym__newline_token1,
      sym_single_comment,
      anon_sym_DOT,
      anon_sym_LT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_relative,
      sym_port,
  [1002] = 6,
    ACTIONS(202), 1,
      aux_sym__newline_token1,
    ACTIONS(205), 1,
      sym_single_comment,
    STATE(28), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(200), 4,
      ts_builtin_sym_end,
      sym_macro,
      anon_sym_DOT,
      anon_sym_RBRACK,
    ACTIONS(208), 7,
      anon_sym_BITS,
      anon_sym_MINREG,
      anon_sym_MINHEAP,
      anon_sym_MINSTACK,
      anon_sym_RUN,
      anon_sym_DW,
      sym_identifier,
  [1031] = 6,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(33), 1,
      aux_sym__newline_token1,
    STATE(28), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(210), 3,
      ts_builtin_sym_end,
      sym_macro,
      anon_sym_DOT,
    ACTIONS(212), 7,
      anon_sym_BITS,
      anon_sym_MINREG,
      anon_sym_MINHEAP,
      anon_sym_MINSTACK,
      anon_sym_RUN,
      anon_sym_DW,
      sym_identifier,
  [1059] = 7,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(59), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(214), 3,
      sym_macro,
      sym_relative,
      sym_port,
    ACTIONS(216), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    STATE(66), 4,
      sym_label,
      sym_placeholder,
      sym_char,
      sym__immediate_literal,
  [1089] = 7,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(59), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(218), 3,
      sym_macro,
      sym_relative,
      sym_port,
    ACTIONS(220), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    STATE(73), 4,
      sym_label,
      sym_placeholder,
      sym_char,
      sym__immediate_literal,
  [1119] = 7,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(59), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(222), 3,
      sym_macro,
      sym_relative,
      sym_port,
    ACTIONS(224), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    STATE(77), 4,
      sym_label,
      sym_placeholder,
      sym_char,
      sym__immediate_literal,
  [1149] = 6,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(33), 1,
      aux_sym__newline_token1,
    STATE(28), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(226), 3,
      ts_builtin_sym_end,
      sym_macro,
      anon_sym_DOT,
    ACTIONS(228), 7,
      anon_sym_BITS,
      anon_sym_MINREG,
      anon_sym_MINHEAP,
      anon_sym_MINSTACK,
      anon_sym_RUN,
      anon_sym_DW,
      sym_identifier,
  [1177] = 6,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(33), 1,
      aux_sym__newline_token1,
    STATE(28), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(230), 3,
      ts_builtin_sym_end,
      sym_macro,
      anon_sym_DOT,
    ACTIONS(232), 7,
      anon_sym_BITS,
      anon_sym_MINREG,
      anon_sym_MINHEAP,
      anon_sym_MINSTACK,
      anon_sym_RUN,
      anon_sym_DW,
      sym_identifier,
  [1205] = 3,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(200), 6,
      ts_builtin_sym_end,
      sym_macro,
      aux_sym__newline_token1,
      sym_single_comment,
      anon_sym_DOT,
      anon_sym_RBRACK,
    ACTIONS(208), 7,
      anon_sym_BITS,
      anon_sym_MINREG,
      anon_sym_MINHEAP,
      anon_sym_MINSTACK,
      anon_sym_RUN,
      anon_sym_DW,
      sym_identifier,
  [1227] = 7,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(59), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(234), 3,
      sym_macro,
      sym_relative,
      sym_port,
    ACTIONS(236), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    STATE(72), 4,
      sym_label,
      sym_placeholder,
      sym_char,
      sym__immediate_literal,
  [1257] = 3,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(182), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    ACTIONS(180), 9,
      sym_macro,
      anon_sym_DOT,
      anon_sym_LT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_relative,
      sym_port,
  [1278] = 3,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(190), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    ACTIONS(188), 9,
      sym_macro,
      anon_sym_DOT,
      anon_sym_LT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_relative,
      sym_port,
  [1299] = 3,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(186), 3,
      sym_memory,
      sym_identifier,
      sym_number,
    ACTIONS(184), 9,
      sym_macro,
      anon_sym_DOT,
      anon_sym_LT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_relative,
      sym_port,
  [1320] = 10,
    ACTIONS(238), 1,
      anon_sym_DQUOTE,
    ACTIONS(240), 1,
      sym_string_segment,
    ACTIONS(243), 1,
      anon_sym_BSLASHx,
    ACTIONS(246), 1,
      anon_sym_BSLASHu,
    ACTIONS(252), 1,
      anon_sym_BSLASHU,
    ACTIONS(255), 1,
      anon_sym_BSLASH,
    STATE(40), 1,
      aux_sym_string_repeat1,
    STATE(44), 1,
      sym_escape_sequence,
    ACTIONS(3), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(249), 2,
      anon_sym_BSLASHu_LBRACE,
      anon_sym_BSLASHU_LBRACE,
  [1353] = 10,
    ACTIONS(258), 1,
      anon_sym_DQUOTE,
    ACTIONS(260), 1,
      sym_string_segment,
    ACTIONS(262), 1,
      anon_sym_BSLASHx,
    ACTIONS(264), 1,
      anon_sym_BSLASHu,
    ACTIONS(268), 1,
      anon_sym_BSLASHU,
    ACTIONS(270), 1,
      anon_sym_BSLASH,
    STATE(42), 1,
      aux_sym_string_repeat1,
    STATE(44), 1,
      sym_escape_sequence,
    ACTIONS(3), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(266), 2,
      anon_sym_BSLASHu_LBRACE,
      anon_sym_BSLASHU_LBRACE,
  [1386] = 10,
    ACTIONS(260), 1,
      sym_string_segment,
    ACTIONS(262), 1,
      anon_sym_BSLASHx,
    ACTIONS(264), 1,
      anon_sym_BSLASHu,
    ACTIONS(268), 1,
      anon_sym_BSLASHU,
    ACTIONS(270), 1,
      anon_sym_BSLASH,
    ACTIONS(272), 1,
      anon_sym_DQUOTE,
    STATE(40), 1,
      aux_sym_string_repeat1,
    STATE(44), 1,
      sym_escape_sequence,
    ACTIONS(3), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(266), 2,
      anon_sym_BSLASHu_LBRACE,
      anon_sym_BSLASHU_LBRACE,
  [1419] = 3,
    ACTIONS(3), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(274), 4,
      anon_sym_DQUOTE,
      anon_sym_BSLASHx,
      anon_sym_BSLASHu_LBRACE,
      anon_sym_BSLASHU_LBRACE,
    ACTIONS(276), 4,
      sym_string_segment,
      anon_sym_BSLASHu,
      anon_sym_BSLASHU,
      anon_sym_BSLASH,
  [1436] = 3,
    ACTIONS(3), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(278), 4,
      anon_sym_DQUOTE,
      anon_sym_BSLASHx,
      anon_sym_BSLASHu_LBRACE,
      anon_sym_BSLASHU_LBRACE,
    ACTIONS(280), 4,
      sym_string_segment,
      anon_sym_BSLASHu,
      anon_sym_BSLASHU,
      anon_sym_BSLASH,
  [1453] = 3,
    ACTIONS(3), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(282), 4,
      anon_sym_DQUOTE,
      anon_sym_BSLASHx,
      anon_sym_BSLASHu_LBRACE,
      anon_sym_BSLASHU_LBRACE,
    ACTIONS(284), 4,
      sym_string_segment,
      anon_sym_BSLASHu,
      anon_sym_BSLASHU,
      anon_sym_BSLASH,
  [1470] = 9,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(286), 1,
      sym_char_value,
    ACTIONS(288), 1,
      anon_sym_BSLASHx,
    ACTIONS(290), 1,
      anon_sym_BSLASHu,
    ACTIONS(294), 1,
      anon_sym_BSLASHU,
    ACTIONS(296), 1,
      anon_sym_BSLASH,
    STATE(79), 1,
      sym_escape_sequence,
    ACTIONS(292), 2,
      anon_sym_BSLASHu_LBRACE,
      anon_sym_BSLASHU_LBRACE,
  [1499] = 9,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(288), 1,
      anon_sym_BSLASHx,
    ACTIONS(290), 1,
      anon_sym_BSLASHu,
    ACTIONS(294), 1,
      anon_sym_BSLASHU,
    ACTIONS(296), 1,
      anon_sym_BSLASH,
    ACTIONS(298), 1,
      sym_char_value,
    STATE(95), 1,
      sym_escape_sequence,
    ACTIONS(292), 2,
      anon_sym_BSLASHu_LBRACE,
      anon_sym_BSLASHU_LBRACE,
  [1528] = 6,
    ACTIONS(300), 1,
      aux_sym__newline_token1,
    ACTIONS(303), 1,
      sym_single_comment,
    STATE(48), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(200), 2,
      sym_macro,
      anon_sym_DOT,
    ACTIONS(208), 2,
      anon_sym_DW,
      sym_identifier,
  [1550] = 6,
    ACTIONS(308), 1,
      aux_sym__newline_token1,
    ACTIONS(310), 1,
      sym_single_comment,
    STATE(48), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(306), 2,
      sym_macro,
      anon_sym_DOT,
    ACTIONS(312), 2,
      anon_sym_DW,
      sym_identifier,
  [1572] = 3,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(208), 2,
      anon_sym_DW,
      sym_identifier,
    ACTIONS(200), 4,
      sym_macro,
      aux_sym__newline_token1,
      sym_single_comment,
      anon_sym_DOT,
  [1587] = 6,
    ACTIONS(314), 1,
      sym_macro,
    ACTIONS(318), 1,
      anon_sym_DOT,
    STATE(51), 1,
      aux_sym_DW_repeat1,
    STATE(67), 1,
      sym_label,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(316), 2,
      anon_sym_DW,
      sym_identifier,
  [1608] = 7,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(321), 1,
      sym_macro,
    ACTIONS(323), 1,
      anon_sym_DW,
    ACTIONS(325), 1,
      sym_identifier,
    STATE(51), 1,
      aux_sym_DW_repeat1,
    STATE(67), 1,
      sym_label,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1631] = 5,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(327), 1,
      ts_builtin_sym_end,
    ACTIONS(329), 1,
      aux_sym__newline_token1,
    STATE(34), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1648] = 5,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(331), 1,
      ts_builtin_sym_end,
    ACTIONS(333), 1,
      aux_sym__newline_token1,
    STATE(33), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1665] = 5,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(335), 1,
      ts_builtin_sym_end,
    ACTIONS(337), 1,
      aux_sym__newline_token1,
    STATE(29), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1682] = 5,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(33), 1,
      aux_sym__newline_token1,
    ACTIONS(339), 1,
      anon_sym_RBRACK,
    STATE(28), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1699] = 5,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(329), 1,
      aux_sym__newline_token1,
    ACTIONS(341), 1,
      ts_builtin_sym_end,
    STATE(34), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1716] = 5,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(329), 1,
      aux_sym__newline_token1,
    ACTIONS(343), 1,
      ts_builtin_sym_end,
    STATE(34), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1733] = 5,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(333), 1,
      aux_sym__newline_token1,
    ACTIONS(345), 1,
      ts_builtin_sym_end,
    STATE(33), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1750] = 5,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(337), 1,
      aux_sym__newline_token1,
    ACTIONS(347), 1,
      ts_builtin_sym_end,
    STATE(29), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1767] = 5,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(333), 1,
      aux_sym__newline_token1,
    ACTIONS(349), 1,
      ts_builtin_sym_end,
    STATE(33), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1784] = 5,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(329), 1,
      aux_sym__newline_token1,
    ACTIONS(351), 1,
      ts_builtin_sym_end,
    STATE(34), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1801] = 5,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(333), 1,
      aux_sym__newline_token1,
    ACTIONS(353), 1,
      ts_builtin_sym_end,
    STATE(33), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1818] = 5,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(337), 1,
      aux_sym__newline_token1,
    ACTIONS(355), 1,
      ts_builtin_sym_end,
    STATE(29), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1835] = 5,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(337), 1,
      aux_sym__newline_token1,
    ACTIONS(357), 1,
      ts_builtin_sym_end,
    STATE(29), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1852] = 2,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(359), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
  [1862] = 4,
    ACTIONS(310), 1,
      sym_single_comment,
    ACTIONS(361), 1,
      aux_sym__newline_token1,
    STATE(49), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1876] = 2,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(363), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
  [1886] = 4,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(337), 1,
      aux_sym__newline_token1,
    STATE(29), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1900] = 4,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(333), 1,
      aux_sym__newline_token1,
    STATE(33), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1914] = 4,
    ACTIONS(13), 1,
      sym_single_comment,
    ACTIONS(329), 1,
      aux_sym__newline_token1,
    STATE(34), 1,
      aux_sym__newline,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [1928] = 2,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(365), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
  [1938] = 2,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(367), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
  [1948] = 2,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(369), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
  [1958] = 2,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(371), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
  [1968] = 2,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(373), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
  [1978] = 2,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(375), 3,
      ts_builtin_sym_end,
      aux_sym__newline_token1,
      sym_single_comment,
  [1988] = 2,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
    ACTIONS(377), 2,
      anon_sym_RAM,
      anon_sym_ROM,
  [1997] = 2,
    ACTIONS(379), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2005] = 2,
    ACTIONS(381), 1,
      sym_hex_escape,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2013] = 2,
    ACTIONS(381), 1,
      sym_unicode_escape_short,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2021] = 2,
    ACTIONS(383), 1,
      sym_unicode_escape,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2029] = 2,
    ACTIONS(381), 1,
      sym_unicode_escape_long,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2037] = 2,
    ACTIONS(282), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2045] = 2,
    ACTIONS(274), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2053] = 2,
    ACTIONS(385), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2061] = 3,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(387), 1,
      sym_char_escape,
  [2071] = 2,
    ACTIONS(389), 1,
      aux_sym__newline_token1,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2079] = 2,
    ACTIONS(391), 1,
      anon_sym_GT,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2087] = 2,
    ACTIONS(393), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2095] = 2,
    ACTIONS(395), 1,
      ts_builtin_sym_end,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2103] = 2,
    ACTIONS(397), 1,
      aux_sym__newline_token1,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2111] = 2,
    ACTIONS(399), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2119] = 2,
    ACTIONS(401), 1,
      anon_sym_GT,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2127] = 2,
    ACTIONS(403), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2135] = 2,
    ACTIONS(405), 1,
      sym_hex_escape,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2143] = 2,
    ACTIONS(405), 1,
      sym_unicode_escape_short,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2151] = 2,
    ACTIONS(405), 1,
      sym_unicode_escape_long,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2159] = 3,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(407), 1,
      sym_char_escape,
  [2169] = 2,
    ACTIONS(409), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2177] = 2,
    ACTIONS(411), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2185] = 2,
    ACTIONS(413), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
  [2193] = 2,
    ACTIONS(415), 1,
      sym_unicode_escape,
    ACTIONS(5), 2,
      sym__whitespace,
      sym_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 67,
  [SMALL_STATE(4)] = 119,
  [SMALL_STATE(5)] = 161,
  [SMALL_STATE(6)] = 203,
  [SMALL_STATE(7)] = 261,
  [SMALL_STATE(8)] = 319,
  [SMALL_STATE(9)] = 361,
  [SMALL_STATE(10)] = 403,
  [SMALL_STATE(11)] = 445,
  [SMALL_STATE(12)] = 487,
  [SMALL_STATE(13)] = 545,
  [SMALL_STATE(14)] = 587,
  [SMALL_STATE(15)] = 630,
  [SMALL_STATE(16)] = 673,
  [SMALL_STATE(17)] = 712,
  [SMALL_STATE(18)] = 751,
  [SMALL_STATE(19)] = 786,
  [SMALL_STATE(20)] = 810,
  [SMALL_STATE(21)] = 834,
  [SMALL_STATE(22)] = 858,
  [SMALL_STATE(23)] = 882,
  [SMALL_STATE(24)] = 906,
  [SMALL_STATE(25)] = 930,
  [SMALL_STATE(26)] = 954,
  [SMALL_STATE(27)] = 978,
  [SMALL_STATE(28)] = 1002,
  [SMALL_STATE(29)] = 1031,
  [SMALL_STATE(30)] = 1059,
  [SMALL_STATE(31)] = 1089,
  [SMALL_STATE(32)] = 1119,
  [SMALL_STATE(33)] = 1149,
  [SMALL_STATE(34)] = 1177,
  [SMALL_STATE(35)] = 1205,
  [SMALL_STATE(36)] = 1227,
  [SMALL_STATE(37)] = 1257,
  [SMALL_STATE(38)] = 1278,
  [SMALL_STATE(39)] = 1299,
  [SMALL_STATE(40)] = 1320,
  [SMALL_STATE(41)] = 1353,
  [SMALL_STATE(42)] = 1386,
  [SMALL_STATE(43)] = 1419,
  [SMALL_STATE(44)] = 1436,
  [SMALL_STATE(45)] = 1453,
  [SMALL_STATE(46)] = 1470,
  [SMALL_STATE(47)] = 1499,
  [SMALL_STATE(48)] = 1528,
  [SMALL_STATE(49)] = 1550,
  [SMALL_STATE(50)] = 1572,
  [SMALL_STATE(51)] = 1587,
  [SMALL_STATE(52)] = 1608,
  [SMALL_STATE(53)] = 1631,
  [SMALL_STATE(54)] = 1648,
  [SMALL_STATE(55)] = 1665,
  [SMALL_STATE(56)] = 1682,
  [SMALL_STATE(57)] = 1699,
  [SMALL_STATE(58)] = 1716,
  [SMALL_STATE(59)] = 1733,
  [SMALL_STATE(60)] = 1750,
  [SMALL_STATE(61)] = 1767,
  [SMALL_STATE(62)] = 1784,
  [SMALL_STATE(63)] = 1801,
  [SMALL_STATE(64)] = 1818,
  [SMALL_STATE(65)] = 1835,
  [SMALL_STATE(66)] = 1852,
  [SMALL_STATE(67)] = 1862,
  [SMALL_STATE(68)] = 1876,
  [SMALL_STATE(69)] = 1886,
  [SMALL_STATE(70)] = 1900,
  [SMALL_STATE(71)] = 1914,
  [SMALL_STATE(72)] = 1928,
  [SMALL_STATE(73)] = 1938,
  [SMALL_STATE(74)] = 1948,
  [SMALL_STATE(75)] = 1958,
  [SMALL_STATE(76)] = 1968,
  [SMALL_STATE(77)] = 1978,
  [SMALL_STATE(78)] = 1988,
  [SMALL_STATE(79)] = 1997,
  [SMALL_STATE(80)] = 2005,
  [SMALL_STATE(81)] = 2013,
  [SMALL_STATE(82)] = 2021,
  [SMALL_STATE(83)] = 2029,
  [SMALL_STATE(84)] = 2037,
  [SMALL_STATE(85)] = 2045,
  [SMALL_STATE(86)] = 2053,
  [SMALL_STATE(87)] = 2061,
  [SMALL_STATE(88)] = 2071,
  [SMALL_STATE(89)] = 2079,
  [SMALL_STATE(90)] = 2087,
  [SMALL_STATE(91)] = 2095,
  [SMALL_STATE(92)] = 2103,
  [SMALL_STATE(93)] = 2111,
  [SMALL_STATE(94)] = 2119,
  [SMALL_STATE(95)] = 2127,
  [SMALL_STATE(96)] = 2135,
  [SMALL_STATE(97)] = 2143,
  [SMALL_STATE(98)] = 2151,
  [SMALL_STATE(99)] = 2159,
  [SMALL_STATE(100)] = 2169,
  [SMALL_STATE(101)] = 2177,
  [SMALL_STATE(102)] = 2185,
  [SMALL_STATE(103)] = 2193,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instruction, 2, .production_id = 20),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instruction, 1, .production_id = 1),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2, .production_id = 14),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 19),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 19), SHIFT_REPEAT(5),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 19), SHIFT_REPEAT(18),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 19), SHIFT_REPEAT(31),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 19), SHIFT_REPEAT(36),
  [81] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 19), SHIFT_REPEAT(32),
  [84] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 19), SHIFT_REPEAT(78),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 19), SHIFT_REPEAT(16),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 19), SHIFT_REPEAT(102),
  [93] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 19), SHIFT_REPEAT(5),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instruction, 3, .production_id = 28),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instruction, 2, .production_id = 7),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, .production_id = 5),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_instruction_repeat1, 2, .production_id = 22),
  [104] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_instruction_repeat1, 2, .production_id = 22), SHIFT_REPEAT(21),
  [107] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_instruction_repeat1, 2, .production_id = 22), SHIFT_REPEAT(102),
  [110] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_instruction_repeat1, 2, .production_id = 22), SHIFT_REPEAT(21),
  [113] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_instruction_repeat1, 2, .production_id = 22), SHIFT_REPEAT(90),
  [116] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_instruction_repeat1, 2, .production_id = 22), SHIFT_REPEAT(46),
  [119] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(14),
  [122] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(93),
  [125] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(14),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(101),
  [131] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(3),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2),
  [136] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(41),
  [139] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(47),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [144] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [154] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [160] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2),
  [166] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 2),
  [170] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 2),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_instruction_repeat1, 1, .production_id = 6),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_instruction_repeat1, 1, .production_id = 6),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, .production_id = 32),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, .production_id = 32),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2, .production_id = 10),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2, .production_id = 10),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_placeholder, 3),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_placeholder, 3),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_char, 3, .production_id = 30),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_char, 3, .production_id = 30),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 3),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3, .production_id = 31),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 3, .production_id = 31),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__newline, 2),
  [202] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__newline, 2), SHIFT_REPEAT(28),
  [205] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__newline, 2), SHIFT_REPEAT(88),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__newline, 2),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 2),
  [212] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 2),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [216] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [220] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [224] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 3),
  [228] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 3),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 4),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, .production_id = 4),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [236] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, .production_id = 33),
  [240] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, .production_id = 33), SHIFT_REPEAT(44),
  [243] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, .production_id = 33), SHIFT_REPEAT(96),
  [246] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, .production_id = 33), SHIFT_REPEAT(97),
  [249] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, .production_id = 33), SHIFT_REPEAT(103),
  [252] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, .production_id = 33), SHIFT_REPEAT(98),
  [255] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, .production_id = 33), SHIFT_REPEAT(99),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [260] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [264] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [268] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [270] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_escape_sequence, 2, .production_id = 8),
  [276] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_escape_sequence, 2, .production_id = 8),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 1, .production_id = 24),
  [280] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 1, .production_id = 24),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_escape_sequence, 3, .production_id = 8),
  [284] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_escape_sequence, 3, .production_id = 8),
  [286] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [290] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [294] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [296] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [298] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [300] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__newline, 2), SHIFT_REPEAT(48),
  [303] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__newline, 2), SHIFT_REPEAT(92),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_DW_repeat1, 2, .production_id = 15),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [312] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_DW_repeat1, 2, .production_id = 15),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_DW_repeat1, 2, .production_id = 21),
  [316] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_DW_repeat1, 2, .production_id = 21),
  [318] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_DW_repeat1, 2, .production_id = 21), SHIFT_REPEAT(102),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [323] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [325] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [327] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2, .production_id = 18),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2, .production_id = 17),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [335] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2, .production_id = 16),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, .production_id = 4),
  [343] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2, .production_id = 13),
  [345] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2, .production_id = 12),
  [347] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 3, .production_id = 25),
  [349] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 3, .production_id = 26),
  [351] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 3, .production_id = 27),
  [353] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, .production_id = 3),
  [355] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, .production_id = 2),
  [357] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2, .production_id = 11),
  [359] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_BITS, 3, .production_id = 23),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [363] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DW, 3, .production_id = 29),
  [365] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MINHEAP, 2, .production_id = 8),
  [367] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MINREG, 2, .production_id = 8),
  [369] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_BITS, 2, .production_id = 8),
  [371] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DW, 2, .production_id = 8),
  [373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_RUN, 2, .production_id = 9),
  [375] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MINSTACK, 2, .production_id = 8),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [387] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [395] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [407] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_URCL(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
