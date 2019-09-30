#include <stdio.h>
int main(void){
    char k[18][4] = {"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW","N","C"};
    int n[13] = {15,93,201,327,477,645,831,1029,1245,1467,1707,1959,18000};
    int deg,i,j,dis;
    scanf("%d%d",&deg,&dis);
    for(i=0;i<16;i++){
        if(deg<112.5+225*i)
            break;
    }
    for(j=0;j<12;j++){
        if(dis<n[j])
            break;
    }
    if(j==0) i=17;
    printf("%s %d\n",k[i],j);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&deg,&dis);
     ^