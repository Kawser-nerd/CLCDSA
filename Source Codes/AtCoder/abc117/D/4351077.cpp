#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    long long N,K;
    cin >> N >> K;
    long  long a[N];
    long  long c = 0;
    long  long d = K;
    vector<long long> cnt;
    for (int i =0;i < N ;i++){
        cin >> a[i];
    }
    for (int i = 0;i< 50;i++){
        cnt.push_back(0);
    }
    for (int i = 0;i < N;i++){
        long long b = a[i];
        c = 0;
        while(b >= 1){
            if(b % 2 == 1){
                cnt[c]++;
            }     
            b = b / 2;
            c++;
        }
    }
    //k???????????
    vector<long long> e;
    for (int i = 0;i< 50;i++){
        e.push_back(0);
    }
    int f = 0;
    while(d >= 1){
        e[f] = d % 2;
        d = d / 2;
        f++;
    }
    bool flag = false;
    int g; 
    for (int i = 0;i < f;i++){
        if (e[f-1-i] == 1){
        if (cnt[f-1-i] <= N / 2){
            cnt[f-1-i] = N - cnt[f-1-i];
        }
        else{
            flag = true;
            g = f- 1 -i;
            break;
        }
        }
    }
    if (flag == true){
        for (int i= 0;i<g;i++){
            if(cnt[i] <= N /2){
                cnt[i] = N - cnt[i];
            }
        }
    }
    long long p = 0;
    long long h = 1;
    for (int i = 0;i < 49;i++){
        p = p + cnt[i]*h;
        h = h * 2;
    }
    cout << p << endl;    
}