#include <cstdio>
#include <algorithm>
using namespace std;
int a,b;
int main()
{
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        printf("%d\n",max(a+b,max(a-b,a*b)));
    }
    return 0;
}