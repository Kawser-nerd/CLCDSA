#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

#ifdef GCD_LCM
ll gcd(ll a,ll b) {
    if(b <= 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b) {
    return (a * b) / gcd(a,b);
}
#endif

class rain {
private:
public:
    int begin, end;

    rain(int _begin, int _end) {
        begin = (_begin / 100) * 60 + (_begin % 100);
        end = (_end / 100) * 60 + (_end % 100);
        begin = begin - (begin % 5);
        if (end % 5)
            end = end + 5 - (end % 5);
    }

    bool operator<(const rain &e) const {
        return this->begin < e.begin;
    }

    void print() {
        if (begin != end)
            printf("%02d%02d-%02d%02d\n", begin / 60, begin % 60, end / 60, end % 60);
    }
};

int main(int argc, char **argv) {
    int n;
    cin >> n;
    vector<rain> rs;
    for (int i = 0; i < n; i++) {
        int begin, end;
        scanf("%d-%d", &begin, &end);
        rs.push_back(rain(begin, end));
    }
    sort(rs.begin(), rs.end());
    for (int i = 0; i < rs.size() - 1; i++) {
        if (rs[i].end >= rs[i + 1].begin) {
            rs[i + 1].begin = min(rs[i + 1].begin,rs[i].begin);
            rs[i + 1].end = max(rs[i + 1].end, rs[i].end);
            rs[i].end = rs[i].begin;
        }
    }
    for (auto &e:rs) {
        e.print();
    }
}