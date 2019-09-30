#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int A,B;
    // int a,b,c,d;
    int tmp = 0, ans = 0;
    vector<int> a(5);
    cin >> A >> B;
    for(int i = A ; i <= B; i++){
        int tmp = i;
        for(int j = 0; j < 5; j++){
            a[4-j] = tmp % 10;
            tmp /= 10;
        }
        if(a[0] == a[4] && a[1] == a[3]){
            ans++;
        }
    } 
    cout << ans << endl;
}