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
    string s;
    cin >> s;
    int n = s.size();
    int c = 0;
    int d = 0;
    bool flag = 1;
    if(s[0]!='A')flag = 0;
    for(int i=2;i<n-1;i++){
        if(s[i]=='C')c++;
    }
    for(int i=0;i<n;i++){
        if(islower(s[i]))d++;
    }
    if(c!=1||d!=n-2)flag = 0;
    if(flag){
        cout << "AC" << endl;
    }else{
        cout << "WA" << endl;
    }
    return 0;
}