/*
 * main.c
 *
 *  Created on: 2019/03/06
 *      Author: family
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d;
    char yes[4] = "Yes\0";
    char no[4] = "No\0\0";
    char *ans;
    scanf("%d %d %d %d",&a,&b,&c, &d);
    if (abs(a - c) <= d) {
      ans = yes;
    } else if((abs(a-b) <= d) && (abs(b-c) <= d)) {
      ans = yes;
    } else {
      ans = no;
    }
    printf("%s\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d",&a,&b,&c, &d);
     ^