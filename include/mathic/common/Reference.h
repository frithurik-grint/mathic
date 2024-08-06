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

        inline auto getPtr() const noexcept
            -> std::add_const_t<T> *const
        {
            return (std::add_const_t<T> *const)this->_ptr;
        }

        inline auto setPtr(T *const value) noexcept
            -> std::add_const_t<T> *const
        {
            return (std::add_const_t<T> *const)this->_ptr = value;
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

        inline auto get() const noexcept
            -> T &
        {
            return *this->_ptr;
        }

        // Operators

        inline auto operator=(const Reference &that)
            -> Reference &
        {
            return this->_ptr = that->_ptr, *this;
        }

        inline auto operator=(Reference &&that)
            -> Reference &
        {
            return this->_ptr = that->_ptr, *this;
        }

        inline auto operator->() const noexcept
            -> T &
        {
            return this->_ptr;
        }

        inline auto operator*() const noexcept
            -> T &
        {
            return this->_ptr;
        }

        inline auto operator==(std::add_const_t<T> &that) const noexcept
            -> bool
        {
            return (this->_ptr == &that) || (*this->_ptr == that);
        }

        inline auto operator!=(std::add_const_t<T> &that) const noexcept
            -> bool
        {
            return (this->_ptr != &that) && (*this->_ptr != that);
        }

        inline auto operator==(const Reference<T> &that) const noexcept
            -> bool
        {
            return (this->_ptr == that->_ptr) || (*this->_ptr == *that->_ptr);
        }

        inline auto operator!=(const Reference<T> &that) const noexcept
            -> bool
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

    template <typename T> static inline auto wrap(const T &value)
        -> Reference<T> *
    {
        return new Reference<T>(value);
    }

    template <typename T> static inline auto wrap(T &value)
        -> Reference<T> *
    {
        return new Reference<T>(value);
    }

    // Unwrapper

    template <typename T> static inline auto unwrap(Reference<T> *const ref, bool deleteIt = true)
        -> T &
    {
        T &result = ref->get();

        if (deleteIt)
            delete ref;

        return result;
    }
}

#endif // MATHIC_COMMON_REFERENCE_H_
