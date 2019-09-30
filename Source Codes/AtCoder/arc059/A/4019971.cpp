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
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n;
    int ans1=0,ans2=0,ans3=0;
    for(int i=1;i<=n;i++)
    {
        ans1+=(sum-a[i])*(sum-a[i]);
        ans2+=(sum+1-a[i])*(sum+1-a[i]);
        ans3+=(sum-1-a[i])*(sum-1-a[i]);
    }
    cout<<min(ans1,min(ans2,ans3));
    return 0;
}