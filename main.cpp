
#include "PrimitiveHttpClient.h"

int main() {

    PrimitiveHttpClient http;

    http.setUserAgent("Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/33.0.1750.154 Safari/537.36");
    http.setTimeOut(30);

    string html;

    http.get("https://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol", html);

    cout << html << endl;

    return 0;
}