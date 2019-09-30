#include <iostream>
#define endl '\n'

using namespace std;

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string str1, str2; cin >> str1 >> str2;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end(), greater<char>());
    if(str1 < str2)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}