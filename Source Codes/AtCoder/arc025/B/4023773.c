#include <stdio.h>

#define MAX_COL (101) /* ???? */
#define MAX_ROW (101) /* ???? */

/* ?????2?????? */
void print2d(int h, int w, int ary[MAX_COL][MAX_COL]);

void accum(int n, int input[MAX_COL], int output[MAX_COL]); /* ??? */
void accum2d(int h, int w, int input[MAX_COL][MAX_COL], int output[MAX_COL][MAX_COL]); /* 2????? */

int main(){
    int sum_ary[MAX_COL][MAX_COL];  /* ??????????2????? */
    int h,w,c[MAX_COL][MAX_COL];    /* ?? */
    int hs,ws,he,we;                /* ????????(h,w?????????/????) */
    int max_cell_num;               /* ??????? */
    int cell_num;                   /* ??? */
    int sum;                        /* ????? */

    /* ?? */
    scanf("%d %d",&h,&w);
    for(hs=1;hs<=h;hs++){
        for(ws=1;ws<=w;ws++){
            scanf("%d",&(c[hs][ws]));
            /* ???????????? */
            if((hs+ws)%2==0){
                c[hs][ws]=-c[hs][ws];
            }
        }
    }

    /* ???????????????????????0??????????? */
    for(hs=0;hs<=h;hs++){
        c[hs][0] = 0;
    }
    for(ws=0;ws<=w;ws++){
        c[0][ws] = 0;
    }

    /* ????? */
    accum2d(h+1,w+1,c,sum_ary);

    /* ???????? */
    /* ?????????(???(hs,ws),???(he,we)?????)???? */
    /* ????????????????????????????0?????????? */
    max_cell_num = 0;
    
    for(hs=1;hs<=h;hs++){
        for(ws=1;ws<=w;ws++){
            for(he=hs;he<=h;he++){
                for(we=ws;we<=w;we++){
                    /* ????????? */
                    sum = sum_ary[he][we] - sum_ary[hs-1][we] - sum_ary[he][ws-1] + sum_ary[hs-1][ws-1];
                    if(sum == 0){
                        /* ???????? */
                        cell_num = (he-hs+1)*(we-ws+1);
                        if(max_cell_num < cell_num){
                            max_cell_num = cell_num;
                        }
                    }
                }
            }
        }
    }

    /* ?? */
    printf("%d\n",max_cell_num);
}


/* ??? */
/* ?? n ??? input ?????????????output???? */
void accum(int n, int input[MAX_COL], int output[MAX_COL]){
    int i;
    output[0] = input[0];
    for(i=1;i<n;i++){
        output[i] = output[i-1] + input[i];
    }
}

/* 2????? */
/* ?? h?? w ?2???? input?????????????2????output???? */
void accum2d(int h, int w, int input[MAX_COL][MAX_COL], int output[MAX_COL][MAX_COL]){
    int hi,wi;
    accum(w,input[0],output[0]);
    for(hi=1;hi<h;hi++){
        accum(w,input[hi],output[hi]);
        for(wi=0;wi<w;wi++){
            output[hi][wi] += output[hi-1][wi];
        }
    }
}

/* ?????2?????? */
void print2d(int h, int w, int ary[MAX_COL][MAX_COL]){
    int hi,wi;
    for(hi=0;hi<h;hi++){
        for(wi=0;wi<w;wi++){
            printf("%d ",ary[hi][wi]);
        }
        printf("\n");
    }
} ./Main.c: In function ‘main’:
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&h,&w);
     ^
./Main.c:24:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&(c[hs][ws]));
             ^