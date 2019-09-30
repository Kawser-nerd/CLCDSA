#include <stdio.h>

long tree[1100][1100],n;

long findep(long k,long r){
    long i,md1=0,md2=0,tmp;
    for (i=1;i<=tree[k][0];i++){
        if (tree[k][i]!=r){
            tmp=findep(tree[k][i], k);
            if (tmp>md1){
                md2=md1;
                md1=tmp;
            }
            else if (tmp>md2){
                md2=tmp;
            }
        }
    }
    if (md1!=0&&md2!=0)
        return md1+md2+1;
    else
        return 1;
}

int main(){
    long t,tt,i,j,k,x,y,max,ans,tmp;
    
    freopen("B-large.in.txt", "r",stdin);
    freopen("B-large.out.txt", "w",stdout);

    scanf("%ld",&tt);
    for (t=1;t<=tt;t++){
        scanf("%ld",&n);
        for (i=1;i<=n;i++){
            tree[i][0]=0;
        }
        for (i=1;i<n;i++){
            scanf("%ld%ld",&x,&y);
            tree[x][0]++;
            tree[x][tree[x][0]]=y;
            tree[y][0]++;
            tree[y][tree[y][0]]=x;
        }
        max=0;
        for (i=1;i<=n;i++){
            tmp=findep(i,-1);
            if (tmp>max)
                max=tmp;
        }
        printf("Case #%ld: %ld\n",t,n-max);
    }
    return 0;
}

