/*
TASK: A-vectors
LANG: C++
*/

#include<stdio.h>
#include<stdlib.h>

FILE *fin,*fout;

long long a[100000],b[100000];
int e[100000],f[100000];
int n;

int comparee(const void *x, const void *y)
{
    if(a[*(int*)x] > a[*(int*)y]) return 1;
    else if(a[*(int*)x] < a[*(int*)y]) return -1;
    else return 0;
}
int comparef(const void *x, const void *y)
{
    if(b[*(int*)x] < b[*(int*)y]) return 1;
    else if(b[*(int*)x] > b[*(int*)y]) return -1;
    else return 0;
}


int main()
{
    int ss,sss;
    long long ans;
    int i,j;
    fin = fopen("A-large.in","r");
    fout = fopen("A-large.out","w");
    fscanf(fin,"%d",&sss);
    for(ss=1;ss<=sss;ss++)
    {
        printf("--%d--\n",ss);
        fscanf(fin,"%d",&n);
        for(i=0;i<n;i++)
        {
            fscanf(fin,"%lld",&a[i]);
            e[i] = i;
        }
        qsort(e,n,sizeof(e[0]),comparee);
        for(i=0;i<n;i++)
        {
            fscanf(fin,"%lld",&b[i]);
            f[i] = i;
        }
        qsort(f,n,sizeof(f[0]),comparef);
        ans = 0;
        for(i=0;i<n;i++)
        {
            ans = ans + a[e[i]]*b[f[i]];
        }
        fprintf(fout,"Case #%d: %lld\n",ss,ans);
    }
    system("PAUSE");
    return 0;
}
