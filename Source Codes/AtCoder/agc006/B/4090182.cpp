#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, x;
    int a[200001];
    cin >> N >> x;
    for(int i = 0; i <= 2*N-1; i++){
        a[i] = i;
    }
    if(N == 2){
        if(x == 2){
            cout << "Yes" << endl;
            cout << 1 << '\n' << 2 << '\n' << 3 << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        if(x == 1 || x == 2*N-1){
            cout << "No" << endl;
        }else{
            if(x == 2){
                cout << "Yes" << endl;
                for(int i = 1; i <= N-3; i++){
                    cout << i+4 << '\n';
                }
                cout << 4 << '\n' << 2 << '\n' << 1 << '\n' << 3 << '\n' ;
                for(int i = N+2; i <= 2*N-1; i++){
                    cout << i << '\n';
                }
            }else{
                cout << "Yes" << endl;
                a[x-2] = 0;a[x-1] = 0;a[x] = 0; a[x+1] = 0;
                sort(a, a+2*N);
                for(int i = 1; i <= N-3; i++){
                    cout << a[i+4] << '\n';
                }
                cout << x-2 << '\n' << x+1 << '\n' << x << '\n' << x-1 << '\n' ;
                for(int i = N+2; i <= 2*N-1; i++){
                    cout << a[i] << '\n';
                }
            }
        }
    }
}