#include <iostream>

using namespace std;
int main(){
    int n;
    int a;
    int max = 0;
    int min = 1000000000;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if( a >= max){
            max = a;
        }
        if( a <= min){
            min = a;
        }
    }

    cout << max - min << endl;
}