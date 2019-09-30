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

int main()
{
    int ce;
    cin>>ce;
    for (int ci = 1; ci <= ce; ci++) {
        LL L, P, C;
        cin>>L>>P>>C;
        int res = 0;
        while (1) {
            if (L * C >= P)
                break;
            C *= C;
            res++;
        }
        printf("Case #%d: %d\n", ci, res);
    }
    return 0;
}
