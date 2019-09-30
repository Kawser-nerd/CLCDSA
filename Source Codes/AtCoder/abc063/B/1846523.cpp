#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char const *argv[]) {

    std::string S;
    std::cin >> S;

    std::vector<bool> showed_alphabet(26);

    bool overlapping_find_word = false;
    for(const auto& word : S)
    {
        int alphabet_index = word - 'a';
        if(showed_alphabet[alphabet_index] == true)
        {
            overlapping_find_word = true;
            break;
        }

        showed_alphabet[alphabet_index] = true;
    }

    std::cout << (overlapping_find_word ? "no" : "yes" ) << '\n';
    return 0;
}