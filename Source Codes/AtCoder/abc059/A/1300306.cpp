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

char s1[12];
char s2[12];
char s3[12];
int main(int argc, char * argv[])
{
    ios::sync_with_stdio(false);
    cin >> s1 >> s2 >> s3;
    cout << (char)((int)s1[0] - 32);
    cout << (char)((int)s2[0] - 32);
    cout << (char)((int)s3[0] - 32);
    cout << endl;
    return 0;
}