#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int n, m, a, b;

bool pairCompare(const P& firstElof, const P& secondElof)
{
    return firstElof.second < secondElof.second;
}

int main(void){
    // Your code here!
    cin >> n >> m;
    vector<P> pairs(m);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        pairs[i] = make_pair(a, b);
    }
    
    
    sort(pairs.begin(), pairs.end(), pairCompare);
    int i = 0;
    int s = pairs[i].second;
    int cnt = 0;
    while(true){
        if(i == m-1){
            cnt += 1;
            break;
        }
        
        if(pairs[i+1].first < s){
            i++;
        } else{
            cnt++;
            s = pairs[i+1].second;
        }
    }
    
    cout << cnt << endl;
}