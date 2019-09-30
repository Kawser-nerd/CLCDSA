#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {

    std::string O,E;
    std::cin >> O >> E;

    std::string answer = "";
    for(int word_index = 0 ; word_index < O.length() ; word_index++ )
    {
        if(word_index < O.length())
            answer += O.substr(word_index,1);
        if(word_index < E.length())
            answer += E.substr(word_index,1);
    }
    std::cout << answer << '\n';
    return 0;
}