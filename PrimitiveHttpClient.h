//
// Created by kmykhail on 28.07.20.
//

#ifndef UNTITLED_PRIMITIVEHTTPCLIENT_H
#define UNTITLED_PRIMITIVEHTTPCLIENT_H

#include <stdlib.h>
#include <curl/curl.h>

#include <iostream>
#include <string>

using namespace std;

// get +
// timeout +

// TODO:
// * user-agent
// * http status code
// * redirect url

class PrimitiveHttpClient {
public:
    PrimitiveHttpClient() = default;
    ~PrimitiveHttpClient();

    bool get(const string &url, string &res);

    void setTimeOut(uint32_t timeout) {_timeout = timeout;}

private:
    static size_t _writeCallback(void *contents, size_t size, size_t nmemb, void *userp);

    void _activateSettings();

private:
    CURL *_curl {nullptr};

    uint32_t _timeout {0};
};


#endif //UNTITLED_PRIMITIVEHTTPCLIENT_H
