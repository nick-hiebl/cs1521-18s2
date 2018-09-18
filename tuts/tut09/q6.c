// gcc q6.c -lcurl -o q6

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

int main(int argc, char **argv)
{
    CURL *cp;

    // check that they gave us a URL
    if (argc < 2) {
        fprintf(stderr, "Usage %s URL\n", argv[0]);
        exit(1);
    }
    // init the curl session
    curl_global_init(CURL_GLOBAL_ALL);
    cp = curl_easy_init();
    // set URL to get
    curl_easy_setopt(cp, CURLOPT_URL, argv[1]);
    // no progress meter please
    curl_easy_setopt(cp, CURLOPT_NOPROGRESS, 1L);
    // send all data to this function
    curl_easy_setopt(cp, CURLOPT_WRITEFUNCTION, write_data);
    // we want the headers be written to stdout
    curl_easy_setopt(cp, CURLOPT_HEADERDATA, headf);
    // we want the body be written to stdout
    curl_easy_setopt(cp, CURLOPT_WRITEDATA, bodyf);
    // get it!
    curl_easy_perform(cp);
    // cleanup curl stuff
    curl_easy_cleanup(cp);

    return 0;
}
