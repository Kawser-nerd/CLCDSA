#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;

int bit[static_cast<int>(2*(1e5)+1)], n;

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int x) {
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

void solve(string S){
    vector<int> bin(26, 0);
    for (auto&& c : S) {
        bin[c - 'a']++;
    }
    bool flag = false;
    char cent;
    for (int i = 0; i < 26; i++) {
        if (bin[i]%2 != 0) {
            if (flag == false) {
                flag = true;
                cent = 'a' + i;
            } else {
                std::cout << -1 << std::endl;
                return;
            }
        }
        bin[i] /= 2;
    }
    string cir;
    for (auto&& c : S) {
        if (bin[c - 'a'] > 0) {
            cir.push_back(c);
            bin[c - 'a']--;
        }
    }
    vector< vector< int > > vv(26, vector<int>());
    int l = 0;
    for(int i = 0; i < cir.size(); i++) {
        vv[cir[i] - 'a'].push_back(l);
        l++;
    }
    if(flag) {
        vv[cent - 'a'].push_back(l);
        l++;
    }
    for (int i = 0; i < cir.size(); i++) {
        vv[cir[cir.size()-i-1] - 'a'].push_back(l);
        l++;
    }
    vector<int> itr(26, 0);
    vector<int> a(S.size());
    for (int i = 0; i < S.size(); i++) {
        a[i] = vv[S[i] - 'a'][itr[S[i] - 'a']]+1;
        itr[S[i] - 'a']++;
    }
    long long ans = 0;
    n = S.size();
    for (int i = 0; i < static_cast<int>(2*(1e5)+1); i++) {
        bit[i] = 0;
    }
    for (int i = 0; i < S.size(); i++) {
        ans += i - sum(a[i]);
        add(a[i], 1);
    }
    std::cout << ans << std::endl;
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    string S;
    cin >> S;
    solve(S);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}