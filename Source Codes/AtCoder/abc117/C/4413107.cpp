#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,sum;
int a[100005],b[100005];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+m+1);
    for(int i=1;i<m;i++)
        b[i]=a[i+1]-a[i];
    sort(b+1,b+m);
    if(m<=n)
        cout<<0;
    else
    {
        int i=1;
        while(m!=n)
        {
            sum+=b[i];
            m--;
            i++;
        }
        cout<<sum;
    }
    return 0;
}