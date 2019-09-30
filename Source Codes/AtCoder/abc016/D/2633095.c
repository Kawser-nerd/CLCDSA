#include <stdio.h>
void Swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int calc(int x1, int y1, int x2, int y2, int diffX, int diffY){
    //printf("(%d-%d)*(%d-%d)-(%d-%d)*(%d-%d)\n",x1,diffX,y2,diffY,x2,diffX,y1,diffY);
    return (x1-diffX)*(y2-diffY)-(x2-diffX)*(y1-diffY);
}

int main(){
    int ax,ay,bx,by;
    int n;
    scanf("%d %d %d %d",&ax,&ay,&bx,&by);
    scanf("%d",&n);
    int ab[101][2];
    int i;
    for(i=0;i<n;i++){
        scanf("%d %d",&ab[i][0],&ab[i][1]);
    }
    ab[n][0]=ab[0][0];
    ab[n][1]=ab[0][1];
    int cnt=0;
    for(i=0;i<n;i++){
        long long area1, area2;
        //puts("");
        area1=calc(ax,ay,ab[i][0],ab[i][1],bx,by);
        area2=calc(ax,ay,ab[i+1][0],ab[i+1][1],bx,by);
        //printf("area1=%lld, area2=%lld\n",area1, area2);
        if(area1*area2>=0)continue;
        area1=calc(ax,ay,ab[i][0],ab[i][1],ab[i+1][0],ab[i+1][1]);
        area2=calc(bx,by,ab[i][0],ab[i][1],ab[i+1][0],ab[i+1][1]);
        //printf("area1=%lld, area2=%lld\n",area1, area2);
        if(area1*area2>=0)continue;
        cnt++;
    }
    printf("%d\n",cnt/2+1);
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d",&ax,&ay,&bx,&by);
     ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:20:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&ab[i][0],&ab[i][1]);
         ^