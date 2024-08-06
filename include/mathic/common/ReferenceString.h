#pragma once

/* MIT License - Copyright (c) 2024 Frithurik Grint */

#ifndef MATHIC_COMMON_REFERENCE_STRING_H_
#define MATHIC_COMMON_REFERENCE_STRING_H_

#include "mathic/common/Reference.h"

#include <string>

namespace Mathic
{
    class ReferenceString :
        public Reference<char>
    {
        std::size_t _size;

    public:
        inline ReferenceString(const char *const cstr) :
            _size(std::strlen(cstr)), Reference<char>(cstr)
        {
        }

        inline ReferenceString(char *const cstr) :
            _size(std::strlen(cstr)), Reference<char>(cstr)
        {
        }

        inline ReferenceString(const std::string &str) :
            _size(str.size()), Reference<char>(str.c_str())
        {
        }

        inline ReferenceString(std::string &str) :
            _size(str.size()), Reference<char>(str.c_str())
        {
        }

        // Fields

        static inline auto getEmpty()
            -> ReferenceString
        {
            return ReferenceString((char *const)nullptr);
        }

        // Methods

        inline auto getSize() const noexcept
            -> const std::size_t
        {
            return (const std::size_t)this->_size;
        }

        inline auto getString() const noexcept
            -> std::string
        {
            return std::string(this->getPtr(), this->getSize());
        }
    };
}

#endif // MATHIC_COMMON_REFERENCE_STRING_H_
