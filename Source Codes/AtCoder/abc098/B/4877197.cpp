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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans=0;
    for(int i=1; i<=n-1; i++){
        int flag[26],tmp=0;
        memset(flag, 0, sizeof(flag));
        for(int j=0; j<i; j++){
            flag[s[j]-'a']++;
        }
        for(int j=i; j<n; j++){
            if(flag[s[j]-'a']!=0){
                tmp++;
                flag[s[j]-'a']=0;
            }
        }
        ans=max(ans, tmp);
    }
    cout << ans;

    return 0;
}