#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, tmp;
    cin >> n;
    vector<int> even;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        if(tmp % 2 == 1){
            even.push_back(tmp);
        }
    }
    if(even.size() % 2 == 0){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}