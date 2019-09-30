#include <iostream>
#include <string>

using namespace std;

int main() {
    string sa, sb, sc;
    cin >> sa >> sb >> sc;

    auto sai = sa.begin();
    auto sbi = sb.begin();
    auto sci = sc.begin();

    char winner = '\0';

    for (auto c = sa.begin(); !winner;) {
        if (*c == 'a') {
            if (sai == sa.end()) winner = 'A';
            else c = sai++;

        } else if (*c == 'b') {
            if (sbi == sb.end()) winner = 'B';
            else c = sbi++;
            
        } else {
            if (sci == sc.end()) winner = 'C';
            else c = sci++;
        }
    }

    cout << winner << endl;

    return 0;
}