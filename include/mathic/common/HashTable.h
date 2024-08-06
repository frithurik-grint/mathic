#pragma once

/* MIT License - Copyright (c) 2024 Frithurik Grint */

#ifndef MATHIC_COMMON_HASH_TABLE_H_
#define MATHIC_COMMON_HASH_TABLE_H_

#include "llvm/ADT/StringMap.h"

namespace Mathic
{
    template <typename TVal> class HashTable :
        public llvm::StringMap<TVal>
    {
    public:
        inline HashTable(std::size_t capacity) :
            llvm::StringMap<TVal>(capacity)
        {
        }

        // Methods

        inline auto add(llvm::StringRef key, TVal value)
            -> decltype(this->insert({ key, value }))
        {
            return this->insert({ key, value });
        }
    };
}

#endif // MATHIC_COMMON_HASH_TABLE_H_
