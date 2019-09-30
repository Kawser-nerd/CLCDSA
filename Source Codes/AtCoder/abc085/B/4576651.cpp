#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int N;
    int sum = 1;
    cin >> N;
    int d[N];
    for(int i = 0; i < N; i++){
        cin >> d[i];
    }
    sort(d, d + N, greater<int>());
    int max = d[0];
    for(int i = 1; i < N; i++){
        if(max > d[i]){
            sum++;
            max = d[i];
        }
    }
    cout << sum << endl;
    return 0;
}