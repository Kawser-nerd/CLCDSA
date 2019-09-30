#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int A, B, C, X;
    int c[3][3]; 
    int ans=0;
    bool flag = true;
    cin >> A >> B >> C >> X;
    for(int i = 0; i <= A; i++){
        for(int j = 0; j <= B; j++){
            for(int k = 0; k <= C; k++){
                if(X == 500*i +100*j + 50*k)ans++;
            }
        }
    }
    cout << ans << endl;
    
}