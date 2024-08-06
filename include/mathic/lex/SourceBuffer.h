#pragma once

/* MIT License - Copyright (c) 2024 Frithurik Grint */

#ifndef MATHIC_LEX_SOURCE_BUFFER_H_
#define MATHIC_LEX_SOURCE_BUFFER_H_

#include "mathic/common/UniqueReference.h"

#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/MemoryBufferRef.h"

#include <memory>
#include <string>

namespace Mathic
{
    static const char NUL = '\0';
    static const char EOL = '\n';

    class SourceBuffer
    {
        UniqueReference<const char *> _name;

        const char *_buffer;

        size_t _length;
        size_t _pBegin = 0;
        size_t _pFrwrd = 0;

        unsigned int _lnBegin = 0;
        unsigned int _coBegin = 0;
        unsigned int _lnFrwrd = 0;
        unsigned int _coFrwrd = 0;

        bool _skipWS = false;

    public:
        inline SourceBuffer(llvm::MemoryBufferRef memBuf) :
            _name(memBuf.getBufferIdentifier().str().c_str()), _buffer(memBuf.getBufferStart()), _length(memBuf.getBufferSize())
        {
        }

        inline SourceBuffer(const char *const name, const char *const buffer, size_t length) :
            _name(name), _buffer(buffer), _length(length)
        {
        }

        // Methods

        auto peekChar(int offset = 0) const noexcept
            -> char;

        auto readChar(int offset = 0) noexcept
            -> char;

        inline void advancePosition() noexcept
        {
            this->_pBegin = this->_pFrwrd;

            this->_coBegin = this->_coFrwrd;
            this->_lnBegin = this->_lnFrwrd;

            return;
        }

        inline void retreatPosition() noexcept
        {
            this->_pFrwrd = this->_pBegin;

            this->_coFrwrd = this->_coBegin;
            this->_lnFrwrd = this->_lnBegin;

            return;
        }

        inline auto getName() const noexcept
            -> const char *
        {
            return this->_name.get();
        }

        inline auto getSize() const noexcept
            -> std::size_t
        {
            return this->_length;
        }

        inline auto getLine() const noexcept
            -> unsigned int
        {
            return this->_lnBegin;
        }

        inline auto getColumn() const noexcept
            -> unsigned int
        {
            return this->_coBegin;
        }

        inline auto enableSkipWhiteSpaces() noexcept
            -> bool
        {
            return this->_skipWS = true;
        }

        inline auto isAtEOF() const noexcept
            -> bool
        {
            return this->_pFrwrd == this->_length;
        }
    };
}

#endif // MATHIC_LEX_SOURCE_BUFFER_H_
