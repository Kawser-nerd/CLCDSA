#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    int counter = 0;
    bool flg = true;
    while(flg){
        for(int i = 0; i < n; i++){
            if(0 == v[i] % 2){
                v[i] = v[i] / 2;
            }else{
                flg = false;
                break;
            }
        }
        if(flg) ++counter;
    }

    cout << counter << endl; 
}