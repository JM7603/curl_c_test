#include <stdio.h>

#define CURL_STATICLIB
#include "../include/curl/curl.h"

#pragma comment(lib, "libcurl.a")

// gcc .\test.c -o ..\out\test.exe
// -DNDEBUG -static -L ..\lib -lcurl -lws2_32 -lwinmm -lwldap32 -lbcrypt

int main(void) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");

    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    curl_easy_cleanup(curl);
  }
  return 0;
}
