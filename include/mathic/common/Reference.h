#pragma once

/* MIT License - Copyright (c) 2024 Frithurik Grint */

#ifndef MATHIC_COMMON_REFERENCE_H_
#define MATHIC_COMMON_REFERENCE_H_

#include <type_traits>

namespace Mathic
{
    template <typename T> class Reference
    {
        T *_ptr = nullptr;

    protected:
        inline Reference(const T *const value) :
            _ptr((std::remove_const_t<T> *)value)
        {
        }

        inline Reference(T *const value) :
            _ptr(value)
        {
        }

        // Methods

        inline T *const get_ptr() const noexcept
        {
            return this->_ptr;
        }

        inline T *const set_ptr(T *const value) noexcept
        {
            return this->_ptr = value;
        }

    public:
        inline Reference(const T &value) :
            _ptr((std::remove_const_t<T> *)&value)
        {
        }

        inline Reference(T &value) :
            _ptr(&value)
        {
        }

        inline Reference(const Reference &other) :
            _ptr(other._ptr)
        {
        }

        inline Reference(Reference &other) :
            _ptr(other._ptr)
        {
        }

        // Methods

        inline T &get() const noexcept
        {
            return *this->_ptr;
        }

        // Operators

        inline Reference &operator=(const Reference &that)
        {
            return this->_ptr = that->_ptr, *this;
        }

        inline Reference &operator=(Reference &&that)
        {
            return this->_ptr = that->_ptr, *this;
        }

        inline T &operator->() const noexcept
        {
            return this->_ptr;
        }

        inline T &operator*() const noexcept
        {
            return this->_ptr;
        }

        inline bool operator==(std::add_const_t<T> &that) const noexcept
        {
            return (this->_ptr == &that) || (*this->_ptr == that);
        }

        inline bool operator!=(std::add_const_t<T> &that) const noexcept
        {
            return (this->_ptr != &that) && (*this->_ptr != that);
        }

        inline bool operator==(const Reference<T> &that) const noexcept
        {
            return (this->_ptr == that->_ptr) || (*this->_ptr == *that->_ptr);
        }

        inline bool operator!=(const Reference<T> &that)
        {
            return (this->_ptr != that->_ptr) && (*this->_ptr != *that->_ptr);
        }

        // Implicit Conversions

        inline operator std::conditional_t<std::is_const_v<T>, T &, void>() const noexcept
        {
            if constexpr (std::is_const_v<T>)
                return this->_ptr;
            else
                return;
        }
    };

    // Wrapper

    template <typename T> static inline Reference<T> *wrap(const T &value)
    {
        return new Reference<T>(value);
    }

    template <typename T> inline Reference<T> *wrap(T &value)
    {
        return new Reference<T>(value);
    }

    // Unwrapper

    template <typename T> static inline T &unwrap(Reference<T> *const ref, bool deleteIt = true)
    {
        T &result = ref->get();

        if (deleteIt)
            delete ref;

        return result;
    }
}

#endif // MATHIC_COMMON_REFERENCE_H_
