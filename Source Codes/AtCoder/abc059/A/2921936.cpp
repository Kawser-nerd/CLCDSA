#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2, s3; cin >> s1 >> s2 >> s3;
    cout << char(s1[0] -32) << char(s2[0] - 32) << char(s3[0] - 32) << endl;

    return 0;
}