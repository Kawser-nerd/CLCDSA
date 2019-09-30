#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    string s;
    cin >> s;
    long w_sum = 0;
    long len = s.length();
    long b_count = 0;
    for (int i = 0 ; i < s.length(); i++) {
        if (s[i] == 'W')  w_sum += b_count;
        else if (s[i] == 'B') b_count += 1;
    }
    cout << w_sum ;
    return 0;
}