#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <vector>

#define ll long long

using namespace std;

int main()
{
    int N;
    ll sum=0;
    cin>>N;
    vector<int>l(N+1);
    vector<int>r(N+1);
    for(int i=1;i<=N;i++){
        cin>>l[i]>>r[i];
    }
    sort(r.begin(),r.end(),greater<int>());
    sort(l.begin(),l.end());
    for(int i=0;i<=N;i++){
        if(l[i]>r[i]){
            sum+=2*(l[i]-r[i]);
        }
    }
    cout<<sum<<endl;
    return 0;
}