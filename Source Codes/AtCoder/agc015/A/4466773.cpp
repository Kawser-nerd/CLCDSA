#include <cstdio>
int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(n==1){
        if(a!=b)  printf("0\n");
        else  printf("1\n");
    }
    else{
        if(a>b)  printf("0\n");
        else printf("%lld\n",(long long)(n-2)*(b-a)+1);
    }

    return 0;
}