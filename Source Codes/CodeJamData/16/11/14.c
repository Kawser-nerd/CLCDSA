//
//  main.c
//  ProblemA
//
//  Created by Tung Nguyen on 4/16/16.
//  Copyright © 2016 Tung Nguyen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef long long Int;

Int readInt(FILE *input){
    Int num;
    fscanf(input, "%lld", &num);
    return num;
}

void readIntArray(FILE *input, Int *array, Int count){
    for (Int i = 0; i < count; i++) {
        fscanf(input, "%llu", &array[i]);
    }
}

int main(int argc, const char * argv[]) {
    FILE *input = fopen("A-large.in.txt", "r");
    FILE *output = fopen("A-large.out.txt", "w");
    
    Int T = readInt(input);
    
    for (Int Case = 0; Case < T; Case++) {
        char S[1000];
        fscanf(input, "%s", S);
        
        
        char result[3000];
        int first = 1500;
        int last = 1500;
        
        result[first] = S[0];
        for (unsigned long i = 1; i < strlen(S); i++) {
            if (S[i] < result[first]) {
                last++;
                result[last] = S[i];
            }
            else{
                first--;
                result[first] = S[i];
            }
        }
        
        fprintf(output, "Case #%lld: ", Case + 1);
        for (int i = first; i <= last; i++) {
            fprintf(output, "%c", result[i]);
        }
        fprintf(output, "\n");
    }
    
    fclose(input);
    fclose(output);
    
    return 0;
}
