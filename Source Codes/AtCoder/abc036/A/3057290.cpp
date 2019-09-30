#include <cstdio>

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(b % a == 0){
        printf("%d\n",b / a);
    }else{
        printf("%d\n",b / a + 1);
    }

    return 0;
}