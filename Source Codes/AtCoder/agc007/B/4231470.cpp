#include <iostream>

using namespace std;

int main(){
    int N;
    long a[100000];
    long b[100000];
    long sum[100000];
    long p[100000];
    long add_a[100000];
    long add_b[100000];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p[i];
    }
    for(int i = 0; i < N; i++){
        add_a[i] = 0;
        add_b[i] = 0;
        a[i] = i+1;
        b[i] = N-i; 
    }
    for(int i = 0; i < N; i++){
        sum[i] = a[p[i]-1]+b[p[i]-1];
    }
    for(int i = 1; i < N; i++){
        if(sum[i] <= sum[i-1]){
            long diff = sum[i-1] - sum[i] + 1;
            sum[i] += diff;
            add_a[p[i]-1] = diff;
            add_b[p[i]-1] = diff;
            // /cout << diff << endl;
        }
    }
    for(int i = 1; i < N; i++){
        add_a[i] += add_a[i-1];
    }
    for(int i = N-2; i >= 0; i--){
        add_b[i] += add_b[i+1];
    }
    for(int i = 0; i < N-1; i++){
       cout << a[i] + add_a[i] << ' ';
    }
    cout << a[N-1]+add_a[N-1] << endl;
    for(int i = 0; i < N-1; i++){
        cout << b[i]+add_b[i] << ' ';
    }
    cout << b[N-1]+add_b[N-1] << endl;
}