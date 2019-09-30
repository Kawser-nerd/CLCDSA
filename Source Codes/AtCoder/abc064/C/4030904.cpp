#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    int dy = 399;
    int t = 0;
    int size = 9;
    vector<int> t1 = {1,400,800,1200,1600,2000,2400,2800,3200};
    vector<int> t2 = {399,799,1199,1599,1999,2399,2799,3199,5000};
    int cnt[9] = {};

    for (int i = 0; i < N; i++){
        for (int k = 0; k < size; k++){
            if (t1[k] <= a[i] && a[i] <= t2[k]){
                cnt[k]++;
            }
        }
    }

    int minN = 0;
    for (int i = 0; i < 8; i++){
        if (cnt[i] != 0){
            minN++;
        }
    }

    int maxN = minN + cnt[8];
    if (cnt[8] == N){
        minN = 1;
        maxN = cnt[8];
    }

    cout << minN << ' ' << maxN << endl;





    


    return 0;
}