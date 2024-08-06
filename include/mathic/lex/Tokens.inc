#ifndef NULL
/// @brief NULL pointer. (why it wasn't alredy defined??)
#   define NULL ((void *)0x00)
#endif // NULL - non si sa mai...

#ifndef _Expand
/// @brief Expands macro value.
#   define _Expand(x) x
#endif // _Expand

/* MIT License - Copyright (c) 2024 Frithurik Grint */

#ifndef _DefineToken
/// @brief Placeholder declaration of _DefineToken(...).
#   define _DefineToken(name)

#   ifndef _DefineLexeme
/// @brief Placeholder declaration of _DefineLexeme(...).
#       define _DefineLexeme(name, text, lexeme)
#   endif // _DefineLexeme
#else
#   ifdef _DefineLexeme
/// Cannot define external _DefineLexeme if is alredy
/// defined an external _DefineToken. Undefine this
/// macro avoids errors.
#       undef _DefineLexeme
#   endif // UNDEF _DefineLexeme

/// @brief Cannot define external _DefineLexeme if is alredy
///        defined an external _DefineToken.
#   define _DefineLexeme(name, text, lexeme)
#endif // _DefineToken

/* =---- Trivia Tokens -----------------------------------------= */

#ifndef _DefineTriviaToken
/// @brief Internal macro for trivia tokens defintion.
#   define _DefineTriviaToken(name, text) _DefineToken(name) _DefineLexeme(name, "<" text "/>", text)
#endif // _DefineTriviaToken

/// @brief EOF trivia token. (end of file)
_DefineTriviaToken(ENDOF,                                       "eof")
/// @brief EOL trivia token. (end of line) - normally it's disabled
_DefineTriviaToken(ENDOL,                                       "eol")
/// @brief NUL trivia token. (end of string)
_DefineTriviaToken(NULCH,                                       "nul")
/// @brief WSP trivia token. (white spaces) - normally it's disabled
_DefineTriviaToken(SPACE,                                       "wsp")

#ifdef _DefineTriviaToken
#   undef _DefineTriviaToken
#endif // UNDEF _DefineTriviaToken

/* =---- Identifier Tokens -------------------------------------= */

#ifndef _DefineIdentsToken
/// @brief Internal macro for identifier tokens defintion.
#   define _DefineIdentsToken(name, text) _DefineToken(name) _DefineLexeme(name, "<" text ">%s<" text "/>", text)
#endif // _DefineIdentsToken

/// @brief Identifier trivia token.
_DefineIdentsToken(IDENT,                                       "ident")
/// @brief Template identifier trivia token.
_DefineIdentsToken(TEMPL,                                       "templ")
/// @brief Reserved word trivia token.
_DefineIdentsToken(RWORD,                                       "rword")

#ifdef _DefineIdentsToken
#   undef _DefineIdentsToken
#endif // UNDEF _DefineIdentsToken

/* =---- Keyword Tokens ----------------------------------------= */

#ifndef _DefineContext
/// @brief Placeholder definition of _DefineContext macro.
#   define _DefineContext(name, value)
#endif // _DefineContext

/// @brief Expression context: keywords enabled in this context are
///        valid in every expression of the language, but not in
///        statements and declarations.
_DefineContext(CTX_EXPRS, 0x0010)
/// @brief Type expression context: keywords enabled in this context
///        are valid only in type expressions.
_DefineContext(CTX_TEXPR, 0x0020)
/// @brief Declaration context: keywords enabled in this context are
///        valid only in declarations.
_DefineContext(CTX_DECLR, 0x0100)
/// @brief Type declaration context: keywords enabled in this context
///        are valid only in type declarations.
_DefineContext(CTX_TDECL, 0x0200)
/// @brief Object definition context: keywords enabled in this context
///        are valid only in objects definitions.
_DefineContext(CTX_OBJCT, 0x0700)
/// @brief Template defition context: keywords enabled in this context
///        are valid only in templates definitions (and declarations).
_DefineContext(CTX_TEMPL, 0x0800)
/// @brief Statement context: keywords enabled in this context are valid
///        in each statement of the language, but not in expressions,
///        declarations and pragmatic statements.
_DefineContext(CTX_STMNT, 0x1000)

