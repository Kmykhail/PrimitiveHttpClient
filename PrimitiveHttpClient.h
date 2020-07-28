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
// user-agent +

// TODO:
// * http status code
// * redirect url

class PrimitiveHttpClient {
public:
    PrimitiveHttpClient() = default;
    ~PrimitiveHttpClient();

    bool get(const string &url, string &res);

    void setTimeOut(uint32_t timeout) {_timeout = timeout;}
    void setUserAgent(const string &user_agent) {_user_agent = user_agent;}

private:
    static size_t _writeCallback(void *contents, size_t size, size_t nmemb, void *userp);

    void _activateSettings();

private:
    CURL *_curl {nullptr};

    uint32_t _timeout {0};

    string  _user_agent;
};


#endif //UNTITLED_PRIMITIVEHTTPCLIENT_H
