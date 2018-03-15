#include "vk/client.hpp"
#include <curl/curl.h>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

namespace vk {
    
    void Client::getOnlineFriends(){
        string getFriendsUrl = vk_method_url + "friends.getOnline" + "?v=5.52&access_token=" + token;
        CURL *curl;
        CURLcode res;
        
        curl = curl_easy_init();
        if (curl){
            curl_easy_setopt(curl, CURLOPT_URL, getFriendsUrl.c_str() );
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_VERBOSE, true);
            //отмена поиска CA-сертификата - исключения ошибки peer certificate cannot be authenticated with given ca certificates
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
            
            res = curl_easy_perform(curl);
            //проверка на ошибки
            if(res != CURLE_OK){
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            }
            else {
                //вывод подключения
                char *url = NULL;
                curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);
                if(url){
                    printf("Redirect to: %s\n", url);
                }
                
                // вывод кода
                long response_code;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
                printf("Response code: %ld\n", response_code);
            }
            
            /* always cleanup */
            curl_easy_cleanup(curl);
        }
    };

    bool Client::checkConnection(){
        CURL *curl = curl_easy_init();
        CURLcode res;
        if (curl) {
            string connectionUrl = vk_method_url + "account.getInfo" + "?v=5.52&access_token=" + token;
            curl_easy_setopt(curl, CURLOPT_URL, connectionUrl.c_str() );
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_VERBOSE, true);
            //отмена поиска CA-сертификата - исключения ошибки peer certificate cannot be authenticated with given ca certificates
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
            //отключение отображения тела
//          curl_easy_setopt(curl, CURLOPT_NOBODY, true);
        }
        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return false;
        }
        else {
            //вывод подключения
            char *url = NULL;
            curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);
            if(url){
                printf("Redirect to: %s\n", url);
            }
            // вывод кода
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            printf("Response code: %ld\n", response_code);
            return true;
        }
        /* always cleanup */
        curl_easy_cleanup(curl);
    };
}