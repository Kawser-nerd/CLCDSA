//
//  main.c
//  num4
//
//  Created by Dingjie Wang on 4/13/12.
//  Copyright 2012 asu. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int max(int a, int b);
int max(int a, int b){
    int num;
    if(a>=b){
        num=a;
    }
    else num=b;
    return num;
}
int main ()
{
    FILE *in;
    FILE *out;
    in=fopen("/Users/dingjiewang/Desktop/coding/num4/D-small-attempt2.in", "r");
    out=fopen("/Users/dingjiewang/Desktop/coding/num4/out.txt", "w");
    int i, j, k, p, q;
    int cs;
    int h, w, dis;
    float a, b, c, d;
    int x, y;
    float lx, ly;
    char read;
    char dump;
    int bk;
    int bk1;
    int po[10000][2];
    int num;
    int a1, b1, c1, d1;
    fscanf(in, "%d", &cs);
    int divider;
    for(i=0;i<cs;i++){
        bk=0;
        num=0;
        fscanf(in, "%d %d %d", &h, &w, &dis);
        fscanf(in, "%c", &dump);
        for(j=0;j<10000;j++){
            po[j][0]=0;
            po[j][1]=0;
        }
        for(j=0;j<h;j++){
            for(k=0;k<w;k++){
                fscanf(in, "%c", &read);
                if(read=='X'){
                    bk=1;
                    a=j-0.5;
                    b=h-j-1.5;
                    c=k-0.5;
                    d=w-k-1.5;
                }
            }
            fscanf(in, "%c", &dump);
        }
        lx=w-2;
        ly=h-2;
        for(j=0;j<=dis/lx+1;j++){
            for(k=0;k<=dis/ly+1;k++){
                for(a1=0;a1<=1;a1++){
                    for(b1=0;b1<=1;b1++){
                        for(c1=0;c1<=1;c1++){
                            for(d1=0;d1<=1;d1++){
                x=pow(-1,a1)*2*j*lx+pow(-1,b1)*c-c;
                y=pow(-1,c1)*2*k*ly+pow(-1,d1)*a-a;
                                divider=1;
                if(pow(x, 2)+pow(y, 2)<=pow(dis, 2)&&(pow(x, 2)+pow(y, 2))!=0){
                    for(p=2;p<=dis;p++){
                        bk1=0;
                        if(x%p==0&&y%p==0){
                            for(q=0;q<num;q++){
                                if(x/p==po[q][0]&&y/p==po[q][1]){
                                    bk1=1;
                                    break;
                                }
                                else{
                                    divider=p;
                                }
                            }
                            if(bk1==1){
                                break;
                            }
                        }
                        if(x%p==0&&y%p==0&&num==0){
                            divider=p;
                        }
                    }
                    if(p==dis+1){
                        for(q=0;q<num;q++){
                            if(po[q][0]==x/divider&&po[q][1]==y/divider){
                                break;
                            }
                        }
                        if(q==num){
                            po[num][0]=x/divider;
                            po[num][1]=y/divider;
                            num++;
                        }
                    }
                }
                            }
                        }
                    }
                }

            }
        }
        fprintf(out, "Case #%d: %d\n", i+1, num);
    }
    fclose(in);
    fclose(out);
}

