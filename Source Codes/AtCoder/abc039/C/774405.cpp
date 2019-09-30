#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
//    Do WBWBWWBWBWBWWBWBWWBW
//    Re WBWWBWBWBWWBWBWWBWBW
//    Mi WWBWBWBWWBWBWWBWBWBW
//    Fa WBWBWBWWBWBWWBWBWBWW
//    So WBWBWWBWBWWBWBWBWWBW
//    La WBWWBWBWWBWBWBWWBWBW
//    Si WWBWBWWBWBWBWWBWBWWB
    string res = "";
    if (s == "WBWBWWBWBWBWWBWBWWBW") {
        res = "Do";
    } else if (s == "WBWWBWBWBWWBWBWWBWBW") {
        res = "Re";
    } else if (s == "WWBWBWBWWBWBWWBWBWBW") {
        res = "Mi";
    } else if (s == "WBWBWBWWBWBWWBWBWBWW") {
        res = "Fa";
    } else if (s == "WBWBWWBWBWWBWBWBWWBW") {
        res = "So";
    } else if (s == "WBWWBWBWWBWBWBWWBWBW") {
        res = "La";
    } else if (s == "WWBWBWWBWBWBWWBWBWWB") {
        res = "Si";
    }

    cout << res << endl;
    return 0;
}