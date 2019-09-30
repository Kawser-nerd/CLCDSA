#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;


int main(void){
    int n;
    scanf("%d", &n);
    
    vector<int> v1;
    vector<int> v2;
    int num;
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        v1.push_back(num);
        v2.push_back(num);
    }
    sort(v2.begin(), v2.end());

    for(int i = 0; i < n; i++){
        if(v1[i] < v2[n / 2]){
            printf("%d\n", v2[n / 2]);
        }else{
            printf("%d\n", v2[n / 2 - 1]);
        }
    }

    return 0;
}