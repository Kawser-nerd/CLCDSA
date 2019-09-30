#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int N;
    cin >> N;
    long long x[N],y[N];
    long long h[N];
    bool flag = true;
    bool flag2 = false;
    long long H;
    int ansx,ansy,ansh;
    long long b = 0;
    for (int i = 0;i<N;i++){
        cin >> x[i] >> y[i] >> h[i];
    } 
    for (int i = 0;i<101;i++){
        for (int j = 0;j<101;j++){
            for (int k = 0;k<N;k++){
                if(h[k] != 0){
                    H = h[k] + abs(x[k] - i) + abs(y[k] - j);
                    break;
                }
            }
            for (int k=0;k<N;k++){
                if(max((H - abs(x[k] - i) - abs(y[k] - j)),b) != h[k]){
                    flag = false;
                    break;
                }
            }
            if (flag == true){
                ansx = i;
                ansy = j;
                ansh = H;
                flag2 = true;
                break;
            }
            flag = true;
        }
        if(flag2 == true){
            break;
        }
    }
    cout << ansx << " " << ansy << " " << ansh << endl;
    
}