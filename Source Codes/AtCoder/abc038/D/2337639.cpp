#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>
//#include <boost/multiprecision/cpp_int.hpp>

#define BIT(a) (1 << (a))

using namespace std;
//using namespace boost::multiprecision;

long long MOD = 1000000007;


long long mod_pow(long long x, long long n){
    long long res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

const int MAX_N = 1 << 17;
int dat[2 * MAX_N -1];
int n;

void init(int n_){
    n = 1;
    while (n < n_) n *= 2;
    for (int i = 0; i < 2 * n - 1; i++) dat[i] = 0;
}

void update(int k, int a){
    k += n - 1;
    dat[k] = max(dat[k], a);
    while (k > 0){
        k = (k - 1) / 2;
        dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}

int query_(int a, int b, int k, int l, int r){
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return dat[k];
    return max(query_(a, b, k * 2 + 1, l, (l + r) / 2), query_(a, b, k * 2 + 2, (l + r) / 2, r));
}

int query(int a, int b){
    return query_(a, b, 0, 0, n);
}



vector<pair<int, int> > box;

bool my_cmp(pair<int, int> a, pair<int, int> b){
    if (a.first == b.first){
        return a.second > b.second;
    }else{
        return a.first < b.first;
    }
}

int main(void){
    int N;
    cin >> N;
    box = vector<pair<int, int> > (N);
    for (int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        box[i] = {x, y};
    }

    sort(box.begin(), box.end(), my_cmp);
    init(100005);
    for (int i = 0; i < N; i++){
        update(box[i].second, query(0, box[i].second) + 1);
        cout << endl;
    }
    cout << query(0, 2 * MAX_N -2) << endl;
}