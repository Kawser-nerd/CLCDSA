//
//  main.c
//  num3
//
//  Created by Dingjie Wang on 4/13/12.
//  Copyright 2012 asu. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int main ()
{
    FILE *in;
    FILE *out;
    in=fopen("/Users/dingjiewang/Desktop/coding/num3/C-large.in", "r");
    out=fopen("/Users/dingjiewang/Desktop/coding/num3/out.txt", "w");
    int i, j, k, h;
    int cs;
    long int n, m;
    long int a, b;
    int digit;
    int nc[7], mc[7];
    fscanf(in, "%d", &cs);
    long int num;
    long int nt;
    long int mp[7];
    int mpp;
    for(i=0;i<cs;i++){
        num=0;
        fscanf(in, "%ld %ld", &a, &b);
        digit=0;
        for(n=a;n<b;n++){
            digit=0;
            nt=n;
            for(j=0;j<7;j++){
                if(nt!=0){
                    digit++;
                }
                nc[j]=nt%10;
                mc[j]=0;
                nt=nt/10;
            }
            mpp=0;
            for(j=0;j<7;j++){
                mp[j]=0;
            }
            for(j=1;j<digit;j++){
                for(k=0;k<j;k++){
                    mc[digit-j+k]=nc[k];
                }
                for(k=0;k<digit-j;k++){
                    mc[k]=nc[j+k];
                }
                m=0;
                for(k=0;k<7;k++){
                    m=m+mc[k]*pow(10, k);
                }
                if(m<=b&&m>n){
                    for(h=0;h<mpp;h++){
                        if(m==mp[h]){
                            break;
                        }
                    }
                    if(h==mpp){
                    num++;
                    mp[mpp]=m;
                    mpp++;
                    }
                }
            }
        }
        fprintf(out, "Case #%d: %ld\n", i+1, num);
    }
    fclose(in);
    fclose(out);
}



