#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, div4, div2;
    string answer;
    div4 = 0;
    div2 = 0;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    for (int i=0; i<n; ++i){
        if(a[i] % 4 == 0){
            div4++;
        }
        else if(a[i] % 2 == 0){
            div2++;
        }
    }
    if((div4 >= n / 2) || ((n - 2 * div4) <= div2)){
        answer = "Yes";
    }
    else {
        answer = "No";
    }
    cout << answer << endl;
}