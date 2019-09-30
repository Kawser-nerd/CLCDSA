#include <iostream>
#include <vector>

int compare_large_number(std::string number,std::string other);

int main(int argc, char const *argv[]) {

    std::string A,B;
    std::cin >> A >> B;


    int compare_result = compare_large_number(A,B);
    if(compare_result > 0)
        std::cout << "GREATER" << '\n';
    else if(compare_result < 0)
        std::cout << "LESS" << '\n';
    else
        std::cout << "EQUAL" << '\n';


    return 0;
}

int compare_large_number(std::string number,std::string other)
{
    if(number.length() > other.length())
        return 1;
    if(number.length() < other.length())
        return -1;

    for(int word_index = 0 ; word_index < number.length() ; word_index ++ )
    {
        if(number[word_index] > other[word_index])
            return 1;
        if(number[word_index] < other[word_index])
            return -1;
    }

    return 0;
}