#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<utility>   
#include<math.h>
#include<algorithm>
using namespace std;

typedef pair<int,int> P;

int main()
{
    // get a integer
    int N;
    cin >> N;
    cout << "1"; 
    for (int i = 0; i < N-1; ++i) {
        cout << "0"; 
    }
    cout << "7" << endl;
}