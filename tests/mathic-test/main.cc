#include "mathic/lex/SourceBuffer.h"
//#include "mathic/lex/Tokens.h"

#include <iostream>

using namespace Mathic;

int main()
{
    const char *const tags[] =
    {
#pragma push_macro("_DefineLexeme")

#ifndef _DefineLexeme
#   define _DefineLexeme(name, text, lexeme) text,
#endif // _DefineLexeme

#include "mathic/lex/Tokens.inc"

#ifdef _DefineLexeme
#   undef _DefineLexeme
#endif // UNDEF _DefineLexeme

#pragma pop_macro("_DefineLexeme")

        NULL
    };

    char **c = (char **)tags;

    while (*c)
        std::printf("%s\n", *(c++));

    return 0;
}