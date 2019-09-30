#include<iostream>
#include<set>
#include <vector>
#include <string>

using namespace std;
#define ll long long

int main(){
    int N;
    int m=0,a=0,r=0,c=0,h=0;
    int d[5];
    ll ans=0;
    cin >> N;
    string S;
    for(int i = 0; i < 5; i++)d[i]=0;
    for(int i = 0; i < N; i++){
        cin >> S;
        if(S[0] == 'M')d[0]++;
        if(S[0] == 'A')d[1]++;
        if(S[0] == 'R')d[2]++;
        if(S[0] == 'C')d[3]++;
        if(S[0] == 'H')d[4]++;
    }
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 4; j++){
            for(int k = j + 1; k < 5; k++){
                // cout << i << j << k<< endl;
                if(k < 5) ans += d[i] * d[j] * d[k];
            }
        }
    }

    cout << ans << endl;

}