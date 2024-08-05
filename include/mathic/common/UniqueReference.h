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
            Reference<T>(other.get_ptr())
        {
            other.set_ptr(nullptr);
        }

        inline UniqueReference(UniqueReference &other) :
            Reference<T>(other.get_ptr())
        {
            other.set_ptr(nullptr);
        }

        // Operators

        inline UniqueReference &operator=(const UniqueReference &that)
        {
            return this->set_ptr(that->get_ptr()), that->set_ptr(nullptr), *this;
        }

        inline UniqueReference &operator=(UniqueReference &&that)
        {
            return this->set_ptr(that->get_ptr()), that->set_ptr(nullptr), *this;
        }
    };

    // Wrapper

    template <typename T> UniqueReference<T> *wrap_unique(const T &value)
    {
        return new UniqueReference<T>(value);
    }

    template <typename T> UniqueReference<T> *wrap_unique(T &value)
    {
        return new UniqueReference<T>(value);
    }
}

#endif // MATHIC_COMMON_UNIQUE_REFERENCE_H_
