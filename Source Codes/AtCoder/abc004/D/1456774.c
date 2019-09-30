#include <stdio.h>

int FRight(int x,int start,int end){ //??????????x?????????start????????end
    if(end-x>=start){
        return x*((end-start)+(end-start-x+1))/2;
    }
    else if(end<start){
        return x*((start-end)+(start-end+x-1))/2;
    }
    else{
        int po=(end-start)*(end-start+1)/2;
        po+=(x-1+start-end)*(x+start-end)/2;
        return po;
    }
}

int FLeft(int x,int start,int end){
    return FRight(x,start,end+x-1);
}

int min(int a,int b){
    if(a>b)return b;
    return a;
}

int main(void){
    int R,G,B;
    int ans=1145141919;
    scanf("%d %d %d",&R,&G,&B);
    for(int i=-1000;i<1000;i++){ //i?R???
        for(int j=1000;j>i;j--){ //j?B?????????????????????????????????????????
            int karians=0;
            if(j-i>G){
             if(j>(int)((G-1)/2)&&-i>(int)((G-1)/2)){
                 karians+=(int)((G-1)/2)*(int)((G+1)/2);
                 if(G%2==0)karians+=G/2;
             }
             else karians+=min(FLeft(G,0,i+1),FRight(G,0,j-1));
             karians+=FRight(R,-100,i);
             karians+=FLeft(B,100,j);
             ans=min(ans,karians);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&R,&G,&B);
     ^