#include <iostream>

using namespace std;

int even (int); //??
int odd (int); //??

int main()
{
    int s; //??
    int a[1000000]; //??a
    
    cin >> s; //??
    a[0] = s;
    //cout << s << '\n';
    for (int i = 1; i <= 1000000; i++){ //????
        if (a[i-1] % 2 == 0){//a[i-1]?????a[i]?f(n) = n/2
            a[i] = even(a[i-1]);
//            cout << a[i] << '\n';
//            cout << "a[" << i - 1 << "] =" << a[i -1] << '\n';
        }
        else {//a[i-1]?????a[i]?f(n) = 3n+1
            a[i] = odd(a[i-1]);
//            cout << a[i] << '\n';
//            cout << "a[" << i - 1 << "] =" << a[i -1] << '\n';
        }
    }
    int i;
    
    for (i = 0; i < 1000000; i++){ //???
        for (int j = 0; j < i; j++){
            if (a[j] == a[i])
                goto LABEL; //???????
        }
    }
LABEL:
    cout << i + 1 << '\n';
}

int even(int n)
{
    return n / 2;
}

int odd(int n)
{
    return 3 * n + 1;
}