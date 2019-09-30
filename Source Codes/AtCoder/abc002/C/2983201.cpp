/*
title:C - ??

url:https://abc002.contest.atcoder.jp/tasks/abc002_3

author:Yuta Hirai
*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    //a????????
    double S;
    xb -= xa;
    yb -= ya;
    xc -= xa;
    yc -= ya;

    S = fabs(xb * yc - xc * yb) / 2.;
    cout << fixed;
    cout << setprecision(1) << S << endl;
}