#pragma once

/* MIT License - Copyright (c) 2024 Frithurik Grint */

#ifndef MATHIC_LEX_TOKENS_H_
#define MATHIC_LEX_TOKENS_H_

#include "mathic/lex/SourceBuffer.h"

namespace Mathic::Lex
{
    enum TokenCode
    {
        TOK_INVAL = 0,

#pragma push_macro("_DefineToken")

#ifndef _DefineToken
#   define _DefineToken(tokName) TOK_ ## tokName,
#endif // _DefineToken

#include "mathic/lex/Tokens.inc"

#ifdef _DefineToken
#   undef _DefineToken
#endif // UNDEF _DefineToken

#pragma pop_macro("_DefineToken")
    };

    auto getTokenToString(TokenCode code)
        -> const char *const;

    auto getTokenCodeName(TokenCode code)
        -> const char *const;

    class Token // class to store token infos
    {
        
    };
}

#endif // MATHIC_LEX_TOKENS_H_
