#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string s;
    cin >> s;

    vector<int> direction(4);
    fill(direction.begin(), direction.end(), 0);
    for (int i = 0; i < s.size(); i++) {
        switch (s[i]) {
            case 'E':
                direction[0]++;
                break;
            case 'W':
                direction[1]++;
                break;
            case 'S':
                direction[2]++;
                break;
            case 'N':
                direction[3]++;
                break;
        }
    }

    if (((direction[0] == 0 && direction[1] == 0) || (direction[0] != 0 && direction[1] != 0))
            && ((direction[2] == 0 && direction[3] == 0) || (direction[2] != 0 && direction[3] != 0))) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}