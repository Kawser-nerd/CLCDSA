#include<iostream>
#include<cmath>
#include<string>
#include<vector>

using namespace std;
#define ll long long 

int  main(){
    int N;
    cin >> N;
    vector<int> c(N);
    vector<int> s(N);
    vector<int> f(N);
    vector<int> a(N,0);
    int t,b;
    int tmp;
    bool flag = true;
    for(int i = 0; i < N-1; i++){
        cin >> c[i] >> s[i] >> f[i];
    }
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < N; j++){
            if(j <= i){
                if(a[j]< s[i]){
                    a[j] = s[i];
                }else{
                    t = a[j] % f[i];
                    if(t != 0) a[j] = a[j] - t + f[i];
                }
                a[j] += c[i];
            }
        }
    }
    for(int i = 0; i < N; i++) cout << a[i] << endl;
}