#include<iostream>
typedef long long ll; 
using namespace std;

int main(){
    ll num[3];
    for(int i = 0; i < 3; i++){
        cin >> num[i];
    }

    sort(num, num + 3);

    
    for (int i = 0; i < 3; i++){
        if(num[i] % 2== 0){
            cout << 0 << endl;
            return 0;
        }
    }

    cout << num[0] * num[1] << endl;
    return 0;
}