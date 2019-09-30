#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int max,t,n,k,l,s,sum;
char a[10];
char keys[10],target[10];
int checka()
    {
    int i,j,k=0;
    for(i=0;i<s;i++)
        {
        for(j=0;j<l&&(i+j)<s;j++)
            {
            if(a[i+j]!=target[j])
                break;
        }
        if(j==l)
            k++;
    }
    sum=sum+k;
    if(k>max)
        max=k;
    return 0;
}
int find(int i)
    {
    //printf("%d\n",i);
    int j;
    if(i>=s)
        {
        checka();
        return 0;
    }
    for(j=0;j<k;j++)
        {
        a[i]=keys[j];
        find(i+1);
    }
    return 0;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    scanf("%d",&t);
    double ans;
    int i;
    for(i=1;i<=t;i++)
        {
        max=0;
        sum=0;
        scanf("%d%d%d",&k,&l,&s);
        scanf("%s",keys);
        scanf("%s",target);
        find(0);
        ans=(double)sum;
        ans=ans/pow(k,s);
        ans=(double)max-ans;
        printf("Case #%d: %lf\n",i,ans);
    }
    return 0;
}

