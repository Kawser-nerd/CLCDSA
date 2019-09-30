#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
using namespace std;
typedef vector<int> vint;
typedef vector<long long> vll;
typedef pair<int,int> pint;
typedef long long ll;
#define range(i,a,b) for(int i=a;i<b;++i)
#define rep(i,n) range(i,0,n)
#define INF 10000000000 //10^10
#define PI 3.141592

int main(){
    int n;
    string s;
    cin >> n >> s;
    int maxx=0;
    range(i,1,n){
        map<char,int> l,r;
        rep(j,i){
            l[s[j]]+=1;
        }
        range(j,i,n){
            r[s[j]]+=1;
        }
        int count=0;
        for(auto it=l.begin();it!=l.end();++it){
            if(r[it->first]!=0){
                ++count;
            }
        }
        maxx=max(maxx,count);
    }
    cout << maxx << endl;
}