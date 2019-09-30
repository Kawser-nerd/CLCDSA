#include <iostream>

using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;
    if(N % K){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}