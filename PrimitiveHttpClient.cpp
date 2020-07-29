//
// Created by kmykhail on 28.07.20.
//

#include "PrimitiveHttpClient.h"

size_t PrimitiveHttpClient::_writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

PrimitiveHttpClient::PrimitiveHttpClient() {
    curl_global_init(CURL_GLOBAL_ALL);
    _curl = curl_easy_init();
}

PrimitiveHttpClient::~PrimitiveHttpClient() {
    curl_easy_cleanup(_curl);
}

void PrimitiveHttpClient::_activateSettings() {

    curl_easy_setopt(_curl, CURLOPT_FOLLOWLOCATION, _redirect_flag);
    curl_easy_setopt(_curl, CURLOPT_SSL_VERIFYPEER , _ssl_verify_peer);
    curl_easy_setopt(_curl, CURLOPT_SSL_VERIFYHOST, _ssl_verify_host);

    if (_timeout) {
        curl_easy_setopt(_curl, CURLOPT_TIMEOUT_MS, 0);
        curl_easy_setopt(_curl, CURLOPT_CONNECTTIMEOUT_MS, 0);
        curl_easy_setopt(_curl, CURLOPT_TIMEOUT , _timeout);
        curl_easy_setopt(_curl, CURLOPT_CONNECTTIMEOUT , _timeout);
    }

    if (!_user_agent.empty()) {
        curl_easy_setopt(_curl, CURLOPT_USERAGENT, _user_agent.c_str());
    }
}

void PrimitiveHttpClient::_getCurlInfo() {

   curl_easy_getinfo(_curl, CURLINFO_RESPONSE_CODE , &_response_code);

   char *tmp = nullptr;

   curl_easy_getinfo(_curl, CURLINFO_EFFECTIVE_URL ,&tmp);
   if (tmp) _redirect_url = tmp;
}

bool PrimitiveHttpClient::get(const string &url, string &result) {

    result.clear();

    if (_curl) {
        curl_easy_setopt(_curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, _writeCallback);
        curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &result);

        _activateSettings();

        if (CURLcode status = curl_easy_perform(_curl); status != CURLE_OK) {
            return false;
        }

        _getCurlInfo();

    }

    return true;
}