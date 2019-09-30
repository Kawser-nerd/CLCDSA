#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <time.h>
#include <memory>
using namespace std;

typedef long long LL;
typedef long long uLL;
typedef unsigned int uint;
#define FOR(i, b, e) for(int i=(b); i<int(e); ++i)
#define FORV(i, b, e) for(i=(b); i<(e); ++i)
#define GET(a) cin >> a
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PB(a) push_back(a)
#define SIZE(a) a.size()
#define PEEK(a) cout << " >> " #a " = " << a << endl
#define peek(a) _peek(#a, a)
template <typename T> void _peek(char name[], T &obj, size_t max_count=32){
    const size_t ipl = 10;
    cout << " >> " << name << " = ["; size_t _count = 0;
    for(typename T::iterator it=obj.begin(); it!=obj.end(); ++it){
        if(_count && _count%ipl == 0) cout << "      [";
        cout << *it; ++_count;
        if(_count%ipl == 0 || _count >= max_count || it == obj.end()-1) cout << " ]\n";
        else cout << ", ";
        if(_count >= max_count) break;
    }
}
template <typename T> ostream &operator << (ostream &cout, pair<T, T> &x){
    cout << "(" << x.first << "," << x.second << ")";
    return cout;
}
template <typename T> inline T GCD(T a, T b){
    if(b==0) return a;
    a %= b; while(a){ swap(a, b); a %= b; }; return b;
}
template <typename T> inline T LCM(T a, T b){
    if(a == 0 || b == 0) return -1;
    a /= GCD(a, b);	T lcm = a * b;
    if(lcm < 0 || lcm/a != b ) return -1;
    return lcm;
}
//===========================================================
int T, test_case;
int A, B;

bool visited[2000012];
int D[10];


LL solve(){
    LL ans=0;
    memset(visited, false, sizeof(visited));
    FOR(i, A, B+1) if(!visited[i]){
        visited[i] = true;
        LL cnt = 1; int size=0;
        
        for(int ti=i; ti; ti/=10) D[size++] = ti%10;
        for(int j=size-1; j>0; --j) if(D[j-1]){
            int upper = 0, lower = 0;
            for(int k=j-1; k>=0; --k) upper = 10*upper+D[k];
            for(int k=size-1; k>=j; --k) {
                lower = 10*lower+D[k];
                upper *= 10;
            }
            int new_num = upper+lower;
            if(new_num <= 2000000 
                && !visited[new_num] 
                && new_num >= A 
                && new_num <= B){
                visited[new_num] = true;
                cnt++;
            }
        }
        
        ans += cnt*(cnt-1)/2;
    }
    return ans;
}

int _tmain(int argc, _TCHAR* argv[])
{
    //freopen("z:\\input.txt", "r", stdin);
    freopen("z:\\output.txt", "w", stdout);
    //freopen("z:\\C-small-attempt0.in", "r", stdin);
    freopen("z:\\C-large.in", "r", stdin);


    GET(T);
    FORV(test_case, 1, T+1)
    {
        GET(A); GET(B);       
        cout << "Case #" << test_case << ": " << solve() <<endl;
    }

    return 0;
}

