#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int N;
    cin >> N;
    int h[N];
    for(int i = 0;i < N;i++){
        cin >> h[i];
    }   
    int p = 0;
    bool flag = true;
    int b,c;
    while(flag == true){
        flag = false;
        for(int i = 0;i< N;i++){
            if(h[i] != 0){
                b = i;
                flag = true;
                break;
            }
        }
        bool flag2 = false;
        if(flag == true){
            for(int j = b;j<N;j++){
                if(h[j] == 0){
                    c = j;
                    flag2 = true;
                    break;
                }
            }
            if(flag2 == false){
                c = N;
            }
            for (int k = b;k<c;k++){
                h[k] = h[k] - 1;
            }
            p = p + 1;
        }
    }
    cout << p << endl;
}