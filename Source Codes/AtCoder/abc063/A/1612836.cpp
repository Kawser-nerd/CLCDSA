#include<cstdio>
#include<map>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main(){
        int a,b;cin>>a>>b;
        int sum = a+b;
        string ans = to_string(sum);
        cout<<(sum<10 ? ans:"error" )<<endl;
        return 0;
}