#include <iostream>
#include <random>

using namespace std;

std::string generate_random_string() {
    constexpr int size{24};
    static const char alphanum[] =
        "0123456789"
        "`~!@$%^*+-_=:;?<>"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    std::string strstr;
    tmp_s.reserve(size);

    random_device rd;
    mt19937 gen{rd()};
    uniform_int_distribution<int> dis{0, sizeof(alphanum) - 1};

    for (int i{}; i < size; ++i) {
        char ch{};
        while (strstr.find(ch) != string::npos)
            ch = alphanum[dis(gen)];
        tmp_s += ch;
        strstr += ch;
    }
    
    return tmp_s;
}

int main()
{
    cout << generate_random_string();
}