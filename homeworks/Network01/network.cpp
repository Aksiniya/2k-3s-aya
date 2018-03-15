#include <curl/curl.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    
    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.instagram.com/accounts/login/?force_classic_login");
        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        //Записывает вывод в поток STDERR, или файл, указанный параметром
        curl_easy_setopt(curl, CURLOPT_VERBOSE, true);
        
        //имя пользователя+пароль
        curl_easy_setopt(curl, CURLOPT_USERPWD, "name:pass");
        
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name$pass");
        
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 5.1; rv:31.0) Gecko/20100101 Firefox/31.0");
        
        //отмена поиска CA-сертификата - исключения ошибки peer certificate cannot be authenticated with given ca certificates
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        
        //выключение отображения тела
        curl_easy_setopt(curl, CURLOPT_NOBODY, true);
        
        //для возврата результата передачи в качестве строки из curl_exec() вместо прямого вывода в браузер.
        //curl_easy_setopt(curl, CURLOPT_RTSP_TRANSPORT, 1); ERROR! ! ! ! ! ! !
        
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