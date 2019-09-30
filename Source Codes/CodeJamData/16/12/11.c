//
//  main.c
//  ProblemB
//
//  Created by Tung Nguyen on 4/16/16.
//  Copyright © 2016 Tung Nguyen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
    FILE *input = fopen("B-large.in.txt", "r");
    FILE *output = fopen("B-large.out.txt", "w");
    
    Int T = readInt(input);
    
    for (Int Case = 0; Case < T; Case++) {
        Int N = readInt(input);
        
        bool seen[2500];
        bool take[2500];
        for (Int i = 0; i < 2500; i++) {
            seen[i] = false;
            take[i] = false;
        }
        
        for (Int i = 0; i < N * 2 - 1; i++) {
            for (Int j = 0; j < N; j++) {
                Int height = readInt(input);
                take[height - 1] = true;
                seen[height - 1] = !seen[height - 1];
            }
        }
        
        fprintf(output, "Case #%lld:", Case + 1);
        for (Int i = 0; i < 2500; i++) {
            if (take[i] && seen[i]) {
                fprintf(output, " %lld", i + 1);
            }
        }
        fprintf(output, "\n");
    }
    
    fclose(input);
    fclose(output);
    
    return 0;
}
