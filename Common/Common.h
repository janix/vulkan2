#pragma once

#include "vulkan/vulkan.h"
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#define LIBRARY_TYPE HMODULE
#elif defined __linux
#include <dlfcn.h>
#define LIBRARY_TYPE void*
#endif