#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    int x;
    int ser, ler;
    vector<int> v;
    vector<int> nosort;
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d", &x);
        v.push_back(x);
        nosort.push_back(x);
    }
    sort(begin(v),end(v));
    ser = v[N/2-1];
    ler = v[N/2];

    int i = 0;
    for(int elem : nosort){
        if(elem <= ser) printf("%d\n", ler);
        else printf("%d\n", ser);
    }

    return 0;
}