#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//standard
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define abs(a) ((a)>(0)?(a):-(a))



int main() {
    char s[200001];
    char a[200001];
    long len;
    long mark=0;
    
    scanf("%s",s);
    
    len = strlen(s);
    
    for (int i=0; i<len; i++) {
        if (s[i] == 'S'){
            mark++;
            a[mark] = 'S';
        }else{ // s[i] == 'T'
            if (a[mark] == 'S'){
                mark--;
            }else{
                mark++;
                a[mark] = 'T';
            }
        }
    }
    
    printf("\n%ld\n", mark);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^