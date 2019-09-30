#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;

int main(void)
{
    int number[3],k;
    for(int i = 0;i < 3;i++){cin >> number[i];}
    cin >> k;
    sort(number,number + 3);
    for(int i = 0;i < k;i++){number[2] *= 2;}
    cout << number[0] + number[1] + number[2] << endl;
    return 0;
}