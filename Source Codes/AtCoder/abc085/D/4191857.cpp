#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, H;
    long a[100000];
    long b[100000];
    long sum = 0;
    cin >> N >> H;
    for(int i = 0; i < N; i++){
        cin >> a[i] >> b[i];
    }
    sort(a, a+N, greater<long>());
    sort(b, b+N, greater<long>());
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(b[i] <= a[0]) break;
        sum += b[i];
        cnt++;
        if(sum >= H){
            cout << i+1 << endl;
            return 0;
        }
    }
    //cout << (H-sum) << ' ' << a[0] << endl;
    if((H-sum)%a[0] == 0){
        cout << cnt+(H-sum)/a[0] << endl;
    }else{
        cout << cnt+(H-sum)/a[0]+1 << endl;
    }
}