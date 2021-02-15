#pragma once

//#define ENG_PLATFORM_WINDOWS
//#define ENG_BUILD_DLL

#ifdef ENG_PLATFORM_WINDOWS
	#ifdef ENG_BUILD_DLL
		#define ENG_API __declspec(dllexport)
	#else
		#define ENG_API __declspec(dllimport)
	#endif
#endif