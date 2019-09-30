#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<fstream>
#include<iostream>
#include<bitset>
#include<cassert>
#include<climits>
#include<vector>
#include<queue>
#include<string>
#include<bitset>

using namespace std;

vector<int> ai[2002];
vector<int> bi[2002];

void do_case(void)
{
    bitset<1000> todo;

    int N;
    cin >> N;

    for(int i = 0; i < N; ++i) todo.set(i);

    vector<int> ai;
    vector<int> bi;
    for(int i = 0; i < N; ++i) {
        int s1, s2;
        cin >> s1 >> s2;

        ai.push_back(s1);
        bi.push_back(s2);
    }

    int stars = 0;
    int played = 0;
    while(todo.any()) {
        int acc = 0;
        for(int i = 0; i < N; ++i) {
            if(todo[i]) {
                if(bi[i] <= stars) {
                    acc += bi[i] >= ai[i] ? 2 : 1;
                    ++played;
                    todo.reset(i);
                }
            }
        }
        if(acc == 0) {
            int maxb = 0;
            int maxi = -1;
            for(int i = 0; i < N; ++i) {
                if(!todo[i]) continue;
                if(ai[i] > stars) continue;
                if(bi[i] <= maxb) continue;
                maxb = bi[i];
                maxi = i;
            }
            if(maxi == -1) {
                cout << "Too Bad\n";
                return;
            } else {
                ++acc;
                ++played;
                ai[maxi] = 10000000;
            }
        }
        stars += acc;
    }
    cout << played << "\n";
}

int main()
{
    freopen("input.data", "r", stdin);
    //freopen("output.data", "r", stdout);

    int cases;
    scanf("%d\n", &cases);
    int i = 1;
    do{
        printf("Case #%d: ", i);
        do_case();
    }while(++i <= cases);

    return 0;
}
