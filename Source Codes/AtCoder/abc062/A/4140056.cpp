#include <iostream>
#include <string>
#include <vector>
# define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;


string solve(int x, int y) {
    vector<int> a = {4, 6, 9, 11};

    auto ax = find(a.begin(), a.end(), x);
    auto ay = find(a.begin(), a.end(), y);

    if (x == 2 and y == 2) {
        return "Yes";
    }
    else if ((x == 2 and y != 2) or (x != 2 and y == 2)) {
        return "No";
    }
    else if (ax == a.end() and ay == a.end()) {
        return "Yes";
    }
    else if (ax != a.end() and ay != a.end()) {
        return "Yes";
    }
    else {
        return "No";
    }
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << solve(x, y) << endl;
    return 0;
}