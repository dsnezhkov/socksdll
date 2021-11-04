Experiment: Loadable socks5 proxy via CGo/C bridge.


## Build

### Pre-requisites

gcc:
   - x86_64-w64-mingw32
e.g: 
```
chocolatey.exe install mingw
```

### Compilation
- Build CGo linked Golang code with exported function 
```
go build -buildmode=c-archive sockssrv.go
```
- Compile C-Dll against CGo static library and bridged to Go, minding the libraries needed

```
gcc -shared -pthread -o cdll.dll cdll.c sockssrv.a -mwindows -lWinMM -lntdll -lWS2_32
```

## Runtime 
Invoke a Go function via C-DLL and pass parameters 
```
rundll32.exe .\cdll.dll,Start 127.0.0.1:3120
```
Note: It does not use DllMain so no default onLoad callbacks


### References
Thanks: 
- Idea and initial example: https://github.com/z505/goDLL 
- Socks library:  https://github.com/armon/go-socks5
