#include<stdio.h>
int main(void){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int i,j,ti,num,q[100000],rate,ans1,ans2,total;
    scanf("%d",&ti);
    for(i=1;i<=ti;i++){
        scanf("%d",&num);
        for(j=0;j<num;j++)
            scanf("%d",&q[j]);
        ans1=0;
        ans2=0;
        rate=0;
        for(j=1;j<num;j++){
            if(q[j]<q[j-1]){
                ans1+=q[j-1]-q[j];
                if((q[j-1]-q[j])>rate)
                    rate=q[j-1]-q[j];
            }
        }
        total=q[0];
        for(j=1;j<num;j++){
            if(total>=rate)
                ans2+=rate;
            else
                ans2+=total;
            total=q[j];

        }
        printf("Case #%d: %d %d\n",i,ans1,ans2);
    }
    return 0;
}
