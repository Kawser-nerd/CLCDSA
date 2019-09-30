#include <iostream>
#define endl '\n'

using namespace std;

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string str; cin >> str;
    str[3] = '8';
    cout << str;
    
    return 0;
}