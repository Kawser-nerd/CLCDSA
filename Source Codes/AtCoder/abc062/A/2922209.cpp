#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<vector<int>> groups{{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
    int x, y; cin >> x >> y;
    bool ok = false;
    

    for (int i = 0; i < 3; i++) {
        if (find(groups[i].begin(), groups[i].end(), x) != groups[i].end() && find(groups[i].begin(), groups[i].end(), y) != groups[i].end()) {
            ok = true;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}