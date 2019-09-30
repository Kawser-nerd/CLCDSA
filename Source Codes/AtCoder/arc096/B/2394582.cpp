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
#include <bitset>

using namespace std;

void solve(long long N, long long C, vector<long long> x, vector<long long> v){
    vector< pair <long long, long long> > sushis;
    for (int i = 0; i < N; i++) {
        sushis.push_back(make_pair(x[i], v[i]));
    }
    sort(sushis.begin(), sushis.end());
    vector< vector<long long> > s(4, vector<long long>(N, 0));
    long long lr = 0;
    long long rr = 0;
    long long lp = 0;
    long long rp = 0;
    long long en = - (sushis[0].first - 0) + sushis[0].second;
    rp = max(en, rp);
    rr = max(en - sushis[0].first, rr);
    s[0][0] = rp;
    s[1][0] = rr;
    for (int i = 1; i < N; i++) {
        en += - (sushis[i].first - sushis[i-1].first) + sushis[i].second;
        rp = max(en, rp);
        rr = max(en - sushis[i].first, rr);
        s[0][i] = rp;
        s[1][i] = rr;
    }
    en = - (C - sushis[N-1].first) + sushis[N-1].second;
    lp = max(en, lp);
    lr = max(en - (C - sushis[N-1].first), lr);
    s[2][0] = lp;
    s[3][0] = lr;
    for (int i = 1; i < N; i++) {
        en += - (sushis[N-i].first - sushis[N-i-1].first) + sushis[N-i-1].second;
        lp = max(en, lp);
        lr = max(en - (C - sushis[N-i-1].first), lr);
        s[2][i] = lp;
        s[3][i] = lr;
    }
    vector<long long> re(2*N);
    for (int i = 0; i < N - 1; i++) {
        re[i] = s[0][i] + s[3][N-i-2];
    }
    re[N-1] = s[0][N-1];
    for (int i = 0; i < N - 1; i++) {
        re[i+N] = s[2][i] + s[1][N-i-2];
    }
    re[2*N-1] = s[2][N-1];
    std::cout << *max_element(re.begin(), re.end()) << std::endl;
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long C;
    long long N;
    scanf("%lld",&N);
    vector<long long> x(N-1+1);
    vector<long long> v(N-1+1);
    scanf("%lld",&C);
    for(int i = 0 ; i <= N-1 ; i++){
    	scanf("%lld",&x[i]);
    	scanf("%lld",&v[i]);
    }
    solve(N, C, x, v);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}