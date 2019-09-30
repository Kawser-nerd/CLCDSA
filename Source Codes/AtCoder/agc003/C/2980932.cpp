//HASHEMESHOON hastam ;)
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <ctime>
#include <list>
#include <iterator>
#define ll long long
#define ss second
#define ff first
#define pb push_back
using namespace std;
ll n,m,x,y,a[100100],b[100100];
map <ll,ll> mp;
int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];b[i]=a[i];
    }
    sort(b,b+n);
    for(int i=0;i<n;i++){
        mp[b[i]]=i%2;
    }
    for(int i=0;i<n;i++){
        if(i%2!=mp[a[i]])x++;
    }
    cout<<x/2;
    return 0;
}