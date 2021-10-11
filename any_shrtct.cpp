//============================================================================
// Name        : cpp4kids_s7(functions)....
// Author      : Omar.R.S
// Version     :
// Copyright   : Your copyright notice (<3)
// Description : solving cpp4kids H.Ws (functions) C++, Ansi-style
//============================================================================
//INCLUDES
#include <windows.h>

#include <map>
#include <string>
#include <iostream>

int main( int, char** )
{

   std::map< int, std::wstring > errors;
   errors[0]                      = L"The operating system is out of memory or resources.";
   errors[ERROR_FILE_NOT_FOUND]   = L"The specified file was not found.";
   errors[ERROR_PATH_NOT_FOUND]   = L"The specified path was not found.";
   errors[ERROR_BAD_FORMAT]       = L"The .exe file is invalid (non-Microsoft Win32 .exe or error in .exe image).";
   errors[SE_ERR_ACCESSDENIED]    = L"The operating system denied access to the specified file.";
   errors[SE_ERR_ASSOCINCOMPLETE] = L"The file name association is incomplete or invalid.";
   errors[SE_ERR_DDEBUSY]         = L"The Dynamic Data Exchange (DDE) transaction could not be completed because other DDE transactions were being processed.";
   errors[SE_ERR_DDEFAIL]         = L"The DDE transaction failed.";
   errors[SE_ERR_DDETIMEOUT]      = L"The DDE transaction could not be completed because the request timed out.";
   errors[SE_ERR_DLLNOTFOUND]     = L"The specified DLL was not found.";
   errors[SE_ERR_FNF]             = L"The specified file was not found.";
   errors[SE_ERR_NOASSOC]         = L"There is no application associated with the given file name extension. This error will also be returned if you attempt to print a file that is not printable.";
   errors[SE_ERR_OOM]             = L"There was not enough memory to complete the operation.";
   errors[SE_ERR_PNF]             = L"The specified path was not found.";
   errors[SE_ERR_SHARE]           = L"A sharing violation occurred.";

	int ret =
			reinterpret_cast<int>(::ShellExecuteA(0, L"open",
					L"\"C:\\Fraps\\fraps.exe\"",
					0, 0, SW_SHOW));
   const int minimumRetOK = 33;
   if ( ret < minimumRetOK ) {
      if ( errors.count( ret ) ) {
         std::wcout << L"Error " << ret << L" " << errors[ ret ];
      } else {
         std::wcout << L"Error " << ret << L" undocumented error";
      }
   }

    return (0);
}
