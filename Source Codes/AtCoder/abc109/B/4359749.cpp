#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> w;
    string a;
    for (int i = 0;i<N;i++){
        cin >> a;
        w.push_back(a);
    }
    bool flag = true;
    for (int i = 0;i<N - 1;i++){
        if (w[i][w[i].size() -1] != w[i + 1][0]){
            flag = false;
            break;
        }
        for (int j = 0;j < i;j++){
            if (w[i] == w[j]){
                flag = false;
                break;
            }
        }
    }
    for(int i = 0;i < N-1;i++){
       if (w[N-1] == w[i]){
                flag = false;
                break;
            } 
    }
    if(flag == true){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
}