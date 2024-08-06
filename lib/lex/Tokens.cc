#include "mathic/lex/Tokens.h"

namespace Mathic::Lex
{
    auto getTokenToString(TokenCode code)
        -> const char *const
    {
        switch (code)
        {
        default:
        case TOK_INVAL:
            return "\?\?\?";

#pragma push_macro("_DefineLexeme")

#ifndef _DefineLexeme
#   define _DefineLexeme(name, text, lexeme) case TOK_ ## name: \
                                                 return lexeme;
#endif // _DefineLexeme

#include "mathic/lex/Tokens.inc"

#ifdef _DefineLexeme
#   undef _DefineLexeme
#endif // UNDEF _DefineLexeme

#pragma pop_macro("_DefineLexeme")
        }
    }

    static auto getTokenCodeName(TokenCode &code)
        -> const char *const
    {
        switch (code)
        {
        default:
        case TOK_INVAL:
            return "\?\?\?";

#pragma push_macro("_DefineLexeme")

#ifndef _DefineLexeme
#   define _DefineLexeme(name, text, lexeme) case TOK_ ## name: \
                                                 return # name;
#endif // _DefineLexeme

#include "mathic/lex/Tokens.inc"

#ifdef _DefineLexeme
#   undef _DefineLexeme
#endif // UNDEF _DefineLexeme

#pragma pop_macro("_DefineLexeme")
        }
    }
}
