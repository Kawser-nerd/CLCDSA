#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> p;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
    }
    sort(p.begin(),p.end());
    int cost = 0;
    for(int i = 0; i < N-1; i++){
        cost += p[i];
    }
    cost += p[N-1] / 2;
    cout << cost << endl;
    
    return 0;
}