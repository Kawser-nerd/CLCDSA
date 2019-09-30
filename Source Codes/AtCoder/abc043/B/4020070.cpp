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
    char ch[1000];
    char c;
    int l=500,r=500;
    while(~scanf("%c",&c))
    {
        if(c=='0')
            ch[r++]='0';
        if(c=='1')
            ch[r++]='1';
        if(c=='B'&&l!=r)
            r-=1;
    }
    for(int i=l;i<r;i++)
    {
        cout<<ch[i];
    }

    return 0;
}