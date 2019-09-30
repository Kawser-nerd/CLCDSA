#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<ctime>
using namespace std;
const int INF = 2147483647;
const double PI = 3.141592653589793;

int z,q,i,n;
long long tab[1005],d,res;

long long nwd (long long a, long long b) {
     if (b==0) return a;
     return nwd (b,a%b);
}

int main() {
scanf ("%d",&z);
for (q=1;q<=z;q++) {
    scanf ("%d",&n); 
    for (i=0;i<n;i++) cin >> tab[i];
    sort (tab,tab+n);
    d=tab[1]-tab[0];
    //cout << d << endl;
    for (i=1;i<n-1;i++)
        d = nwd(d,tab[i+1]-tab[i]);
    res = (d-tab[0]%d)%d;
    cout << "Case #"<< q << ": " << res << endl;       
}
return 0;
}
