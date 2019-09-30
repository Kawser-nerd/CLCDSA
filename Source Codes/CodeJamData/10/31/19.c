#include <stdio.h>
#include <stdlib.h>


int T,N,a[1001][2],sonuc;
int intersect(int l,int j)
{
    if(a[l][1]-a[l][0]==a[j][1]-a[j][0]) return 0;
    if(a[j][0]>=a[l][0] && a[l][1]>=a[j][1]) return 1;
    if(a[l][0]>=a[j][0] && a[j][1]>=a[l][1]) return 1;
    return 0;
}
int main(void)
{
    int i,j,l;
    FILE *in,*out;
    in=fopen("A-small.in","r");
    out=fopen("A-small.out","w");
    fscanf(in," %d",&T);
    for(i=1;i<=T;i++)
    {
        sonuc=0;
        fscanf(in," %d",&N);
        for(j=0;j<N;j++)
        {
            fscanf(in," %d %d",&a[j][0],&a[j][1]);
            for(l=0;l<j;l++)
            {
                if(intersect(l,j)) sonuc++;
            }
        }
        fprintf(out,"Case #%d: %d\n",i,sonuc);
    }
    fclose(in);
    fclose(out);
    return 0;
}
