#pragma once

#include "Logger.h"

#include <cstdlib>

#define YOKOSO_ASSERT(condition, message)                 \
    do                                                    \
    {                                                     \
        if (!(condition))                                 \
        {                                                 \
            Logger::Error(std::string("Assertion failed: ") + (message)); \
            std::abort();                                 \
        }                                                 \
    } while (0)