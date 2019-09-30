#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long N;
    cin >> N;
    int l;
    int cnt = 0;
    for(int i=0; i<=60; i++)
        if(N & (1LL << i)){
            l = i;
            cnt++;
        }

    long long N2 = 1;
    for(int i=0; i<l; i++){
        if((l-i) % 2 == 0){
            N2 <<= 1;
            N2++;
        }else N2 <<= 1;
    }
    if(N2 > N){
        if(l % 2 == 0) cout << "Takahashi" << endl;
        else cout << "Aoki" << endl;
    }else{
        if(l % 2 == 0) cout << "Aoki" << endl;
        else cout << "Takahashi" << endl;
    }

    return 0;
}