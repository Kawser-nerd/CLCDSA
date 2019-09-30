#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BIT {
        public:
        vector<int> a;
        BIT(int n) {
                a = vector<int>(n, 0);
        }
        int query(int i) {
                int res = 0;
                for(int j = i; j != 0 ; j -= (j & (-j))) {
                        res = max(res, a[j]);
                }
                return res;
        }
        void update(int i, int num) {
                for(int j = i; j < a.size(); j += (j & (-j))) {
                        a[j] = max(a[j], num);
                }
        }
        void print() {
                for(auto x: a) {
                        cout << x << endl;
                }
        }
};
int main() {
        int N;
        cin >> N;
        BIT hoge(100010);
        vector<int> p(N);
        vector<pair<int,int>> a(N);
        for(auto& x : a) {
                cin >> x.second >> x.first;
                x.second *= -1;
        }
        sort(a.begin(),a.end());
        int res = 0;
        for(int i = 0; i < N; i++) {
                a[i].second *= -1;
                p[i] = hoge.query(a[i].second - 1) + 1;
                hoge.update(a[i].second, p[i]);
                res = max(res, p[i]);
        }
        cout << res << endl;
}