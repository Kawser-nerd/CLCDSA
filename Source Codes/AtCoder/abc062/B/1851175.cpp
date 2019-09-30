#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    int H,W;
    std::cin >> H >> W;

    std::vector<char> words;
    for(int height = 0 ; height < H ; height++)
    {
        for(int width = 0 ; width < W ; width++ )
        {
            char word;
            std::cin >> word;
            words.push_back(word);
        }
    }

    for(int width = 0 ; width < W + 2 ; width++ )
    {
        std::cout << "#";
    }
    putchar('\n');

    for(int height = 0 ; height < H ; height++)
    {
        std::cout << "#";
        for(int width = 0 ; width < W ; width++ )
        {
            std::cout << words[W*height+width];
        }
        std::cout << "#" << '\n';
    }

    for(int width = 0 ; width < W + 2 ; width++ )
    {
        std::cout << "#";
    }
    putchar('\n');
    return 0;
}