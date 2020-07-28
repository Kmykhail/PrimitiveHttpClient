//
// Created by kmykhail on 28.07.20.
//

#include "PrimitiveHttpClient.h"

size_t PrimitiveHttpClient::_writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

PrimitiveHttpClient::~PrimitiveHttpClient() {
    curl_easy_cleanup(_curl);
}

void PrimitiveHttpClient::_activateSettings() {

    if (_timeout)
    {
        curl_easy_setopt(_curl, CURLOPT_TIMEOUT_MS, 0);
        curl_easy_setopt(_curl, CURLOPT_CONNECTTIMEOUT_MS, 0);
        curl_easy_setopt(_curl, CURLOPT_TIMEOUT , _timeout);
        curl_easy_setopt(_curl, CURLOPT_CONNECTTIMEOUT , _timeout);
    }
}

bool PrimitiveHttpClient::get(const string &url, string &result) {

    result.clear();

    _curl = curl_easy_init();

    if (_curl) {
        curl_easy_setopt(_curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, _writeCallback);
        curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &result);

        _activateSettings();

        if (CURLcode status = curl_easy_perform(_curl); status != CURLE_OK) {
            return false;
        }
    }

    return true;
}