
#pragma once 

#define UNICODE
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace wcl::core {
    struct MenuHandle {
        HMENU hMenu = NULL;
    };
}
