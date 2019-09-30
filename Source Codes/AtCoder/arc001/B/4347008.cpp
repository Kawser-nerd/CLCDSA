#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
    int N;
    string a;
    cin >> N; 
    cin >> a;
    int num[4] = {0,0,0,0};
    for (int i = 0;i < N;i++){
        if(a[i] == '1'){
            num[0]++;
        }
        else if (a[i] == '2'){
            num[1]++;
        }
        else if (a[i] == '3'){
            num[2]++;
        }
        else if (a[i] == '4'){
            num[3]++;
        }

    }
    int temax = num[0];
    int temin = num[0];
    for (int i = 0;i< 4;i++){
        if (num[i] > temax){
            temax = num[i];
        }
        else if (num[i] < temin){
            temin = num[i];
        }
    }
    cout << temax << " " << temin << endl;
}