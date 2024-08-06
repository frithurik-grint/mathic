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
        inline HashTable() :
            llvm::StringMap<TVal>()
        {
        }

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

        template <typename... TInit> inline auto init(llvm::StringRef key, TInit &&...initVals)
            -> bool
        {
            return this->insert(llvm::StringMapEntry<TVal>::create(key, this->getAllocator(), std::forward<TInit>(initVals)...));
        }
    };
}

#endif // MATHIC_COMMON_HASH_TABLE_H_
