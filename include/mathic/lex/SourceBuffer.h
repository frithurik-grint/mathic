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

        char peekChar(int offset = 0) const noexcept;
        char readChar(int offset = 0) noexcept;

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

        inline const char *getName() const noexcept
        {
            return this->_name.get();
        }

        inline size_t getBufferSize() const noexcept
        {
            return this->_length;
        }

        inline unsigned int getLine() const noexcept
        {
            return this->_lnBegin;
        }

        inline unsigned int getColumn() const noexcept
        {
            return this->_coBegin;
        }

        inline bool enableSkipWhiteSpaces() noexcept
        {
            return this->_skipWS = true;
        }

        inline bool isAtEOF() const noexcept
        {
            return this->_pFrwrd == this->_length;
        }
    };
}

#endif // MATHIC_LEX_SOURCE_BUFFER_H_
