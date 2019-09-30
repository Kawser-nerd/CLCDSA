#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-9;
 
typedef long long ll;
 
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
 
 
char A[105];
char B[105];
int main(int argc, char * argv[])
{
    ios::sync_with_stdio(false);
    cin >> A >> B;
    int flag = 0;
    if (strlen(A) > strlen(B)) {
        cout << "GREATER" << endl;
        return 0;
    }
    if (strlen(A) < strlen(B)) {
        cout << "LESS" << endl;
        return 0;
    }
    rep(i, 100) {
        if ((int)A[i] == 0) {
            break;
        }
        if (A[i] > B[i]) {
            cout << "GREATER" << endl;
            return 0;
        }
        if (A[i] < B[i]) {
            cout << "LESS" << endl;
            return 0;
        }
    }
    cout << "EQUAL" << endl;
 
    return 0;
}