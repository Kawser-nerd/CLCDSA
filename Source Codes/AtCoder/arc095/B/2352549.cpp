#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main(void){
    int n;
    scanf("%d", &n);

    vector<int> v1;

    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        v1.push_back(num);
    }
    sort(v1.begin(), v1.end());

    int n_ = v1[n - 1];
    int diff = 1000000001;
    int index;
    for(int i = 0; i < n; i++){
        if(diff > abs(n_ - v1[i] * 2)){
            diff = abs(n_ - v1[i] * 2);
            index = i;
        }
    }

    printf("%d %d\n", n_, v1[index]);

    return 0;

}