#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <climits>
#include <functional>
#include <map>
#include <stack>
#define endl '\n'
#define ll long long
#define NCONS 16001

using namespace std;

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string a, b; cin >> a >> b;
    string temp = a + b;
    int number = stoi(temp);
    
    for(int i = 1; i * i <= 100100; i++)
    {
        if(i * i == number)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}