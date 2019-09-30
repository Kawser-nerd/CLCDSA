#include <iostream>
#define endl '\n'

using namespace std;

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N; cin >> N;
    bool flag = false;
    while(N--)
    {
        char ch; cin >> ch;
        if(ch == 'Y')
            flag = true;
    }
    if(flag)
        cout << "Four" << endl;
    else
        cout << "Three" << endl;
    return 0;
}