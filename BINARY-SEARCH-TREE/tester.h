#include <iostream>

int TotalAsserts = 18;
int TrueAsserts = 0;

#ifndef NDEBUG
#   define ASSERT(condition, message, w) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
        } \
        else { \
            TrueAsserts+=w; \
        } \
        std::cerr <<"Success "<< TrueAsserts << "/" << TotalAsserts <<std::endl; \
    } while (false)
#else
#   define ASSERT(condition, message, w) do { } while (false)
#endif