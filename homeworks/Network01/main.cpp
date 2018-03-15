#include <vk/сlient.hpp>
#include <string>
#include <map>
#include <ios>

int main () {

    string token = " ";
    using vk::Client;
    auto client = Client(token);
    auto is_connected = client->authorization();
    return 0;
}