#ifdef _DefineContext
#   undef _DefineContext
#endif // UNDEF _DefineContext

#ifndef _DefineKwordToken
/// @brief Internal macro for keyword tokens defintion.
#   define _DefineKwordToken(name, lexeme) _DefineToken(name) _DefineLexeme(name, "<kword name=\"" lexeme "\"/>", lexeme)
#endif // _DefineKwordToken

/// @brief 'abstract' keyword token.
_DefineKwordToken(KWORD_ABSTRACT,                              "abstract")
/// @brief 'auto' keyword token.
_DefineKwordToken(KWORD_AUTO,                                  "auto")
/// @brief 'bool' keyword token.
_DefineKwordToken(KWORD_BOOL,                                  "bool")
/// @brief 'break' keyword token.
_DefineKwordToken(KWORD_BREAK,                                 "break")
/// @brief 'call' keyword token.
_DefineKwordToken(KWORD_CALL,                                  "call")              // ?
/// @brief 'case' keyword token.
_DefineKwordToken(KWORD_CASE,                                  "case")
/// @brief 'char' keyword token.
_DefineKwordToken(KWORD_CHAR,                                  "char")
/// @brief 'checked' keyword token.
_DefineKwordToken(KWORD_CHECKED,                               "checked")           // ?
/// @brief 'const' keyword token.
_DefineKwordToken(KWORD_CONST,                                 "const")
/// @brief 'continue' keyword token.
_DefineKwordToken(KWORD_CONTINUE,                              "continue")
/// @brief 'default' keyword token.
_DefineKwordToken(KWORD_DEFAULT,                               "default")
/// @brief 'do' keyword token.
_DefineKwordToken(KWORD_DO,                                    "do")
/// @brief 'else' keyword token.
_DefineKwordToken(KWORD_ELSE,                                  "else")
/// @brief 'end' keyword token.
_DefineKwordToken(KWORD_END,                                   "end")               // ?
/// @brief 'enum' keyword token.
_DefineKwordToken(KWORD_ENUM,                                  "enum")
/// @brief 'extern' keyword token.
_DefineKwordToken(KWORD_EXTERN,                                "extern")
/// @brief 'final' keyword token.
_DefineKwordToken(KWORD_FINAL,                                 "final")
/// @brief 'float' keyword token.
_DefineKwordToken(KWORD_FLOAT,                                 "float")
/// @brief 'for' keyword token.
_DefineKwordToken(KWORD_FOR,                                   "for")
/// @brief 'fn' keyword token.
_DefineKwordToken(KWORD_FN,                                    "fn")
/// @brief 'goto' keyword token.
_DefineKwordToken(KWORD_GOTO,                                  "goto")
/// @brief 'if' keyword token.
_DefineKwordToken(KWORD_IF,                                    "if")
/// @brief 'int' keyword token.
_DefineKwordToken(KWORD_INT,                                   "int")
/// @brief 'let' keyword token. (constant declaration)
_DefineKwordToken(KWORD_LET,                                   "let")
/// @brief 'match' keyword token.
_DefineKwordToken(KWORD_MATCH,                                 "match")             // ?
/// @brief 'module' keyword token.
_DefineKwordToken(KWORD_MODULE,                                "module")
/// @brief 'nameof' keyword token.
_DefineKwordToken(KWORD_NAMEOF,                                "nameof")
/// @brief 'object' keyword token.
_DefineKwordToken(KWORD_OBJECT,                                "object")
/// @brief 'override' keyword token.
_DefineKwordToken(KWORD_OVERRIDE,                              "override")          // ?
/// @brief 'pragma' keyword token.
_DefineKwordToken(KWORD_PRAGMA,                                "pragma")
/// @brief 'private' keyword token.
_DefineKwordToken(KWORD_PRIVATE,                               "private")
/// @brief 'protected' keyword token.
_DefineKwordToken(KWORD_PROTECTED,                             "protected")
/// @brief 'public' keyword token.
_DefineKwordToken(KWORD_PUBLIC,                                "public")
/// @brief 'real' keyword token.
_DefineKwordToken(KWORD_REAL,                                  "real")
/// @brief 'return' keyword token.
_DefineKwordToken(KWORD_RETURN,                                "return")
/// @brief 'signed' keyword token.
_DefineKwordToken(KWORD_SIGNED,                                "signed")
/// @brief 'sizeof' keyword token.
_DefineKwordToken(KWORD_SIZEOF,                                "sizeof")
/// @brief 'static' keyword token.
_DefineKwordToken(KWORD_STATIC,                                "static")
/// @brief 'struct' keyword token.
_DefineKwordToken(KWORD_STRUCT,                                "struct")
/// @brief 'switch' keyword token.
_DefineKwordToken(KWORD_SWITCH,                                "switch")
/// @brief 'type' keyword token.
_DefineKwordToken(KWORD_TYPE,                                  "type")
/// @brief 'typeof' keyword token.
_DefineKwordToken(KWORD_TYPEOF,                                "typeof")
/// @brief 'undef' keyword token.
_DefineKwordToken(KWORD_UNDEF,                                 "undef")             // ?
/// @brief 'union' keyword token.
_DefineKwordToken(KWORD_UNION,                                 "union")
/// @brief 'unsigned' keyword token.
_DefineKwordToken(KWORD_UNSIGNED,                              "unsigned")
/// @brief 'use' keyword token.
_DefineKwordToken(KWORD_USE,                                   "use")
/// @brief 'void' keyword token.
_DefineKwordToken(KWORD_VOID,                                  "void")
/// @brief 'while' keyword token.
_DefineKwordToken(KWORD_WHILE,                                 "while")
/// @brief 'with' keyword token.
_DefineKwordToken(KWORD_WITH,                                  "with")              // ?

