#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <array>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

long long int lucas(int n)
{
    return n == 0 ? 2 : (n == 1 ? 1 : lucas(n-1)+lucas(n-2));
}

int main(){

    int n;
    cin >> n;
    
    
    array<long long int,87> l;
    /*
    for (int i = 0; i <= 86;i++){
        l[i] = lucas(i);
        cout << i << endl;
    }*/
    l[0] = 2;
    
    l[1] = 1;
   
    for (int i = 2; i <= 86; i++){
        l[i] = l[i - 1] + l[i - 2];
    }    
    cout << l[n] << endl;
    
    return 0;

}