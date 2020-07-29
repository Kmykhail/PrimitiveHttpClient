#include <vector>

#include "PrimitiveHttpClient.h"

void test(PrimitiveHttpClient &http) {
    vector<string> urls_for_test {
            "https://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol", // OK
            "http://www.microsoft.com/" // Redirect -> https://www.microsoft.com/uk-ua/
    };

    for (auto &original_url : urls_for_test) {
        cout << "original_url: " << original_url << endl;

        string html;
        http.get(original_url, html);

        cout << html << endl;

        if (auto redirect_url = http.getRedirectUrl(); redirect_url != original_url) {
            // Redirect
            cout << "RedirectUrl: " << redirect_url << endl;
            cout << "ResponceCode: " << http.getResponseCode() << endl; // response code of redirected url
        }
    }
}

int main() {

    PrimitiveHttpClient http;

    http.setUserAgent("Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/33.0.1750.154 Safari/537.36");
    http.setTimeOut(30);

    test(http);

    return 0;
}