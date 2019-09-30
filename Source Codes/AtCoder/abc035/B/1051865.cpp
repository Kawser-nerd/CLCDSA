#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int t;
    cin >> s >> t;
    int x, y;
    x = y = 0;
    int hatena_count = 0;
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        switch(*iter) {
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            case '?':
                hatena_count++;
                break;
        }
    }
    int dist = abs(x) + abs(y);
    if (t == 2) {
        dist = max((int)s.size() % 2, dist - hatena_count);
    } else {
        dist += hatena_count;
    }
    cout << dist << endl;
}