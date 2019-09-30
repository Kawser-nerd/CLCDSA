#include<iostream>
#include<string>
#include<vector>
#include <cassert>

using namespace std;

string s;
int cnt[200000] = {0};
int moveto[200000] = {0};
int tmp[26] = {0};
vector<int> v[26];

template <typename T>
class BIT {
private:
    vector<T> v;
    const int n;

public:
    BIT(int _n) : v(_n + 1, 0), n(_n) {}

    // a[0] + a[1] + ... + a[i - 1]
    // O(log n)
    T sum (int i) {
        assert(0 <= i && i < n + 1);
        T s = 0;
        while(i > 0) {
            s += v[i - 1];
            i -= i & -i;
        }
        return s;
    }

    // a[i] + a[i + 1] + ... + a[j - 1]
    // O(log n)
    T sum (int i, int j) {
        return sum(j) - sum(i);
    }

    // a[i] += x
    // O(log n)
    void add(int i, T x) {
        assert(0 <= i && i < n);
        i++;
        while (i <= n) {
            v[i - 1] += x;
            i += i & -i;
        }
    }

};

int main() {
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        cnt[i] = tmp[s[i] - 'a'];
        tmp[s[i] - 'a']++;
        v[s[i] - 'a'].push_back(i);
    }
    int odd = 0;
    for (auto vi : v) {
        if (vi.size() % 2 == 1)odd++;
    }

    if (odd > 1) {
        cout << -1 << endl;
        return 0;
    }

    int forecnt = 0;
    for (int i = 0; i < n; ++i){
        int c = s[i] - 'a';
        int totalcnt = tmp[c];
        if (cnt[i] < totalcnt / 2) {
            moveto[i] = forecnt;
            forecnt++;
        } else if (totalcnt % 2 == 1 && totalcnt / 2 == cnt[i]) {
            moveto[i] = n / 2;
        } else {
            int pairpos = v[c][totalcnt - cnt[i] - 1];
            moveto[i] = n - moveto[pairpos] - 1;
        }
    }

    // for (int i = 0; i < n; ++i){
        // cout << moveto[i] << " ";
    // }

    BIT<int> b = BIT<int>(n);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += i - b.sum(moveto[i] + 1);
        b.add(moveto[i], 1);
    }
    cout << ans << endl;
}