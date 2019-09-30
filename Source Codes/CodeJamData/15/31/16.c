#include<stdio.h>

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large-output.txt","w",stdout);
    int t,r,c,w,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d %d",&r,&c,&w);
        printf("Case #%d: %d\n",i,r*(c/w)+w-1+(c%w!=0));
    }
    return 0;
}
