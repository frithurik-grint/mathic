#include "mathic/common/SourceBuffer.h"

namespace Mathic
{
    char SourceBuffer::peekChar(int offset) const noexcept
    {
        char c;

        if ((this->_pFrwrd + offset) < this->_length)
            c = this->_buffer[this->_pFrwrd + offset - 1];
        else
            c = NUL;

        return c;
    }

    char SourceBuffer::readChar(int offset) noexcept
    {
        char c;

        do
        {
            if ((this->_pFrwrd + offset) < this->_length)
                c = this->_buffer[(this->_pFrwrd++) + offset];
            else
                c = NUL;

            if (c == EOL)
                ++this->_lnFrwrd, this->_coFrwrd = 0;
            else
                ++this->_coFrwrd;
        } while (this->_skipWS && std::isspace(c));

        return c;
    }
}
