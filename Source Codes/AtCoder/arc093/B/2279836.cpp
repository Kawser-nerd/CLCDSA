#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool a[50][100];
bool b[50][100];
int main(){
    int A,B;
    cin >> A >> B;
    A--,B--;
    rep(i,50){
        rep(j,49){
            if(A==0)break;
            if(i%2){
                a[i][j*2+1] = true;
                A--;
                if(A==0)break;
            }
        }
        if(A==0)break;
    }
    rep(i,50){
        rep(j,49){
            if(B==0)break;
            if(i%2){
                b[i][j*2+1] = true;
                B--;
                if(B==0)break;
            }
        }
        if(B==0)break;
    }
    cout << "100 100\n";
    rep(i,50){
        rep(j,100){
            if(a[i][j]){
                cout << '.';
            }else{
                cout << '#';
            }
        }
        cout << endl;
    }
    rep(i,50){
        rep(j,100){
            if(!b[i][j]){
                cout << '.';
            }else{
                cout << '#';
            }
        }
        cout << endl;
    }
}