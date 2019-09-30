#include<stdio.h>
#include<stdlib.h>

int asc(const void *x, const void *y) {
	const int* a=(const int*)x;
	const int* b=(const int*)y;
	if(*a>*b)return 1;
	if(*a<*b)return -1;
	return 0;
}

int main(){

    int kids;
    int candy_max;
    int array[128] = {0};
    int happy = 0;
    int pointer = 0;
    int num;

    scanf("%d %d\n",&kids,&candy_max);
    int candy = candy_max;

    for(int i=0; i<kids; i++){
        scanf("%d",&array[i]);
    }

    //sort
    qsort( array, kids, sizeof(array[0]), asc);

    //degug
    //printf("degug:");
    //for(int i=0; i<kids; i++){
    //    printf("%d ", array[i]);
    //}
    //printf("\n");

    //candy?????????????
    for(int i=0; i < kids; i++){
        candy -= array[i];
        if(candy == 0){
            happy++;
            printf("%d",happy);
            return 0;
        } 
        if(candy <= 0){
            printf("%d",happy);
            return 0;
        }
        happy++;
    }
    
    if(candy > 0 && candy != candy_max){
        happy--;
        printf("%d",happy);
        return 0;
    }

    printf("0");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d\n",&kids,&candy_max);
     ^
./Main.c:25:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&array[i]);
         ^