//
// Created by IBAÑES on 12/09/2023.
//

#ifndef DATA_STRUCTURE_TESTER_H
#define DATA_STRUCTURE_TESTER_H

#endif //DATA_STRUCTURE_TESTER_H
#include <iostream>

int TotalAsserts = 0;
int TrueAsserts = 0;

#ifndef NDEBUG
#   define ASSERT(condition, message) \
    do { \
        TotalAsserts++; \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
        } \
        else { \
            TrueAsserts++; \
        } \
        std::cerr <<"Success "<< TrueAsserts << "/" << TotalAsserts <<std::endl; \
    } while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif