#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int n;
    double tx[2],ty[2],t,v,x,y,d;
    scanf("%lf %lf %lf %lf %lf %lf",&tx[0],&ty[0],&tx[1],&ty[1],&t,&v);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&x,&y);
        d=sqrt((tx[0]-x)*(tx[0]-x)+(ty[0]-y)*(ty[0]-y))+sqrt((tx[1]-x)*(tx[1]-x)+(ty[1]-y)*(ty[1]-y));
        if(d<=v*t){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}