#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main(){

    int N;

    cin >> N;
    vector<int> l(N);
    for(int i = 0; i < N; ++i){
        cin >> l[i];
    }

    sort(l.begin(), l.end(), greater<int>() );

    cout << l[0] - l[N-1] << endl;
}