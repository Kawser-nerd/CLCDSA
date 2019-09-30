#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string s;
    std::cin >> s;
    std::vector<char> a;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1' || s[i] == '0'){
            a.push_back(s[i]);
        }
        else if(!(a.empty())){
            a.pop_back();
        }
    }
    for(int i = 0; i < a.size(); i++){
        std::cout << a[i];
    }
    return 0;
}