#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(){
    int N;
    cin >> N;
    int nums[N];
    double factor = 0;
    int sign = 1;
    for(int i = 0; i < N; ++i){ cin >> nums[i] ;}
    
    qsort(nums, N, sizeof(int), compare_int);

    for(int i = N - 1; i >= 0; --i){
        factor += sign * nums[i] * nums[i];
        sign *= -1;
    }
    printf("%.7f", factor * M_PI);
    return 0;
}