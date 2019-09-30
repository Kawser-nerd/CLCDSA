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
    vector<int> a(n);
    a[0] = n;
    set<char>st;
    int c = 0;
    for(int i=n-1;i>=0;i--){
        st.insert(s[i]);
        if(st.size()==26){
            c++;
            a[c] = i;
            st.clear();
        }
    }
    int m = c;
    int l = 0;
    string ans;
    if(a[m]==0){
        ans.PB('a');
        for(int j=a[m];j<a[m-1];j++){
            if(s[j]=='a'){
                l = j+1;
                break;
            }
        }
        m--;
    }
    //cerr << m << endl;
    for(int i=m;i>=0;i--){
        st.clear();
        //cerr << l << " " << a[i] << endl;
        for(int j=l;j<a[i];j++){
            st.insert(s[j]);
        }
        char p;
        rep(j,26){
            if(st.count('a'+j)==0){
                ans.PB('a'+j);
                p = 'a'+j;
                break;
            }
        }
        if(i!=0){
            for(int j=a[i];j<a[i-1];j++){
                if(s[j]==p){
                    l = j+1;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}