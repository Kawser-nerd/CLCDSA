#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <queue>
using namespace std;

#define ll long long
typedef pair<ll, ll> P;

int main(){
    ll X,A,B,N, K,sum=0,l=0,r=0, tmp = 1000000000000000000LL;;
    cin >> N;
    vector<int> a(N);
    vector< set<ll> > E(N); 
    P p;
    queue<P> pairs;
    vector<ll> dist1(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
        a[i]--;
        E[i].insert(a[i]);
    }

    for(int i = 0; i < N; i++){
        dist1[i] = -1;
    }
    dist1[0] = 0;

    //cul dist1
    for(auto i: E[0]){
        // cout << i << endl;
        pairs.push(make_pair(i,1));
    }
    while(pairs.size()){
        p = pairs.front();
        pairs.pop();
        int d = p.second;
        int n = p.first;
        if(dist1[n] == -1){
            dist1[n] = d;
            for(auto i: E[n]) pairs.push(make_pair(i, d+1));
        }
    }
    cout << dist1[1] << endl;
}