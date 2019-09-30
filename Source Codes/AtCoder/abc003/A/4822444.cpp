#include <iostream>

using namespace std;
    int main(){
        double n;
        cin >> n;
        double k = 10000;

        double sum = 0;

        for(int i = 1; i < n + 1; i++){
            sum = sum + k * i / n;
        }

        cout << sum << endl;

}