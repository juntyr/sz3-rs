#ifndef _DEF_HPP
#define _DEF_HPP

#include <cmath>
#include <cstdlib>
#include <new>

namespace SZ {

    typedef unsigned int uint;
    typedef unsigned char uchar;

}

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

#endif
