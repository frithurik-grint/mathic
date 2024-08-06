#include "mathic/lex/SourceBuffer.h"

#include <iostream>

using namespace Mathic;

int main()
{
    SourceBuffer src("test", "a = 1 + 4", 10);

    char c;

    do
        std::cout << (c = src.readChar());
    while (c);

    src.advancePosition();

    std::cout << std::endl << src.getColumn() << std::endl;

    return 0;
}