/*
 * main.c
 *
 *  Created on: 2019/03/06
 *      Author: family
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int x;
    int i = 0;
    int j= 0;
    int ans = 0;
    int temp = 0;
    scanf("%d", &x);

    for(i = 1; i <= 31; i++) {
    	for( j = 2; j <= 10; j++) {
    		temp = pow(i,j);
    		if ((temp <= x) && (temp >= ans)) {
    			ans = temp;
    		}
    	}
    }
    printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &x);
     ^