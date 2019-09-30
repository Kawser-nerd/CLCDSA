#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    int a;
    vector<int> v, vorg;
    int vmax;
    int vmax2;

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &a);
        v.push_back(a);
        vorg.push_back(a);
    }
    auto vmax_iter = max_element(begin(v),end(v));
    vmax = *vmax_iter;
    int vmax2nd = vmax / 2;
    *vmax_iter = -1;
    for(int i = 0; i < N; i++){
        if(v[i] > vmax2nd) v[i] = vmax - v[i];
    }
    auto vmax2_iter = max_element(begin(v),end(v));
    vmax2 = vorg[vmax2_iter - begin(v)];

    printf("%d %d\n",vmax,vmax2);
}