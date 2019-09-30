#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main(void){
    // Here your code !
    int N,t = 0;
    ll res = 0;
    cin >> N;
    
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
        res += a[i];
    } 
    
    ll tmp = 0;
    for(int i = 1; i <= N; i++ ) tmp+=i;
    
    if(res % tmp){
        cout << "NO" << endl;
        return 0;
    } 
    
    ll tmp1 = res / tmp;
   
    for(int i = 0; i < N; i++){
        
        int tmp2 = a[i] - a[(i+1)%N]+ tmp1;
        
        if(tmp2%N != 0 || tmp2 < 0 ){
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;

    return 0;
    
}