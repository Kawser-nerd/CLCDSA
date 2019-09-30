#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    long long answer;
    answer = K * pow(K - 1, N - 1);
    cout <<  answer;
}