#include <iostream>

int main()
{
    std::string s[3];
    std::cin >> s[0] >> s[1] >> s[2];
    for(int i = 0; i < 3; i++){
        std::cout << s[i][0];
    }

    return 0;
}