#include <iostream>
#include <cstdlib>

int solve(std::string str, char target){
    int ret = 0;
    const int length = str.length();
    int counter = 0;
    for (int i=0; i<length; ++i){
        if(target == str[i]){
            ret = std::max(ret, counter);
            counter = 0;
        }
        else {
            counter++;
        }
    }
    ret = std::max(ret, counter);
    return ret;
}

int main()
{
    std::string s;
    std::cin >> s;
    int ans = 101;
    for (int i=0; i<26; ++i){
        ans = std::min(ans, solve(s, 'a' + i));
    }
    std::cout << ans << std::endl;
    return 0;
}