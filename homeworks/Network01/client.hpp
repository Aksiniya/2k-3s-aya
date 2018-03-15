#include <string>
#include <map>
#include <curl/curl.h>
#include <iostream>
#include <stdio.h>

namespace vk{
    class Client{
//        string name;
//        string password;
        string token;
    public:
        using dict_t = std::map<std::string, std::string>;
//        Client(dict_t settings) : name(settings->first),
//                                  password(settings->second){}
        Client(string tkn) : token(tkn){}
        
        void authorization(){
            string vk_url = "https://api.vk.com/method/friends.getOnline?v=5.52&access_token=" + token;
            curl_easy_setopt(curl, CURLOPT_URL, vk_url);
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
        
        auto check_connection() -> bool {
            
        }
    };
}