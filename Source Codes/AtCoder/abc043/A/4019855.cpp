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
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=i;
    cout<<ans;
    return 0;
}