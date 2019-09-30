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
    int n;
    cin>>n;
    a[n]++;
    cin>>n;
    a[n]++;
    cin>>n;
    a[n]++;
    if(a[5]==2&&a[7]==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}