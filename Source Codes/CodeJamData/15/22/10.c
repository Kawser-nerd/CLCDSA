#include "stdio.h"
int t,k,r,c,n,i,min;
char select[16];
void findMin(int d, int u){
    int i,j,count;
    if(u>n||n-u>r*c-d){
        return;
    }else if(d>=r*c){
        for(i=count=0;i<r;i++){
            for(j=0;j<c;j++){
                if(select[i*c+j]){
                    if(j&&select[i*c+j-1]) count++;
                    if(r&&select[(i-1)*c+j]) count++;
                }
            }
        }
        if(count < min) min = count;
    }else{
        select[d] = 0;
        findMin(d+1, u);
        select[d] = 1;
        findMin(d+1, u+1);
    }
}
int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d%d%d",&r,&c,&n);
        min = 100000000;
        findMin(0,0);
        printf("Case #%d: %d\n", k, min);
    }
}
