#include <stdio.h>
#include <stdlib.h>

int energy(int emax, int e, int r, int n, int pos, int* v){
    if(pos>n)return 0;
    int i,val,max=0;
    for(i=0;i<=e;i++){
        val = i*v[pos];
        int h=e-i+r;
        if(h>emax)h=emax;
        val = val + energy(emax,h , r,n,pos+1,v);
        if(max<val)max=val;
    }
    return max;
}

int main(){

    int cases;
    scanf("%d",&cases);

    int v[100];
    int i,emax,n,r,j,val;
    for(i=1;i<=cases;i++){
        scanf("%d",&emax);
        scanf("%d",&r);
        scanf("%d",&n);
        for(j=1;j<=n;j++)
            scanf("%d",&v[j]);

        val = energy(emax,emax,r,n,1,v);
        printf("Case #%d: %d\n",i,val);
    }

    return 0;
}
