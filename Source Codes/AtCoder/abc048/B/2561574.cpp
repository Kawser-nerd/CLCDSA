#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
#include <string.h>
#include <math.h>
#include<map>
#include<string.h>
#define ll long long
using namespace std;
ll a,b,c;
int main()
{

    cin>>a>>b>>c;
    cout<<b/c-a/c+(bool)(a%c==0)<<endl;
    return 0;
}