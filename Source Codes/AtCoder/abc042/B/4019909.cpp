#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <string>
#include <cmath>
//#include <vector>
//#include <time.h>
#include <queue>
//#include <stack>
//#include <map>
//#include <set>
using namespace std;
typedef long long ll;
typedef long double ld;
int a[10000];
int main()
{
    string ch[1010];
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>ch[i];
    sort (ch+1,ch+n+1);
    for(int i=1;i<=n;i++)
        cout<<ch[i];
    return 0;
}