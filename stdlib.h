#ifndef STDLIB_H
#define STDLIB_H
typedef enum {
    false = 0,
    true = 1
} bool;
#define NULL ((void*)0)
typedef unsigned char uint8;
typedef signed char int8;

typedef unsigned short uint16;
typedef signed short int16;

typedef unsigned long uint32;
typedef signed long int32;

typedef unsigned long long uint64;
typedef signed long long int64;

#ifdef __x86_64__
    typedef uint64 size_t;
#else
    typedef uint32 size_t;
#endif
 
#define min(a, b)  (((a) > (b)) ? (b) : (a))
#define max(a, b)  (((a) > (b)) ? (b) : (a))

#endif
