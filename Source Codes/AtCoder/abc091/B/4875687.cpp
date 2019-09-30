#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>

using namespace std;

int main()
{
    int n,m;
    pair<string, int> card[200];
    vector<int> ans;
    cin >> n;
    int i;
    for(i=0; i<n; i++){
        cin >> card[i].first;
        card[i].second=1;
    }
    cin >> m;
    for(int j=i; j<i+m; j++){
        cin >> card[j].first;
        card[j].second=-1;
    }
    sort(card, card+n+m);
    int tmp=card[0].second;
    string s=card[0].first;
    for(int i=1; i<n+m; i++){
        if(card[i].first==s){
            tmp+=card[i].second;
        }else{
            ans.push_back(tmp);
            s=card[i].first;
            tmp=card[i].second;
        }
    }
    ans.push_back(tmp);
    sort(ans.begin(), ans.end(), greater<int>());
    if(ans[0]<0){
        ans[0]=0;
    }
    cout << ans[0];

    return 0;
}