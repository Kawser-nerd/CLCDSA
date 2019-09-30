#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define NUM 2000000

vector<pair<int, int>> v;
int N;

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int p;
        scanf("%d", &p);
        v.push_back(make_pair(p, i));
    }

    sort(v.begin(), v.end());

    /*
    for(int i = 0; i < N; i++){
        printf("%d %d\n", v[i].first, v[i].second);
    }
    */

    int count_max = 1;
    int cnt = 1;

    for(int i = 1; i < N; i++){
        if(v[i - 1].second < v[i].second){
            cnt += 1;
        }else{
            count_max = max(cnt, count_max);
            cnt = 1;
        }
    }
    count_max = max(cnt, count_max);

    printf("%d\n", N - count_max);

}