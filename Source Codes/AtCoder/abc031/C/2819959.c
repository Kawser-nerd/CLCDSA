#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int max(int a, int b){
    if(a>b){
        return(a);
    } else {
        return(b);
    }
}

int min(int a, int b){
    if(a<b){
        return(a);
    } else {
        return(b);
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    int ans=-30000,aoki=0,takahashi=0,tmp=-300000,aokimax=-300000;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int k=min(i,j); k<=max(i,j); k++){
                if (i==j){
                    aoki=-300000;
                } else if((k-min(i,j))%2==0){
                    takahashi+=a[k];
                } else {
                    aoki+=a[k];
                }
            }
            if(aokimax<aoki){
                aokimax=aoki;
                tmp=takahashi;
            }
            aoki=0;
            takahashi=0;
        }
        if(tmp>ans){
            ans=tmp;
        }
        tmp=-300000;
        aokimax=-300000;
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:28:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^