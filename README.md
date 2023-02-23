# curl_c_test
Statically linked libcurl in the MinGW environment

## command

```bash
gcc .\test.c -o ..\out\test.exe -DNDEBUG -static -L ..\lib -lcurl -lws2_32 -lwinmm -lwldap32 -lbcrypt
```

