#include <iostream>
#include<cstdio>
using namespace std;

int main(){
    int N,box;
    scanf("%d",&N);
    int num[60] = {0},cnt = 0;
    for(int i = 0;i < N; i++){
        scanf("%d",&box);
        for(int j = 0; j < N; j++){
            if(box <= num[j]){
                num[j] = box;
                break;
            }
            if(num[j] == 0){
                num[j] = box;
                cnt++;
                break;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}