#ifndef CALC_CONTXT_KEYWORDS
/// @brief If its value is 1, keywords have a specific context
///        where they're keywords, so in other contexts some
///        keywords can be used as identifiers. To disable
///        keywords contextualization, set this macro to zero.
#   define CALC_CONTXT_KEYWORDS 0                                                   // contexts are disabled
#endif // CALC_CONTXT_KEYWORDS

#ifndef CALC_SORTED_KEYWORDS
/// @brief If its value is 1, keywords are in alphabetical
///        order. If keywords are not sorted, set this macro
///        to zero.
#   define CALC_SORTED_KEYWORDS 1
#endif // CALC_SORTED_KEYWORDS

#ifdef _DefineKwordToken
#   undef _DefineKwordToken
#endif // UNDEF _DefineKwordToken

/* =---- Pragmatic Keyword Tokens ------------------------------= */

#ifndef _DefinePragmToken
/// @brief Internal macro for pragmatic tokens defintion.
#   define _DefinePragmToken(name, lexeme) _DefineToken(PRAGM_ ## name) _DefineLexeme(PRAGM_ ## name, "<pragm name=\"" lexeme "\"/>", lexeme)
#endif // _DefinePragmToken

// TODO...

#ifndef CALC_SORTED_PRAGMATICS
/// @brief If its value is 1, pragmatics are in alphabetical
///        order. If pragmatics are not sorted, set this macro
///        to zero.
#   define CALC_SORTED_PRAGMATICS 1
#endif // CALC_SORTED_PRAGMATICS

#ifdef _DefinePragmToken
#   undef _DefinePragmToken
#endif // UNDEF _DefinePragmToken

/* =---- Punctuation Tokens ------------------------------------= */

#ifndef _DefinePunctToken
/// @brief Internal macro for keyword tokens defintion.
#   define _DefinePunctToken(name, lexeme) _DefineToken(PUNCT_ ## name) _DefineLexeme(PUNCT_ ## name, "<punct name=\"" # name "\"/>", lexeme)
#endif // _DefinePunctToken

// Brackets

