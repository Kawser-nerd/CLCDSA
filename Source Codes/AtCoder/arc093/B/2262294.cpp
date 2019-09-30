#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define CK(N, A, B) (A <= N && N < B)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = (b - 1); a <= i; i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long LLINF = 1e18;

using namespace std;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int dy8[] = {0,1,1,1,0,-1,-1,-1};
int dx8[] = {1,1,0,-1,-1,-1,0,1};

/*==================================================*/
/*variable*/
int A, B;
string s[110];
/*==================================================*/
/*function*/

/*==================================================*/

int main() {
    cin>>A>>B;

    REP(i,0,100) s[i] = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

    int cnt = 0;
    REP(i,0,50){
        REP(j,0,100){
            if(A > 1 && i % 2 == 0 && j % 2 == 0){
                s[i][j] = '.';
                A--;
            }else{
                s[i][j] = '#';
            }
        }
    }

    RREP(i,50,100){
        REP(j,0,100){
            if(B > 1 && i % 2 == 0 && j % 2 == 0){
                s[i][j] = '#';
                B--;
            }else{
                s[i][j] = '.';
            }
        }
    }

    cout<<100<<" "<<100<<endl;
    REP(i,0,100){
        cout<<s[i]<<endl;
    }

    return 0;
}