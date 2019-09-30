#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int k;
    int n;
    cin >> k;
    if(k==1){
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    n = (k/4+1)*2;
    if(n>500){
        n=500;
    }
    vector<vector<int> > v(n,vector<int>(n));
    int p=1;
    rep(i,n){
        int t = i;
        rep(j,n){
            if(n-i+p-1!=k){
                if(j%2==0)v[j][t] = p;
                else v[j][t] = p+1;
            }else{
                v[j][t]= p;
            }
            t = (t+n-1)%n;
        }
        if(n-i+p-1==k){
            p+=1;
        }else{
            p+=2;
        }
    }
    cout << n << endl;
        rep(i,n){
            rep(j,n){
               cout << v[i][j] << " "; 
            }
            cout << endl;
        }
    return 0;
}