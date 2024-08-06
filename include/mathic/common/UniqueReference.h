#pragma once

/* MIT License - Copyright (c) 2024 Frithurik Grint */

#ifndef MATHIC_COMMON_UNIQUE_REFERENCE_H_
#define MATHIC_COMMON_UNIQUE_REFERENCE_H_

#include "mathic/common/Reference.h"

namespace Mathic
{
    template <typename T> class UniqueReference :
        public Reference<T>
    {
    public:
        inline UniqueReference(const T &value) :
            Reference<T>(value)
        {
        }

        inline UniqueReference(T &value) :
            Reference<T>(value)
        {
        }

        inline UniqueReference(const UniqueReference &other) :
            Reference<T>(other.getPtr())
        {
            other.setPtr(nullptr);
        }

        inline UniqueReference(UniqueReference &other) :
            Reference<T>(other.getPtr())
        {
            other.setPtr(nullptr);
        }

        // Operators

        inline auto operator=(const UniqueReference &that)
            -> UniqueReference &
        {
            return this->setPtr(that->getPtr()), that->setPtr(nullptr), *this;
        }

        inline auto operator=(UniqueReference &&that)
            -> UniqueReference &
        {
            return this->setPtr(that->getPtr()), that->setPtr(nullptr), *this;
        }
    };

    // Wrapper

    template <typename T> auto wrap_unique(const T &value)
        -> UniqueReference<T>
    {
        return new UniqueReference<T>(value);
    }

    template <typename T> auto wrap_unique(T &value)
        -> UniqueReference<T> *
    {
        return new UniqueReference<T>(value);
    }
}

#endif // MATHIC_COMMON_UNIQUE_REFERENCE_H_
