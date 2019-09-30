#include <cstdio>

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int ans = 0;
    if(a <= b){
        printf("%d",c / a);
    }else{
        printf("%d",c / b);
    }
    printf("\n");

    return 0;
}