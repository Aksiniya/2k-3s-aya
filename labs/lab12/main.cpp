
#include <stdio.h>
#include <curl/curl.h>

int main(int argc, char* argv[])
{
    if(argc < 2){
        cout << "Отсутствует передаваемый параметр - нет информации о ресурсе" << endl;
        return 0;
    }
    
    char* name = argv[1];
    
    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, name);
        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        //отмена поиска CA-сертификата - исключения ошибки peer certificate cannot be authenticated with given ca certificates
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        //выключение отображения тела
        curl_easy_setopt(curl, CURLOPT_NOBODY, true);
        
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
    return 0;
}
