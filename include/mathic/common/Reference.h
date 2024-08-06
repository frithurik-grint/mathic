#pragma once

/* MIT License - Copyright (c) 2024 Frithurik Grint */

#ifndef MATHIC_COMMON_REFERENCE_H_
#define MATHIC_COMMON_REFERENCE_H_

#include <type_traits>
#include <utility>

namespace Mathic
{
    template <typename T> class Reference
    {
        T *_ptr = nullptr;

    protected:
        constexpr Reference(std::add_const_t<T> *const value) :
            _ptr((std::remove_const_t<T> *)value)
        {
        }

        constexpr Reference(T *const value) :
            _ptr(value)
        {
        }

        // Methods

        constexpr auto getPtr() const noexcept
            -> T *const
        {
            return this->_ptr;
        }

        constexpr auto setPtr(T *const value) noexcept
            -> T *const
        {
            return this->_ptr = value;
        }

        constexpr auto movPtr() noexcept
            -> T *const
        {
            return std::exchange<T *, std::nullptr_t>(this->_ptr, nullptr);
        }

        constexpr auto getConstPtr() const noexcept
            -> std::add_const_t<T> *const
        {
            return (std::add_const_t<T> *const)this->_ptr;
        }

        constexpr auto setConstPtr(std::add_const_t<T> *const value) noexcept
            -> std::add_const_t<T> *const
        {
            return this->_ptr = (T *const)value;
        }

        constexpr auto equals(const Reference<T> &that) const noexcept
            -> bool
        {
            return (this->getConstPtr() == that.getConstPtr()) || ((!!(this->getConstPtr()) && !!(that.getConstPtr())) && (*this->getConstPtr() == *that.getConstPtr()));
        }

    public:
        constexpr Reference()
            = default;

        constexpr Reference(const Reference<T> &other) noexcept :
            _ptr(other.getPtr())
        {
        }

        constexpr Reference(Reference<T> &other) noexcept :
            _ptr(other.getPtr())
        {
        }

        constexpr Reference(Reference<T> &&other) noexcept :
            _ptr(other.movPtr())
        {
        }

        constexpr Reference(const T &value) noexcept :
            _ptr((std::remove_const_t<T> *) &value)
        {
        }
        
        constexpr Reference(T &value) noexcept :
            _ptr(&value)
        {
        }

        // Methods

        constexpr auto get() const noexcept
            -> T &&
        {
            return static_cast<std::remove_reference_t<T> &&>(*this->getPtr());
        }

        constexpr auto move() noexcept
            -> Reference<T> &&
        {
            return static_cast<Reference<T> &&>(*this);
        }

        // Operators

        constexpr auto operator=(const Reference<T> &that) noexcept
            -> Reference<T> &
        {
            return this->setPtr(that.getPtr()), *this;
        }

        constexpr auto operator=(Reference<T> &that) noexcept
            -> Reference<T> &
        {
            return this->setPtr(that.getPtr()), *this;
        }

        constexpr auto operator=(Reference<T> &&that) noexcept
            ->Reference<T> &
        {
            return this->setPtr(that.movPtr()), *this;
        }

        constexpr auto operator*() const noexcept
            -> T &&
        {
            return this->get();
        }

        constexpr auto operator->() const noexcept
            -> T &&
        {
            return this->get();
        }

        constexpr auto operator==(const Reference<T> &that) const noexcept
            -> bool
        {
            return this->equals(that);
        }

        constexpr auto operator!=(const Reference<T> &that) const noexcept
            -> bool
        {
            return !(this == that);
        }

        constexpr auto operator==(std::add_const_t<T> &that) const noexcept
            -> bool
        {
            return (this->getConstPtr() == &that) || (*this->getConstPtr() == that);
        }

        constexpr auto operator!=(std::add_const_t<T> &that) const noexcept
            -> bool
        {
            return !(this == that);
        }
    };

    // Wrapper

    template <typename T> static inline auto wrap(std::add_const_t<T> &value)
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
