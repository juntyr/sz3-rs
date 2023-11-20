#ifndef _DEF_HPP
#define _DEF_HPP

#include <cmath>
#include <cstdint>

#if defined(__wasm__)
    #include <cstdlib>
    #include <new>
#endif // defined(__wasm__)

namespace SZ3 {

    typedef unsigned int uint;
    typedef unsigned char uchar;

}

#if defined(__wasm__)
    extern "C" void __cxa_pure_virtual() { abort(); }
    extern "C" void __cxa_allocate_exception() { abort(); }
    extern "C" void __cxa_throw() { abort(); }
    extern "C" unsigned int __cxa_uncaught_exceptions() { return 0; }

    void* operator new(std::size_t n)
    {
        return std::malloc(n);
    }

    void* operator new[](std::size_t n)
    {
        return std::malloc(n);
    }

    void* operator new(std::size_t n, std::align_val_t a)
    {
        return std::aligned_alloc(static_cast<std::size_t>(a), n);
    }

    void operator delete(void* p) noexcept
    {
        std::free(p);
    }

    void operator delete[](void* p) noexcept
    {
        std::free(p);
    }

    void operator delete(void* p, std::align_val_t a) noexcept
    {
        std::free(p);
    }
#endif // defined(__wasm__)

#endif
