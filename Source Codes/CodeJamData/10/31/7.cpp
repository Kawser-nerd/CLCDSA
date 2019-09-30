#include  <cstdio> 
#include  <cstdlib> 
#include  <cstring> 
#include  <string> 
#include  <vector> 
#include  <cmath> 
#include  <algorithm> 
#include  <cassert> 
#include  <set> 
#include  <map> 
#include  <queue> 
#include  <iostream> 
#include <fstream> 
using namespace std; 
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )  

typedef long long LL; 
typedef pair<int,int> pii; 

int t[1024][2];

int main()
{
    int ce;
    cin>>ce;
    for (int ci = 1; ci <= ce; ci++) {
        int N;
        cin>>N;
        REP(i, N)
            cin>>t[i][0]>>t[i][1];
        int res = 0;
        REP(i, N)
            REP(j, N)
                if (t[i][0] > t[j][0] && t[i][1] < t[j][1])
                    res++;
        printf("Case #%d: %d\n", ci, res);
    }
    return 0;
}
