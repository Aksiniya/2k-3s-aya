#include <string>
#include <curl/curl.h>
#include <iostream>
#include <stdio.h>

using namespace std;

namespace vk{
    class Client{
        string token;
        string vk_method_url = "https://api.vk.com/method/";
    public:
        Client(string tkn) : token(tkn){}
        
        void getOnlineFriends(){
            string getFriendsUrl = vk_method_url + "friends.getOnline" + "?v=5.52&access_token=" + token;
            CURL *curl;
            CURLcode res;
            
            curl = curl_easy_init();
            if (curl){
                curl_easy_setopt(curl, CURLOPT_URL, getFriendsUrl.c_str() );
                curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
                curl_easy_setopt(curl, CURLOPT_VERBOSE, true);
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
                
                res = curl_easy_perform(curl);
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
        }
        
        bool checkConnection(){
            CURL *curl = curl_easy_init();
            CURLcode res;
            if (curl) {
                string connectionUrl = vk_method_url + "account.getInfo" + "?v=5.52&access_token=" + token;
                curl_easy_setopt(curl, CURLOPT_URL, connectionUrl.c_str() );
                curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
                curl_easy_setopt(curl, CURLOPT_VERBOSE, true);
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
                //                curl_easy_setopt(curl, CURLOPT_NOBODY, true);
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
        }
    };
}