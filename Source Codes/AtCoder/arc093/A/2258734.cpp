#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
    int N;
    int A[100010];
    int reduceTime[100010];

    scanf("%d",&N);
    A[0] = 0;
    A[N+1] = 0;
    for(int i = 1; i <= N; i++){
        scanf("%d",&A[i]);
    }

    int cost = 0;

    for(int i = 1; i <= N; i++){
        cost += abs(A[i-1]-A[i]);
        reduceTime[i] = abs(A[i-1]-A[i]) + abs(A[i]-A[i+1]) - abs(A[i-1]-A[i+1]);
//        printf("%d\n",cost);

    }
    cost += abs(A[N]);

//    printf("%d\n",cost);

    for(int i = 1; i <= N; i++){
//        printf("%d ", reduceTime[i]);
        printf("%d\n",cost-reduceTime[i]);
    }

/*
    for(int i = 0; i < N; i++){
        p = 0;
        int cost = 0;
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            cost += abs(p-A[j]);
            p = A[j];
        }
        cost += abs(p);
        printf("%d\n",cost);
    }
*/

    return 0;

}