/// @brief '(' stray bracket token. (left round bracket)
_DefinePunctToken(LROUN,                                       "(")
/// @brief ')' stray bracket token. (rigth round bracket)
_DefinePunctToken(RROUN,                                       ")")
/// @brief '[' stray bracket token. (left square bracket)
_DefinePunctToken(LSQRD,                                       "[")
/// @brief ']' stray bracket token. (right square bracket)
_DefinePunctToken(RSQRD,                                       "]")
/// @brief '(' stray bracket token. (left curly bracket)
_DefinePunctToken(LCURL,                                       "{")
/// @brief '(' stray bracket token. (rigth curly bracket)
_DefinePunctToken(RCURL,                                       "}")

// Composed Brackets

/// @brief '()' composed bracket token. (round brackets)
_DefinePunctToken(ROUND,                                       "()")
/// @brief '[]' composed bracket token. (square brackets)
_DefinePunctToken(SQRED,                                       "[]")
/// @brief '{}' composed bracket token. (curly brackets)
_DefinePunctToken(CURLY,                                       "{}")

// Stray Punctuators

/// @brief '~' stray punctuator token. (tilde)
_DefinePunctToken(TILDE,                                       "~")

/// @brief '?' stray punctuator token. (question mark)
_DefinePunctToken(QUEST,                                       "?")
/// @brief '!' stray punctuator token. (exclamation mark)
_DefinePunctToken(EXCLM,                                       "!")
/// @brief '&' stray punctuator token. (ampersand)
_DefinePunctToken(AMPER,                                       "&")
/// @brief '|' stray punctuator token. (pipe)
_DefinePunctToken(PIPEE,                                       "|")
/// @brief '^' stray punctuator token. (caret)
_DefinePunctToken(CARET,                                       "^")

/// @brief '<' stray punctuator token. (less than)
_DefinePunctToken(LESST,                                       "<")
/// @brief '>' stray punctuator token. (greater than)
_DefinePunctToken(GREAT,                                       ">")
/// @brief '=' stray punctuator token. (equal)
_DefinePunctToken(EQUAL,                                       "=")

/// @brief '+' stray punctuator token. (plus)
_DefinePunctToken(PLUSS,                                       "+")
/// @brief '-' stray punctuator token. (minus)
_DefinePunctToken(MINUS,                                       "-")
/// @brief '*' stray punctuator token. (asterisk)
_DefinePunctToken(STARR,                                       "*")
/// @brief '/' stray punctuator token. (slash)
_DefinePunctToken(SLASH,                                       "/")
/// @brief '%' stray punctuator token. (percent)
_DefinePunctToken(PERCN,                                       "%")

/// @brief '#' stray punctuator token. (hash)
_DefinePunctToken(SHARP,                                       "#")
/// @brief '@' stray punctuator token. (at)
_DefinePunctToken(ATSIG,                                       "@")

/// @brief ',' stray punctuator token. (comma)
_DefinePunctToken(COMMA,                                       ",")
/// @brief '.' stray punctuator token. (dot)
_DefinePunctToken(POINT,                                       ".")
/// @brief ':' stray punctuator token. (colon)
_DefinePunctToken(COLON,                                       ":")
/// @brief ';' stray punctuator token. (semicolon)
_DefinePunctToken(SEMIC,                                       ";")

/// @brief '\' stray punctuator token. (backslash)
_DefinePunctToken(BACKS,                                       "\\")
/// @brief '`' stray punctuator token. (backtick)
_DefinePunctToken(BACKT,                                       "`")

// Composed Tokens - Doubled

/// @brief '??' composed punctuator token.
_DefinePunctToken(QUEST_QUEST,                                 "??")
/// @brief '!!' composed punctuator token.
_DefinePunctToken(EXCLM_EXCLM,                                 "!!")
/// @brief '&&' composed punctuator token.
_DefinePunctToken(AMPER_AMPER,                                 "&&")
/// @brief '||' composed punctuator token.
_DefinePunctToken(PIPEE_PIPEE,                                 "||")

/// @brief '<<' composed punctuator token.
_DefinePunctToken(LESST_LESST,                                 "<<")
/// @brief '>>' composed punctuator token.
_DefinePunctToken(GREAT_GREAT,                                 ">>")
/// @brief '==' composed punctuator token.
_DefinePunctToken(EQUAL_EQUAL,                                 "==")

