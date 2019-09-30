#include<iostream>
using namespace std;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int minTrain, minBus;
    minTrain = A > B ? B : A;
    minBus = C > D ? D : C;

    cout << minTrain + minBus << "\n";

    return 0;
}