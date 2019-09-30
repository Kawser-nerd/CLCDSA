#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int round(int t, int s){
        return (t + s/2)/s;
}
signed main(){
        int a,b;
        cin >> a >> b;
        int t = abs(b-a);
        int m5 = round(t,5);
        t = abs(t - 5*m5);
        cout << m5/2+m5%2 + t<< endl;
        return 0;
}