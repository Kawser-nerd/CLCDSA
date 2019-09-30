#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(){

    int N;
    int mypow = 10;
    int total = 0;

    cin >> N;
    int N_org = N;

    for(int i = 1; i <=8; i++){
        total += N % mypow;
        N = N / mypow;
    }
    if(  N_org % total == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}