#include<stdio.h>
long buffer[100000000];
void merge(long a[],long left,long right){
    if(left<right){
        long axis=(left+right)/2,i=left,p=0,q=left,r=0;
        merge(a,left,axis);
        merge(a,axis+1,right);
        while(i<=axis)buffer[p++]=a[i++];
        while(i<=right && r<p)a[q++]=(a[i]<=buffer[r])?a[i++]:buffer[r++];
        while(r<p)a[q++]=buffer[r++];
    }
}
int main(void){
    long N,X;
    scanf("%ld%ld",&N,&X);
    long Xi[N];
    for(int i=0;i<N;i++){
        scanf("%ld",&Xi[i]);
    }
    for(int i=0;i<N;i++){
        Xi[i]=Xi[i]-X;
        if(Xi[i]<0){
            Xi[i]=-1*Xi[i];
        }
    }
    merge(Xi,0,N-1);
    long D=Xi[0];
    long c=0;
    long a=0;
    while(c!=1){
        for(int i=0;i<N;i++){
            a=0;
            if((Xi[i]%D)!=0){
                a=1;
                D-=1;
                break;
            }
        }
        if(a==0){c=1;}
    }
    printf("%ld\n",D);
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld",&N,&X);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld",&Xi[i]);
         ^