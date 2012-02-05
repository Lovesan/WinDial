// Copyright (C) 2012, Dmitry Ignatiev <lovesan.ru at gmail.com>
// 
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef __WIN_DIAL_H__
#define __WIN_DIAL_H__

#include <windows.h>

#define WIN_DIAL_VERSION "0.1.1.0"
#define WIN_DIAL_VERNUM 0x0110
#define WIN_DIAL_MAJOR 0
#define WIN_DIAL_MINOR 1
#define WIN_DIAL_REVISION 1
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
