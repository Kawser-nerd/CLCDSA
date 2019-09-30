#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>

bool finishGame(std::map<std::string, std::string> hands)
{
    for(const auto& hand : hands)
    {
        if(hand.second.length() == 0)
            return true;
    }
    return false;
}


int main(int argc, char const *argv[]) {

    std::string A,B,C;
    std::cin >> A >> B >> C;

    std::map<std::string, std::string> each_hands;
    each_hands["a"] = A;
    each_hands["b"] = B;
    each_hands["c"] = C;

    std::string current_turn_name = "a";
    while(true)
    {
        auto player_hand = each_hands[current_turn_name];
        std::string card_name = player_hand.substr(0,1);
        if(card_name == ""){
            putchar(std::toupper(current_turn_name[0]));
            putchar('\n');
            break;
        }
        each_hands[current_turn_name] = player_hand.substr(1,player_hand.length());

        current_turn_name = card_name;
    }
    return 0;
}