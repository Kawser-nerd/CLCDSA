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
#include <list>
#include <queue>
#include <bitset>

using namespace std;

bool dfs(vector<long long>& o, long long node, vector< list< pair<long long, long long> > >& r, vector<int>& used){
    for (auto&& var : r[node]) {
        if (used[var.first] == 1) {
            if (o[var.first] == o[node] + var.second) {
                continue;
            } else {
                return false;
            }
        } else {
            used[var.first] = 1;
            o[var.first] = o[node] + var.second;
            if(dfs(o, var.first, r, used)) {
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

void solve(long long N, long long M, vector<long long> L, vector<long long> R, vector<long long> D){
    vector<long long> o(N);
    vector<int> used(N, 0);
    vector< list< pair<long long, long long> > > r(N, list< pair<long long, long long> >());
    for (int i = 0; i < M; i++) {
        r[L[i]-1].push_back(make_pair(R[i]-1, D[i]));
        r[R[i]-1].push_back(make_pair(L[i]-1, -D[i]));
    }
    bool flag = true;
    for (int i = 0; i < N; i++) {
        if(used[i] == 1) {
            continue;
        }
        used[i] = 1;
        o[i] = 0;
        if(dfs(o, i, r, used)){
            continue;
        } else {
            flag = false;
            break;
        }
    }
    if (flag) {
        //long long minx = *min_element(o.begin(), o.end());
        //long long maxx = *max_element(o.begin(), o.end());
        //if (maxx - minx <= 1000000000) {
        //    std::cout << "Yes" << std::endl;
        //} else {
        //    std::cout << "No" << std::endl;
        //}
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long M;
    long long N;
    std::cin >> N;
    std::cin >> M;
    vector<long long> D(M);
    vector<long long> R(M);
    vector<long long> L(M);
    for(int i = 0 ; i < M ; i++){
        std::cin >> L[i] >> R[i] >> D[i];
    }
    solve(N, M, L, R, D);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}