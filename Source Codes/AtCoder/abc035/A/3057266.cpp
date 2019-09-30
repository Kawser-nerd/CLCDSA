#include <cstdio>

int main(){
    int w,h;
    scanf("%d %d",&w,&h);
    if(w / 4 * 3 == h){
        printf("4:3\n");
    }else{
        printf("16:9\n");
    }

    return 0;
}