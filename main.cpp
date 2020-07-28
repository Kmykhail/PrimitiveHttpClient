
#include "PrimitiveHttpClient.h"

int main() {

    PrimitiveHttpClient http;

    http.setTimeOut(30);

    string html;

    http.get("https://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol", html);
    cout << html << endl;

    return 0;
}