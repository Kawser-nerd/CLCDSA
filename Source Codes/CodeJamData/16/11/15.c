/* 
 
Google Code Jam Round 1A
April 15, 2016

Jesse Pritchard
Public contact: chaserdevelopment@gmail.com
 
Problem A

*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

#define MAX_LEN 10000

int main() {
    long num, iii;
    scanf(" %ld", &num);
    for (iii = 0; iii < num; iii++) {
        
        char* S = malloc(sizeof(char) * (MAX_LEN + 1));
        scanf(" %[A-Z]", S);
        
        char* buf = malloc(sizeof(char) * (MAX_LEN * 2 + 2));
        char* ptr = buf + MAX_LEN;
        char* leftptr = ptr;
        char* rightptr = ptr;
        
        *ptr = *S;
        
        int i;
        for (i = 1; i < strlen(S); i++) {
            if (S[i] >= *leftptr) {
                leftptr--;
                *leftptr = S[i];
            }
            else {
                rightptr++;
                *rightptr = S[i];
            }
        }
        
        rightptr++;
        *rightptr = '\0';
        
        printf("Case #%ld: %s\n", iii + 1, leftptr);
        
        free(S);
        free(buf);
    }
    return 0;
}

