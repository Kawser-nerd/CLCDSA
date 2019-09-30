#include <algorithm>
#include <iostream>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <vector>
#include <map>
#include <tuple>
#include <random>
#include <stdio.h>
using namespace std;

int N;

int main(){
    cin>>N;
    long up[N],down[N];
    for (int i=0;i<N;i++) cin>>up[i]>>down[i];
    vector <tuple<long,long>> l,u;
    for (int i=0;i<N;i++) {
        if(up[i]<=down[i])  l.push_back(make_tuple(up[i],down[i]));
        if(up[i]>down[i])  u.push_back(make_tuple(up[i],down[i]));

    }

    sort(l.begin(),l.end(),
            [](tuple<long,long> const &lhs, tuple<long,long> const &rhs) {
                return get<0> (lhs) < get<0>(rhs);
                }
            );
    sort(u.begin(),u.end(),
            [](tuple<long,long> const &lhs, tuple<long,long> const &rhs) {
                return get<1> (lhs) > get<1>(rhs);
                }
            );

    long long n=0,m=-LONG_MAX;
    //cout<<l.size()<<get<1> (l[0])<<endl;
    for (int i=0;i<l.size();i++){
        n=n+get<0>(l[i]);
        if(n>m) m=n;
        n=n-get<1>(l[i]);
    }
    for (int i=0;i<u.size();i++){
        n=n+get<0>(u[i]);
        if(n>m) m=n;
        n=n-get<1>(u[i]);
    }
    cout<<m<<endl;
}