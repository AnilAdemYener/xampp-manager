#ifndef header
#define header

/*

this header includes header files
according to os

example:
gnu+linux --> src/linux/l_main.h
windows --> src/windows/w_main.h
global --> src/global/g_main.h

*/

#include "../global/g_main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

behind the defines && includes
==============================
#define OS <operating system>
#include <os>_header.h ==> for header files
#include ../<os>/<os>_main.h ==> for function files

*/

/*

Note
====
    __linux__       Defined on Linux
    __sun           Defined on Solaris
    __FreeBSD__     Defined on FreeBSD
    __NetBSD__      Defined on NetBSD
    __OpenBSD__     Defined on OpenBSD
    __APPLE__       Defined on Mac OS X
    __hpux          Defined on HP-UX
    __osf__         Defined on Tru64 UNIX (formerly DEC OSF1)
    __sgi           Defined on Irix
    _AIX            Defined on AIX

*/

#ifdef __linux__
	#define OS "linux"
	#include "l_header.h"
	#include "../linux/l_main.h"
#elif _WIN32
	#define OS "windows"
	#include "w_header.h"
	#include "../windows/w_main.h"
#else
	#define OS "unknown"
#endif

#endif // header
