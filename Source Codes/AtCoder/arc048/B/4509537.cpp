#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()

using namespace std;

int main(){
    int N;
    cin>>N;
    int R[N],H[N];
    vector<int> v;
    map<pair<int,int>,int> m;
    REP(i,N){
        cin>>R[i]>>H[i];
        v.push_back(R[i]);
        m[make_pair(R[i],H[i])]+=1;
        if(H[i]==3)m[make_pair(R[i],H[i]-3)]+=1;
        if(H[i]==1)m[make_pair(R[i],H[i]+3)]+=1;
    }
    sort(ALL(v));
    REP(i,N){
        int a=distance(v.begin(),lower_bound(ALL(v),R[i]));
        int b=distance(v.begin(),upper_bound(ALL(v),R[i]));
        cout<<a+m[make_pair(R[i],H[i]+1)]<<" ";
        cout<<N-b+m[make_pair(R[i],H[i]-1)]<<" ";
        cout<<m[make_pair(R[i],H[i])]-1<<endl;
    }
    return 0;
}