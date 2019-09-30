#include <iostream>

using namespace std;

int main(void) {
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    int MIN = 1<<30;
    int min_xy = max(X, Y) * 2;
    for (int c=0; c<=min_xy; c+=2) {
        int a = max(X - c/2, 0);
        int b = max(Y - c/2, 0);
        int price = A*a + B*b + C*c;
        MIN = min(price, MIN);
    }
    cout<<MIN<<endl;

    return 0;
}