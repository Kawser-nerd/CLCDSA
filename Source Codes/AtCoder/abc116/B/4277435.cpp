#include <iostream>
#include <vector>

using namespace std;

int f(int n){
    if (n % 2 == 0){
        // ??
        return n/2;
    } else {
        // ??
        return 3*n + 1;
    }
}

int main(){
    int s;
    cin >> s;
    vector<int> a;

    // a_1
    a.push_back(s);
    int count = 1;

    while (true){
        int val = f(a.at(count-1));

        count++;
        for(int val_in_a: a){
            if (val == val_in_a){
                cout << count;
                return 0;
            }
        }

        a.push_back(val);

    }
}