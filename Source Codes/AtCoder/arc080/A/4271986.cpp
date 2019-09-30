#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int cnt1 = 0, cnt2 = 0, cnt4 = 0;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        if(a%4 == 0) cnt4++;
        else if(a%2 == 0) cnt2++;
        else cnt1++;
    }
    if(cnt1 > cnt4+1){
        cout << "No" << endl;
    }else if(cnt1 == cnt4+1){
        if(cnt2 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}