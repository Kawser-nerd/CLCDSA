#include <iostream>
using namespace std;
int main(){
    string s1;
    string s2;
    string s3;
    cin >> s1 >> s2 >> s3;
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
    transform(s3.begin(), s3.end(), s3.begin(), ::toupper);
    cout << s1[0] << s2[0] << s3[0] << endl;
}