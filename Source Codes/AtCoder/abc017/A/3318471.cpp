#include<iostream>
#include <string>
using namespace std;

int main() {
    int s1, s2, s3, e1, e2, e3;
    cin >> s1 >> e1 >> s2 >> e2 >> s3 >> e3;
    cout << (s1*e1 + s2*e2 + s3*e3 )/10 << endl;
}