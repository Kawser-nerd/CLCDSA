/*
 * main.c
 *
 *  Created on: 2019/03/24
 *      Author: family
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char S[100001] = {0};
int l[100001] = {0};
int r[100001] = {0};
int d[100001] = {0};

void checkAC(int n)
{
    int i;
    int count = 0;
    for(i = 0; i < n; i++){
        if((S[i] == 'A') && (S[i+1] == 'C')){
            count++;
        }
        d[i] = count;
        //printf("%d",d[i]);
    }
    //printf("\n");
    return;
}

int main()
{
    int N, Q;
    int i = 0;
    int start = 0;
    int end = 0;
    int ans = 0;
    scanf("%d %d", &N, &Q);
    scanf("%s",S);
    for(i = 0; i < Q; i++) {
        scanf("%d %d", &l[i], &r[i]);
    }

    // AC??
    checkAC(N);
    for(i = 0; i < Q; i++) {
        start = l[i]-1;
        end = r[i]-2;
        ans = d[end];
        if(start > 0) {
            ans -= d[start-1];
        } else {
            //
        }
        //printf("end=%d start=%d\n",d[end], d[start]);
        printf("%d\n",ans);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:40:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &Q);
     ^
./Main.c:41:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",S);
     ^
./Main.c:43:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &l[i], &r[i]);
         ^