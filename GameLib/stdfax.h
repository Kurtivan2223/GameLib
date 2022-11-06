#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifdef _WIN32
	#include <Windows.h>
#endif

#define DLLEXPORT __declspec(dllexport)
#define EXTERN_DLL_EXPORT extern "C" __declspec(dllexport)
#include <iostream>