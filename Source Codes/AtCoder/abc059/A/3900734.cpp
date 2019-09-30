#include <iostream>

using namespace std;

int main(void)
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    cout << char('A' + (s1[0] - 'a'));
    cout << char('A' + (s2[0] - 'a'));
    cout << char('A' + (s3[0] - 'a'));
    cout << endl;
    return 0;
}