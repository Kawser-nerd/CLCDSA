#include <iostream>
#include <set>

int main(){

    int i;

    std::string str;
    std::cin >> str;

    if(str.size() != 26){
        std::set<char> alphabet;
        char a = 'a';

        for(i = 0; i < 26; i++){
            alphabet.insert(a);
            a++;
        }

        for(i = 0; i < str.size(); i++){
            alphabet.erase(str[i]);    
        }

        std::cout << str + *alphabet.begin() << std::endl;
        return 0;
    }else{
        int pos = -1;
        char min = 'z';
        for(i = 0; i < str.size(); i++){
            if((str[i] < str[i + 1]) == 1){
                pos = i;
            }
        }

        if(pos == -1){
            std::cout << pos << std::endl;
            return 0;
        }


        for(i = pos + 1; i < str.size(); i++){
            if(min > str[i] && str[pos] < str[i]) min = str[i];
        }

        str[pos] = min;
        for(i = 0; i < pos + 1; i++){
            std::cout << str[i];
        }
        std::cout << std::endl;
        return 0;
    }
}