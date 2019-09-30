#include<stdio.h>
#include<string.h>
char srx[1001][1001],t[1001];                   
int n,i,j,k;                           
int cmp(char a[],char b[])
{     
    int t=strlen(a);
    char c;
    for(k=0;k<t/2;k++)
    {c=a[k];
    a[k]=a[t-k-1];
    a[t-k-1]=c;}
    t=strlen(b);
    for(k=0;k<t/2;k++)
    {c=b[k];
    b[k]=b[t-k-1];
    b[t-k-1]=c;}
    int sry=strcmp(a,b);                  
    t=strlen(a);
    for(k=0;k<t/2;k++)
    {c=a[k];
    a[k]=a[t-k-1];
    a[t-k-1]=c;}
    t=strlen(b);
    for(k=0;k<t/2;k++)
    {c=b[k];
    b[k]=b[t-k-1];
    b[t-k-1]=c;}
    if(sry>=0)
    return 0;
    return 1;
}
int main()
{                      
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%s",srx[i]);    
    for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
    if(!cmp(srx[i],srx[j]))
    {strcpy(t,srx[i]);
    strcpy(srx[i],srx[j]);
    strcpy(srx[j],t);}
    for(i=0;i<n;i++)
    printf("%s\n",srx[i]);  
    return 0;                              
} ./Main.c: In function ‘main’:
./Main.c:35:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",srx[i]);    
     ^