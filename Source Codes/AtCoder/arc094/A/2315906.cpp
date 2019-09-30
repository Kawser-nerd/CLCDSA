#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    int num[3];
    for(int i = 0; i < 3; i++){
        scanf("%d", &num[i]);
    }

    int max_num = max(num[0], max(num[1], num[2]));
    
    int a = max_num - num[0];
    int b = max_num - num[1];
    int c = max_num - num[2];

    int sum = a/2 + b/2 + c/2;

    int rem_sum = a % 2 + b % 2 + c % 2;

    if(rem_sum == 1){
        sum += 2;
    }else if(rem_sum == 2){
        sum += 1;
    }

    printf("%d\n", sum);

    return 0;
}