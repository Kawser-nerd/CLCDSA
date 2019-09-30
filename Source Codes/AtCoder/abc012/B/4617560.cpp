#include<cstdio>
using namespace std;
int main(){
    int n,x[3];
    scanf("%d",&n);
    x[2]=n%60;
    x[1]=n%3600/60;
    x[0]=n/3600;
    for(int i=0;i<3;i++){
        if(x[i]<10){
            printf("0");
        }
        printf("%d",x[i]);
        if(i<2){
            printf(":");
        }
        else{
            printf("\n");
        }
    }
}