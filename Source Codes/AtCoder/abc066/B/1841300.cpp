#include <iostream>

bool IsEaseString(std::string sentense);

int main(int argc, char const *argv[]) {

    std::string S;
    std::cin >> S;


    for(int times = S.length() - 1 ; times > 0 ; times--)
    {
        std::string check_sentence = S.substr(0,times);

        if(IsEaseString(check_sentence))
        {
            std::cout << check_sentence.length() << '\n';
            break;
        }

    }

    return 0;
}


bool IsEaseString(std::string sentence)
{
    int string_length = sentence.length();

    /** 2?????????????????????????? **/
    if(string_length % 2 == 1)
        return false;

    /** ??????????????????? **/
    std::string forward_sentence = sentence.substr(0,string_length/2);
    std::string back_sentence = sentence.substr(string_length/2,string_length/2);


    return forward_sentence == back_sentence;
}