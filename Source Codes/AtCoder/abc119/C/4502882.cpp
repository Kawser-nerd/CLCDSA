#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include <iostream>
 
inline int min(int x, int y) {return x < y ? x : y;}
inline long min(long x, long y) {return x < y ? x : y;}
inline int max(int x, int y) {return x > y ? x : y;}
inline long max(long x, long y) {return x > y ? x : y;}
 
using namespace std;
 
int main() {
    int N, A, B, C;
    int l[8];
    cin >> N >> A >> B >> C;
    for (int i = 0; i < N; i++) {
        cin >> l[i];
    }

    int loop_num = 1;
    for (int i = 0; i < N; i++) {
        loop_num *= 4;
    }
    int min_cost = 100000000;
    for (int s = 0; s < loop_num; s++) {
        int tmp = s;
        int null_cnt = 0;
        int group[4] = {0, 0, 0, 0};
        for (int i = 0; i < N; i++) {
            group[tmp % 4] += l[i];
            if (tmp % 4 == 3) null_cnt++;
            tmp /= 4;
        }

        if (group[0] == 0 || group[1] == 0 || group[2] == 0) continue;

        int cost = (N - null_cnt - 3) * 10;
        cost += abs(group[0] - A);
        cost += abs(group[1] - B);
        cost += abs(group[2] - C);
        min_cost = min(min_cost, cost);
    }

    cout << min_cost << endl;
}