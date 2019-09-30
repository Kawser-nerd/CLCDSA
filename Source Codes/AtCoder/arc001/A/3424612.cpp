#include<iostream>
#include<vector>

#define ANS_NUM 4

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> ans(ANS_NUM, 0);
    string c;
    cin >> c;

    for(int i = 0; i < n; i++){
        switch(c[i]){
            case '1':
                ans[0]++;
                break;
            case '2':
                ans[1]++;
                break;
            case '3':
                ans[2]++;
                break;
            default:
                ans[3]++;
                break;
        }
    }

    int max = *max_element(ans.begin(), ans.end());
    int min = *min_element(ans.begin(), ans.end());

    cout << max << " " << min << "\n";

    return 0;
}