#include <iostream>
#include <math.h>

using namespace std;


int main()
{
        string i, j;
        int a, b;

        cin >> i;
        cin >> j;

        a = stoi(i+j);
        b = sqrt(a);

        if (b*b == a) {
                cout << "Yes" << endl;
        } else {
                cout << "No" << endl;
        }



        return 0;
}