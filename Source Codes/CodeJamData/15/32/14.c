#include<stdio.h>

int k,l,s,num,max,ans;
char keyboard[150],target[150],temp[150];

int Check(int start){
    if(start+l>s){
        return 0;
    }
    int i;
    for(i=start;i<start+l;i++){
        if(temp[i]!=target[i-start]){
            return 0;
        }
    }
    return 1;
}

int Add(){
    int i,j=0;
    for(i=0;i<s;i++){
        if(Check(i)==1){
            j++;
        }
    }
    return j;
}

void Run(int now){
    int i;
    if(now==s){
        i=Add();
        ans+=i;
        if(i>max){
            max=i;
        }
        return ;
    }
    for(i=0;i<k;i++){
        temp[now]=keyboard[i];
        Run(now+1);
    }
    return ;
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0-output.txt","w",stdout);
    int t,i,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d %d %s %s",&k,&l,&s,keyboard,target);
        num=1;
        for(j=0;j<s;j++){
            num*=k;
        }
        ans=0;
        max=0;
        Run(0);
        printf("Case #%d: %f\n",i,1.0*(max*num-ans)/num);
    }
    return 0;
}
