#include <iostream>
#include <vector>

using namespace std;

int N = 0;
vector<int> a(100, 0);

int main(void){
    int sum = 0;
    int correct = 0;

    int remain = 0;

    int ans = 0;

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> a[i];
        sum += a[i];
    }

    correct = sum / N;

    for(int i=0; i<N; ++i){
        a[i] -= correct;
    }

    for(int i=0; i<N; ++i){
        remain += a[i];
        if(remain != 0){
            ans++;
        }
    }

    if(remain != 0){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}