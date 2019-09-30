#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    int n;
    scanf("%d",&n);
    char r[n+2];
    scanf("%s",r);
    double gpa=0;
    for (int i=0; i<n; i++){
        if (r[i]=='A'){
            gpa+=4;
        } else if (r[i]=='B'){
            gpa+=3;
        } else if (r[i]=='C'){
            gpa+=2;
        } else if (r[i]=='D'){
            gpa+=1;
        }
    }
    gpa=gpa/(double)n;
    printf("%1.10f\n",gpa);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",r);
     ^