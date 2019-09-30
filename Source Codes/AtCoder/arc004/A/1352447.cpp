#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    double max = -1 ;
    int x[N], y[N];

    for(int i = 0; i < N; ++i){
            cin >> x[i] >> y[i];
    }

    for(int i = 1; i < N; ++i){
        for(int j = 0; j < i; ++j){
            double dx = x[i] - x[j];
            double dy = y[i] - y[j];
            double l = dx * dx + dy * dy;
            if(max < l) max = l;
        }
    }

    printf("%.5f\n", sqrt(max));
    
    return 0;
}