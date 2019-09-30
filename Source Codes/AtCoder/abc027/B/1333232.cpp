#include <iostream>
using namespace std;

int main(){
    int N, ans = 0, sum = 0;
    cin >> N;
    int nums[N];
    for(int i = 0; i < N; ++i){
        cin >> nums[i];
        sum += nums[i];
    }
    int ave = sum % N;
    int buff = 0;
    if(ave != 0) ans = -1;
    else{
        int temp = sum / N;
        
        for(int i = 0; i < N; ++i){
            nums[i] -= temp;
        }
        int flag = 0;
        for(int i = 0; i < N; ++i){
            buff += nums[i];
            if(buff == 0){
                ans++;
            }
        }
        ans = N - ans;
    }

    cout << ans << endl;
    return 0;
}