/// @brief '++' composed punctuator token.
_DefinePunctToken(PLUSS_PLUSS,                                 "++")
/// @brief '--' composed punctuator token.
_DefinePunctToken(MINUS_MINUS,                                 "--")

/// @brief '..' composed punctuator token.
_DefinePunctToken(POINT_POINT,                                 "..")
/// @brief '::' composed punctuator token.
_DefinePunctToken(COLON_COLON,                                 "::")

// Composed Tokens - Equal

/// @brief '?=' composed punctuator token.
_DefinePunctToken(QUEST_EQUAL,                                 "?=")
/// @brief '!=' composed punctuator token.
_DefinePunctToken(EXCLM_EQUAL,                                 "!=")
/// @brief '&=' composed punctuator token.
_DefinePunctToken(AMPER_EQUAL,                                 "&=")
/// @brief '|=' composed punctuator token.
_DefinePunctToken(PIPEE_EQUAL,                                 "|=")
/// @brief '^=' composed punctuator token.
_DefinePunctToken(CARET_EQUAL,                                 "^=")

/// @brief '<=' composed punctuator token.
_DefinePunctToken(LESST_EQUAL,                                 "<=")
/// @brief '>=' composed punctuator token.
_DefinePunctToken(GREAT_EQUAL,                                 ">=")

/// @brief '<<=' composed punctuator token.
_DefinePunctToken(LESST_LESST_EQUAL,                           "<<=")
/// @brief '>>=' composed punctuator token.
_DefinePunctToken(GREAT_GREAT_EQUAL,                           ">>=")

/// @brief '+=' composed punctuator token.
_DefinePunctToken(PLUSS_EQUAL,                                 "+=")
/// @brief '-=' composed punctuator token.
_DefinePunctToken(MINUS_EQUAL,                                 "-=")
/// @brief '*=' composed punctuator token.
_DefinePunctToken(STARR_EQUAL,                                 "*=")
/// @brief '/=' composed punctuator token.
_DefinePunctToken(SLASH_EQUAL,                                 "/=")
/// @brief '%=' composed punctuator token.
_DefinePunctToken(PERCN_EQUAL,                                 "%=")

// Composed Tokens

/// @brief '?.' composed punctuator token.
_DefinePunctToken(QUEST_POINT,                                 "?.")

/// @brief '->' composed punctuator token. (arrow)
_DefinePunctToken(ARROW,                                       "->")
/// @brief '=>' composed punctuator token. (then arrow)
_DefinePunctToken(THENN,                                       "=>")
/// @brief '<>' composed punctuator token. (equivalence arrow)
_DefinePunctToken(EQVLN,                                       "<>")

/// @brief '...' composed punctuator token. (ellipsis)
_DefinePunctToken(ELLIP,                                       "...")

#ifdef _DefinePunctToken
#   undef _DefinePunctToken
#endif // UNDEF _DefinePunctToken

/* =---- Constant Literal Tokens -------------------------------= */

#ifndef _DefineLiterToken
/// @brief Internal macro for keyword tokens defintion.
#   define _DefineLiterToken(name, text) _DefineToken(LITER_ ## name, NULL) _DefineLexeme(LITER_ ## name, text)
#endif // _DefineLiterToken

// Numeric Literals

// TODO...

#ifdef _DefineLiterToken
#   undef _DefineLiterToken
#endif // UNDEF _DefineLiterToken

/* =------------------------------------------------------------= */

#ifdef _DefineLexeme
#   undef _DefineLexeme
#endif // UNDEF _DefineLexeme

#ifdef _DefineToken
#   undef _DefineToken
#endif // UNDEF _DefineToken

#ifdef _Expand
#   undef _Expand
#endif // UNDEF _Expand

#ifndef MATHIC_LEX_TOKENS_INC_
/// @brief This header is inlcuded at least one time.
#   define MATHIC_LEX_TOKENS_INC_
#endif // MATHIC_LEX_TOKENS_INC_
