#include "vk/client.hpp"

int main () {
    string token;
    cout << "Введите token:" << endl;
    cin >> token;
    vk::Client client(token);
    bool is_connected = client.checkConnection();
    if(is_connected){
        client.getOnlineFriends();
    }
    return 0;
}