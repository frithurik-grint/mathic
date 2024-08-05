#pragma once

/* MIT License - Copyright (c) 2024 Frithurik Grint */

#ifndef MATHIC_COMMON_SOURCE_BUFFER_H_
#define MATHIC_COMMON_SOURCE_BUFFER_H_

#include "mathic/common/UniqueReference.h"

#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/MemoryBufferRef.h"

#include <memory>
#include <string>

namespace Mathic
{
    class SourceBuffer
    {
        UniqueReference<std::string> _name;

        const char *_buff = nullptr;

    private:
        inline SourceBuffer(const std::string &name, llvm::MemoryBufferRef memBuf) :
            _name(name), _buff(memBuf.getBufferStart())
        {
        }

    public:
        inline SourceBuffer(const std::string &name) :
            _name(name)
        {
        }

        // Static Methods

        static auto OpenStandardInput()
            -> SourceBuffer;
    };
}

#endif // MATHIC_COMMON_SOURCE_BUFFER_H_
