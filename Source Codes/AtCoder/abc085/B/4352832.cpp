#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

int  main(){
    int N;
    int a,b;
    int tmp = 1e9, ans = 0;
    cin >> N;
    vector<int> d(N);
    for(int i = 0; i < N; i++){
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    for(int i = N-1; i >= 0 ; i--){
        if(tmp > d[i]){
            ans++;
            tmp = d[i];
        }
    }
    cout << ans << endl;
}