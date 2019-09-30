/*
 
 Google Code Jam Round 1C
 May 8, 2016
 
 Jesse Pritchard
 Public contact: chaserdevelopment@gmail.com
 
 Problem D
 
 */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

long max(long* arr, int N) {
    int i;
    long large = 0;
    for (i = 0; i < N; i++) {
        if (arr[i] > large) {
            large = arr[i];
        }
    }
    return large;
}

long neq(long* arr, int N, long match) {
    int i;
    long num = 0;
    for (i = 0; i < N; i++) {
        if (arr[i] == match) {
            num++;
        }
    }
    return num;
}

int fmatch(long* arr, int N, long match) {
    int i;
    for (i = 0; i < N; i++) {
        if (arr[i] == match) {
            return i;
        }
    }
    return -1;
}


int main() {
    long num, iii;
    scanf(" %ld", &num);
    for (iii = 0; iii < num; iii++) {
        
        int N;
        scanf(" %d", &N);
        
        long P[N];
        int i;
        for (i = 0; i < N; i++) {
            scanf(" %ld", &P[i]);
        }
        
        printf("Case #%ld:", iii + 1);
        
        long M = max(P, N);
        while (M != 0) {
            long num = neq(P, N, M);
            if (num % 2) {
                int first = fmatch(P, N, M);
                if (first == -1) {
                    printf("ERROR!");
                    return -1;
                }
                else {
                    P[first]--;
                    printf(" %c", 'A' + first);
                }
            }
            else {
                int first = fmatch(P, N, M);
                if (first == -1) {
                    printf("ERROR!");
                    return -1;
                }
                else {
                    P[first]--;
                    printf(" %c", 'A' + first);
                }
                
                first = fmatch(P, N, M);
                if (first == -1) {
                    printf("ERROR!");
                    return -1;
                }
                else {
                    P[first]--;
                    printf("%c", 'A' + first);
                }
            }
            M = max(P, N);
        }
        
        printf("\n");
    }
    return 0;
}

