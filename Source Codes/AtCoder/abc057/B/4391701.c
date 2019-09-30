#include<stdio.h>

int minmin(int a,int b,int c,int d);

int main(void)
{
        int n,m,i,j,min,tmp,jj;
        int a[50],b[50],c[50],d[50];

        scanf("%d%d",&n,&m);

        for(i=0;i<n;i++)
                scanf("%d%d",&a[i],&b[i]);
        for(i=0;i<m;i++)
                scanf("%d%d",&c[i],&d[i]);


        for(i=0;i<n;i++){
                tmp = minmin(a[i],b[i],c[0],d[0]);
                jj = 1;
                for(j=1;j<m;j++){
                        min = minmin(a[i],b[i],c[j],d[j]);
                        if(tmp>min){
                                tmp = min;
                                jj = j+1;
                        }
                }
                printf("%d\n",jj);
        }

        return 0;
}
int minmin(int a,int b,int c,int d)
{
        int min;
        if(c>a)
                min = c - a;
        else
                min =a-c;
        if(d>b)
                min +=d-b;
        else
                min +=b-d;

        return min;
} ./Main.c: In function ‘main’:
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&n,&m);
         ^
./Main.c:13:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%d%d",&a[i],&b[i]);
                 ^
./Main.c:15:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%d%d",&c[i],&d[i]);
                 ^