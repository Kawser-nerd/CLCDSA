#include<stdio.h>

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large-output.txt","w",stdout);
    int t,n,in[1000],d,x,y,i,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        d=0;
        x=0;
        y=0;
        scanf("%d %d",&n,&in[0]);
        for(j=1;j<n;j++){
            scanf("%d",&in[j]);
            if(in[j-1]>in[j]){
                x+=(in[j-1]-in[j]);
            }
            if(in[j-1]-in[j]>d){
                d=in[j-1]-in[j];
            }
        }
        for(j=0;j<n-1;j++){
            if(in[j]<d){
                y+=in[j];
            }
            else{
                y+=d;
            }
        }
        printf("Case #%d: %d %d\n",i,x,y);
    }
    return 0;
}
