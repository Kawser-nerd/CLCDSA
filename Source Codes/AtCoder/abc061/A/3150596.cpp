#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
int main()
{

    int a, b, c; 
    scanf("%d%d%d",&a,&b,&c);
    if(c >= a && c <= b)
        printf("Yes\n");
    else
    {
        printf("No\n");
    }
    return 0;
}