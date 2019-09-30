//
//  main.cpp
//  robo526
//
//  Created by takumi on 2017/05/26.
//  Copyright © 2017? takumi. All rights reserved.
//

#include <stdio.h>


int main() {
    int l,a[50]={0},aoki=0,takahasi=0,takahasimax=-1000000,aokimax=-10000000,mmax=0;
    //printf(" ");
    scanf("%d",&l);
    for(int i =0; i< l; i++){
        scanf("%d",&a[i]);
    }
    for (int k = 0; k < l; k ++){//????k?????
        for(int m = 0; m < k; m++){//???m?????(m<k)
            for(int o = m+1; o <= k; o+=2){//???m???(m<k)
                aoki = aoki + a[o];
            }
            if (aokimax < aoki){
                aokimax = aoki;
                mmax = m;
            }
            aoki = 0;
        }
        for(int m =k+1; m < l;m++ ){//???m?????(k<m)
            for(int n = k+1; n <= m; n+=2){//?????m???
                aoki = aoki + a[n];
            }
            if (aokimax < aoki){
                aokimax = aoki;
                mmax = m;
            }
            aoki = 0;
        }
        //???????

        if(k<mmax){
            for(int p = k; p <= mmax; p+=2){
                takahasi = takahasi + a[p];
                //printf("+%d\n",a[p]);
            }
            if (takahasimax < takahasi){
                takahasimax = takahasi;
            }
//               printf("%d %d %d\n",mmax,k,takahasi);
            takahasi = 0;
        }else{
            for(int q = mmax; q <= k; q+=2){
                takahasi = takahasi + a[q];
            }
            if (takahasimax < takahasi){
                takahasimax = takahasi;
            }
             //   printf("%d %d %d\n",mmax,k,takahasi);
            takahasi = 0;
        }
        aokimax = -1000000;
    }
    printf("%d\n",takahasimax);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&l);
     ^
./Main.c:17:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^