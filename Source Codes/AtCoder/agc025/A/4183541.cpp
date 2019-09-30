#include <iostream>
#include <cmath>

using namespace std;

int sum (int num) {
    int sum {0};
    for (int i = 0; i < 5; i++) {
        sum += num % 10;
        num = (num - (num % 10)) / 10;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    int A, B;
    int smallest {INT_MAX};
    
    for (int i {1}; i < N; ++i) {
        A = i;
        B = N - i;
        int total = sum(A) + sum(B);
        if (smallest > total) {
            smallest = total;
        }
    }
    cout << smallest << endl;
    
    return 0;
}