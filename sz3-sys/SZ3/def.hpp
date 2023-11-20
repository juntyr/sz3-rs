#ifndef _DEF_HPP
#define _DEF_HPP

#include <cmath>
#include <cstdint>

#if defined(__wasm__)
    #include <cstdlib>
    #include <new>
    #include <stdexcept>
    #include <cstdio>
#endif // defined(__wasm__)

namespace SZ3 {

    typedef unsigned int uint;
    typedef unsigned char uchar;

}

#if defined(__wasm__)
    extern "C" void __cxa_pure_virtual() { printf("__cxa_pure_virtual\n"); abort(); }
    extern "C" void __cxa_allocate_exception() { printf("__cxa_allocate_exception\n"); abort(); }
    extern "C" void __cxa_throw() { printf("__cxa_throw\n"); abort(); }
    extern "C" unsigned int __cxa_uncaught_exceptions() { printf("__cxa_uncaught_exceptions\n"); return 0; }

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

    std::length_error::~length_error() { printf("std::length_error::~length_error()\n"); abort(); }
    std::bad_array_new_length::bad_array_new_length() noexcept { printf("std::bad_array_new_length::bad_array_new_length()\n"); abort(); }
    std::bad_array_new_length::~bad_array_new_length() { printf("std::bad_array_new_length::~bad_array_new_length()\n"); abort(); }
    std::exception::~exception() { printf("std::exception::~exception()\n"); abort(); }
    std::bad_alloc::bad_alloc() noexcept { printf("std::bad_alloc::bad_alloc()\n"); abort(); }
    const char* std::logic_error::what() const noexcept { printf("std::logic_error::what()\n"); abort(); }
    const char* std::bad_array_new_length::what() const noexcept { printf("std::bad_array_new_length::what()\n"); abort(); }
    const char* std::exception::what() const noexcept { printf("std::exception::what()\n"); abort(); }
#endif // defined(__wasm__)

#endif
