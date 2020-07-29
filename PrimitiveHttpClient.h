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
// http status code +
// redirect url +

class PrimitiveHttpClient {
public:
    PrimitiveHttpClient();
    ~PrimitiveHttpClient();

    bool get(const string &url, string &res);

    uint32_t getResponseCode() const {return _response_code;}

    string  getRedirectUrl() const {return _redirect_url;}

    void setTimeOut(uint32_t timeout) {_timeout = timeout;}
    void setUserAgent(const string &user_agent) {_user_agent = user_agent;}
    void setRedirectAbility(bool redirect_flag) {_redirect_flag = redirect_flag;}
    void setSSLVerifyPeer(int peer) {_ssl_verify_peer = peer;}
    void setSSLVerifyHost(int host) {_ssl_verify_host = host;}


private:
    static size_t _writeCallback(void *contents, size_t size, size_t nmemb, void *userp);

    void _activateSettings();
    void _getCurlInfo();

private:
    CURL *_curl {nullptr};

    bool _redirect_flag {true};

    uint32_t _timeout {0};
    uint32_t _response_code {0};
    uint32_t _ssl_verify_peer {0};
    uint32_t _ssl_verify_host {0};

    string  _user_agent;
    string  _redirect_url;
};


#endif //UNTITLED_PRIMITIVEHTTPCLIENT_H
