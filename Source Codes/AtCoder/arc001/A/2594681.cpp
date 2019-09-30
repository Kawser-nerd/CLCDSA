#include <string>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

#define inf 100100100
#define INF 100100100

int main(){
    int N;
    string c;
    cin >> N;
    cin >> c;
    int mi = inf, ma = 0;
    for(int i = 0;i < 4;i++){
        string s = to_string(i+1);
        int t = std::count(c.begin(), c.end(), *s.c_str());
        mi = min(mi, t);
        ma = max(ma, t);
    }
    cout << ma << ' ' << mi << endl;
    return 0;
}