#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vs;
    int x[3];

    for (int i = 0; i < 3; i++) {
        int x; cin >> x;
        vs.push_back(x);
    }

    sort(vs.begin(), vs.end());

    cout << vs[0] + vs[1] << endl;

    return 0;
}