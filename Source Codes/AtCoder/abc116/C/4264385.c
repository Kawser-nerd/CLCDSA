#include <stdio.h>

int fin(int h[],int N){
    int a=0;
    for(int i=0;i<N;i++){
       if(h[i]!=0) a++;
   }
   if(a == 0) return 1;
   else return 0;
}

void look(int h[],int N){
    for(int i=0;i<N;i++) printf("h[%d]:%d\n",i,h[i]);
}

int main(void){
    int N;
    scanf("%d",&N);
    int h[N];
    for(int i=0;i<N;i++) scanf("%d",&h[i]);
    
    int j,k,m,l,r,r_now,len,counter=0;
    
    if(fin(h,N)){
        printf("0");
        return 0;
    }
    
    while(1){
        
        l=0;
        r=0;
        r_now=0;
        len=0;
        
        for(j=0;j<N;j++){
            if(h[j] == 0) continue;
            for(k=j;k<N;k++){
                if(h[k] == 0){
                    r_now = k-1;
                    break;
                } else if(k == N-1) r_now=k;
            }
            if(r_now-j>=len){
                len = r_now-j;
                r=r_now;
                l=j;
            }
        }
        
        for(m=l;m<=r;m++) h[m]--;
        
        counter++;
        
        if(fin(h,N)){
            printf("%d",counter);
            return 0;
        }
        
        //printf("counter:%d\n",counter);
        //look(h,N);
    }
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:20:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<N;i++) scanf("%d",&h[i]);
                          ^