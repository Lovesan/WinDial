#include <string.h>
#include <windows.h>
#include <ras.h>
#include <raserror.h>
#include "WinDial.h"

static void WinDialRasClose(HRASCONN connection)
{
  RASCONNSTATUSW status;
  DWORD ret;
  status.dwSize = sizeof(status);
  if(ERROR_SUCCESS == RasHangUpW(connection))
  {
    do
    {
      ret = RasGetConnectStatusW(connection, &status);
      Sleep(100);
    } while(ERROR_INVALID_HANDLE != ret);
  }
}

static BOOL WinDialFindConnectionDesc(LPCWSTR name, LPRASCONNW connection)
{
  LPRASCONNW connections = NULL;
  DWORD bufferSize = 0, n = 0, ret, i;
  BOOL found = FALSE;
  ret = RasEnumConnectionsW(NULL, &bufferSize, &n);
  if(ERROR_BUFFER_TOO_SMALL != ret)
    goto cleanup;
  connections = (RASCONNW*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, bufferSize);
  connections[0].dwSize = sizeof(RASCONNW);
  ret = RasEnumConnectionsW(connections, &bufferSize, &n);
  if(ERROR_SUCCESS != ret)
    goto cleanup;  
  for(i = 0; i< n; ++i)
    if(0 == wcscmp(name, connections[i].szEntryName))
    {        
      found = TRUE;
      if(connection)
        *connection = connections[i];
      break;
    }
cleanup:
  if(connections)
    HeapFree(GetProcessHeap(), 0, connections);
  return found;
}

WIN_DIAL_EXTERN BOOL WinDialFindConnection(LPCWSTR name)
{
  return WinDialFindConnectionDesc(name, NULL);
}

WIN_DIAL_EXTERN BOOL WinDialOpenConnection(LPCWSTR name)
{  
  RASDIALPARAMSW params;
  BOOL pwd;
  DWORD ret, i = 0;
  HRASCONN conn = NULL;
  if(WinDialFindConnection(name))
    return TRUE;
  memset(&params, 0, sizeof(params));
  params.dwSize = sizeof(params);
  while(i < (sizeof(params.szEntryName) - 1))
  {
      if(!(params.szEntryName[i] = name[i]))
          break;
      ++i;
  }
  ret = RasGetEntryDialParamsW(NULL, &params, &pwd);
  if(ERROR_SUCCESS != ret)
    return FALSE;
  ret = RasDialW(NULL, NULL, &params, 0, NULL, &conn);
  if(ERROR_SUCCESS != ret)
    return FALSE;
  return TRUE;
}

WIN_DIAL_EXTERN BOOL WinDialCloseConnection(LPCWSTR name)
{
  RASCONNW connection;
  if(!WinDialFindConnectionDesc(name, &connection))
    return FALSE;
   WinDialRasClose(connection.hrasconn);
  return TRUE;
}
