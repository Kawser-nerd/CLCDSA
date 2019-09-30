#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int main(void){
    int h,w,black=0;
    scanf("%d%d",&h,&w);
    char s[h][w+2];
    int cost[h*w][h*w];
    for (int i=0; i<h; i++){
        scanf("%s",s[i]);
    }
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if (s[i][j]=='#'){
                black++;
            }
        }
    }
    for (int i=0; i<h*w; i++){
        for (int j=0; j<h*w; j++){
            cost[i][j]=1e9;
        }
    }
    cost[0][0]=1;
    int count=0,x[h*w],y[h*w];
    x[0]=0,y[0]=0;
    for (int i=0; i<count+1; i++){
        if (s[x[i]-1][y[i]]=='.' && cost[x[i]-1][y[i]]>cost[x[i]][y[i]]+1){
            cost[x[i]-1][y[i]]=cost[x[i]][y[i]]+1;
            count++;
            x[count]=x[i]-1;
            y[count]=y[i];
        }
        if (s[x[i]+1][y[i]]=='.' && cost[x[i]+1][y[i]]>cost[x[i]][y[i]]+1){
            cost[x[i]+1][y[i]]=cost[x[i]][y[i]]+1;
            count++;
            x[count]=x[i]+1;
            y[count]=y[i];
        }
        if (s[x[i]][y[i]-1]=='.' && cost[x[i]][y[i]-1]>cost[x[i]][y[i]]+1){
            cost[x[i]][y[i]-1]=cost[x[i]][y[i]]+1;
            count++;
            x[count]=x[i];
            y[count]=y[i]-1;
        }
        if (s[x[i]][y[i]+1]=='.' && cost[x[i]][y[i]+1]>cost[x[i]][y[i]]+1){
            cost[x[i]][y[i]+1]=cost[x[i]][y[i]]+1;
            count++;
            x[count]=x[i];
            y[count]=y[i]+1;
        }
    }
    if (cost[h-1][w-1]==1e9){
        printf("-1\n");
    } else {
        printf("%d\n",h*w-black-cost[h-1][w-1]);
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s[i]);
         ^