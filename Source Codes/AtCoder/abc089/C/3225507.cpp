#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void){
    int n;
    vector <string> str;
    string sub;
    long ans = 0;
    vector <int> cnt;
    
    cnt.resize(5);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> sub;
        str.push_back(sub);
        if(str[i][0] == 'M')        cnt[0]++;
        if(str[i][0] == 'A')        cnt[1]++;
        if(str[i][0] == 'R')        cnt[2]++;
        if(str[i][0] == 'C')        cnt[3]++;
        if(str[i][0] == 'H')        cnt[4]++;
    }
    
    int alpha_cnt = 0;
    for(int i = 0; i < 5; i++){
        if(cnt[i])      alpha_cnt++;
    }
    
    if(alpha_cnt < 3){
        cout << 0 << endl;
        return 0;
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 4; j++){
            for(int k = j + 1; k < 5; k++){
                ans += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }
    
    cout << ans << endl;
}