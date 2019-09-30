#include<iostream>
#include<vector>

using namespace std;
#define ll long long

int main(){
    ll N;
    int a[4];
    int cnt=0;
    ll L[87];
    L[0] = 2;
    L[1] = 1;
    cin >> N;
    for(int i = 2; i <= N; i++){
        L[i]= L[i-1]+ L[i-2];
    }   
    cout << L[N] << endl;
}