#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    char s[25];
    scanf("%s",s);
    if (s[1]=='W'){
        if (s[6]=='B'){
            printf ("Mi\n");
        } else {
            printf ("Si\n");
        }
    } else {
        if (s[3]=='W'){
            if (s[9]=='W'){
                printf ("Re\n");
            } else {
                printf ("La\n");
            }
        } else if (s[5]=='B'){
            printf ("Fa\n");
        } else {
            if (s[10]=='B'){
                printf ("Do\n");
            } else {
                printf ("So\n");
            }
        }
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^