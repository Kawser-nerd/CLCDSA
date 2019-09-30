#include<stdio.h>

int v,used[40],check;

int Check(){
    int value[40]={0},i,j;
    value[0]=1;
    for(i=1;i<=v;i++){
        if(used[i]!=0){
            for(j=v;j>=0;j--){
                if(value[j]==1 && j+i<=v){
                    value[j+i]=1;
                }
            }
        }
    }
    for(i=1;i<=v;i++){
        if(value[i]==0){
            return 0;
        }
    }
    return 1;
}

void Choose(int num,int start){
    if(num==0){
        if(Check()==1){
            check=1;
        }
        return ;
    }
    int i;
    for(i=start;i<=v;i++){
        if(used[i]==0){
            used[i]++;
            Choose(num-1,i+1);
            if(check==1){
                return ;
            }
            used[i]--;
        }
    }
    return ;
}

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0-output.txt","w",stdout);
    int t,c,d,temp,i,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d %d",&c,&d,&v);
        for(j=1;j<=v;j++){
            used[j]=0;
        }
        for(j=0;j<d;j++){
            scanf("%d",&temp);
            used[temp]=2;
        }
        check=0;
        for(j=0;j<=v;j++){
            Choose(j,1);
            if(check==1){
                printf("Case #%d: %d\n",i,j);
                break;
            }
        }
    }
    return 0;
}
