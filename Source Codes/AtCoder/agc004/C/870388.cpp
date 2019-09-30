//C++14 (Clang 3.8.0)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#define rp(i,a,b) for(int (i)=(int)(a);i<(int)(b);++i)

typedef long long ll;


using namespace std;


int main(){
    int H,W;
    vector<vector<bool>> a,r,b;
    cin>>H>>W;
    rp(i,0,H)  {
        string s;
        cin>>s;
        vector<bool> tmp;
        rp(j,0,W) {
            if(s[j]=='#') tmp.push_back(true);
            else tmp.push_back(false);
        }
        a.push_back(tmp);
    }

    
    rp(i,0,H){
        vector<bool> tmp_r,tmp_b;
        if( i%2 == 0 ) {rp(k,0,W) {tmp_r.push_back(true);tmp_b.push_back(false);}tmp_b[W-1] = true;}
        else rp(k,0,W) {{tmp_r.push_back(false);tmp_b.push_back(true);}tmp_r[0] = true;}
        tmp_r[W-1] = false;
        tmp_b[0] = false;
        rp(j,0,W){
            if(a[i][j] == true){
            tmp_r[j] = true;
            tmp_b[j] = true;
            }
        }
        r.push_back(tmp_r);
        b.push_back(tmp_b);
    }
    rp(i,0,H) {
        rp(j,0,W) {
            if(r[i][j]) cout<<'#';
            else cout<<'.';
        }
        cout<<endl;
    }
    cout<<endl;
    rp(i,0,H) {
        rp(j,0,W) {
            if(b[i][j]) cout<<'#';
            else cout<<'.';
        }
        cout<<endl;
    }



    return 0;
};