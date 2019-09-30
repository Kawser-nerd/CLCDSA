#include <cstdio>
#include <algorithm>
using namespace std;

int E, R;
long long solve(int* start, int length, int se, int ee){
    if(length == 0)
        return 0;
    long long pos = max_element(start, start+length) - start;
    long long ie = pos*R+se;
    if(ie > E)
        ie=E;
    long long re = ee-(length-pos)*R;
    if(re < 0)
        re=0;
    long long res=(ie-re)*start[pos];
    res+=solve(start, pos, se, ie);
    res+=solve(start+pos+1, length-pos-1, re+R, ee);
    return res;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        int N, v[10000];
        scanf("%d%d%d", &E, &R, &N);
        for(int i=0; i<N; i++)
            scanf("%d", v+i);
        printf("Case #%d: %lld\n", t, solve(v, N, E, R));
    }
}
