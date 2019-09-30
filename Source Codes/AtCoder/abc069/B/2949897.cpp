#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    int s_size;
    cin >> s;

    s_size = s.size();



    cout << s[0] << s_size -2 << s[ s_size - 1 ] << endl;
    return 0;
}