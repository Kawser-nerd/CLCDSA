//
//  main.c
//  num2
//
//  Created by Dingjie Wang on 4/13/12.
//  Copyright 2012 asu. All rights reserved.
//

#include <stdio.h>
int main ()
{
    FILE *in;
    FILE *out;
    in=fopen("/Users/dingjiewang/Desktop/coding/num2/B-large.in", "r");
    out=fopen("/Users/dingjiewang/Desktop/coding/num2/out.txt", "w");
    int i, j, k, h;
    int cs;
    int n, s, p;
    int t[100];
    int num, su;
    fscanf(in, "%d", &cs);
    for(i=0;i<cs;i++){
        num=0;
        su=0;
        for(j=0;j<100;j++){
            t[j]=0;
        }
        fscanf(in, "%d %d %d", &n, &s, &p);
        for(j=0;j<n;j++){
            fscanf(in, "%d", &t[j]);
        }
        for(j=0;j<n;j++){
            if(p>1){
            if(3*p-2<=t[j]){
                num++;
            }
            else{ if(3*p-4<=t[j]&&su<s){
                num++;
                su++;
            }
            }
            }
            else{
                if(t[j]>=p){
                    num++;
                }
            }
        }
        fprintf(out, "Case #%d: %d\n", i+1, num);
    }
    fclose(in);
    fclose(out);
}

