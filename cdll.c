#include <stdio.h>
#include <string.h>
#include "sockssrv.h"
#include <windows.h>
#include <tchar.h>

#define BUFFER_SIZE 100
// force gcc to link in go runtime (may be a better solution than this)

// Wanted to allow loads without DLLMain
extern  __declspec(dllexport) void CALLBACK Start(HWND hwnd, HINSTANCE hinst, LPCSTR lpszCmdLine, int nCmdShow)
{

	int n;

	//MessageBox(hwnd, lpszCmdLine, "", MB_OK);
	GoString host={0,0};
	GoString port={0,0};

	char *p;
	p = strtok((char*) lpszCmdLine, ":");
	if(p) {
		n = strlen(p);
		host.p = p;
		host.n = n;

		char buf[10];
		itoa(n,buf,10);
    }

    p = strtok(NULL, ",");
    if(p){
		n = strlen(p);
		port.p = p;
		port.n = n;

		char buf[10];
		itoa(n,buf,10);
	}

	// Handoff 
	StartSocks(host, port);
}



int main() { }