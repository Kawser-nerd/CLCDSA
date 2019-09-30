#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main(){

    int a , b, k;

    scanf("%d%d%d", &a, &b, &k);

    int cnt = 0; //??????
    for (int i=110; i >= 1; i--){

        if (a % i == 0 && b % i  == 0){
            cnt++;
            if(cnt == k){
                cout << i <<endl;
                return 0;
            }
        }
    }
}