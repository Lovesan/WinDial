#ifndef __WIN_DIAL_H__
#define __WIN_DIAL_H__

#include <windows.h>

#define WIN_DIAL_VERSION "0.1.0.0"
#define WIN_DIAL_VERNUM 0x0100
#define WIN_DIAL_MAJOR 0
#define WIN_DIAL_MINOR 1
#define WIN_DIAL_REVISION 0
#define WIN_DIAL_BUILD 0

#ifdef __cplusplus
#define WIN_DIAL_EXTERN extern "C"
#else
#define WIN_DIAL_EXTERN
#endif

WIN_DIAL_EXTERN BOOL WinDialFindConnection(LPCWSTR name);

WIN_DIAL_EXTERN BOOL WinDialOpenConnection(LPCWSTR name);

WIN_DIAL_EXTERN BOOL WinDialCloseConnection(LPCWSTR name);

#endif // __WIN_DIAL_H__
