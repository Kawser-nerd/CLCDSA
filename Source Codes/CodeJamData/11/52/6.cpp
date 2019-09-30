/**********************************************************************
Author: hanshuai
Created Time:  2011/6/11 22:08:19
File Name: b.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 10005;
int num[maxn];
int main() {
    freopen("b.out", "w", stdout);
    int test, cas = 0, N;
    scanf("%d", &test);
    while(test --){
        printf("Case #%d: ", ++cas);
        memset(num, 0, sizeof(num));
        scanf("%d", &N);
        for(int i = 0; i < N; i ++){
            int tmp;
            scanf("%d", &tmp);
            num[tmp] ++;
        }
        int ans = N + 100;
        if(N == 0) ans = 0;
        else{
            vector<int> vec;
            for(int i = 0; i < maxn; i ++){
                if(num[i] >= (int)vec.size()){
                    for(int j = 0; j < (int)num[i]; j ++){
                        if(j == (int)vec.size()) vec.push_back(0);
                        vec[j] ++;
                    }
                }else{
                    sort(vec.begin(), vec.end());
                    while((int)vec.size() > num[i]){
                        ans = min(ans, vec.back());
                        vec.pop_back();
                    }
                    for(int j = 0; j < (int)num[i]; j ++){
                        vec[j] ++;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

