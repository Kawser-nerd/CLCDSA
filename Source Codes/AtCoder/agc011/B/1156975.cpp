#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>
#include <time.h>
#include <random>

using namespace std;

int64_t imos[100000];

int main(){
    int N;
    cin>>N;
    vector<int64_t> A(N);
    for(auto &a:A) cin>>a;
    sort(A.begin(), A.end());
    imos[0]=A[0];
    for(int i=1;i<N;i++){
        imos[i]=imos[i-1]+A[i];
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        int64_t S = A[i];
        int idx = upper_bound(A.begin(), A.end(), S*2)-A.begin();
        while(idx<N){
            S = imos[idx-1];
            if(idx == upper_bound(A.begin(), A.end(), S*2)-A.begin()) break;
            idx = upper_bound(A.begin(), A.end(), S*2)-A.begin();
        }
        if(idx==N){
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}