#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
int main() {
        int N, M;
        cin >> N >> M;
        vector<pair<int, int> > r(M);
        for(auto &x: r) {
                cin >> x.second >> x.first;
        }

        sort(r.begin(),r.end());

        int pos = 0, num = 0;

        for(auto x: r) {
//              cout << x.first << " " << x.second << " " << pos << endl;
                if(pos < x.second) {
                        pos = x.first - 1;
                        num++;
                }
        }

        cout << num << endl;
}