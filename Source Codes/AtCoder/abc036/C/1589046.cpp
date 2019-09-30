#include <iostream>
#include <algorithm>
#define MAX_N 100001
using namespace std;

typedef pair<int, int> P;
P a[MAX_N];
int main(){
    int N; cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a+N);
    for(int i = 0, j = 0; i < N - 1; ++i){
        if(a[i].first != a[i+1].first){
            a[i].first = j;
            j++;
        }else{
            a[i].first = j;
        }
        if(i == N-2) a[i+1].first = j;
    
    }
    for(int i = 0; i < N; ++i){
        int tmp = a[i].second;
        a[i].second = a[i].first;
        a[i].first = tmp;
    }

    sort(a, a+N);
    for(int i = 0; i < N; ++i){
        cout << a[i].second << endl;
    }
    
    return 0;
}