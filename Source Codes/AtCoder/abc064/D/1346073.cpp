#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string input;
    string ans;
    cin >> input;
    ans = input;
    int right = 0;
    for(int i = n - 1; i >= 0; --i){
        if(input[i] == ')'){
            right++;
        }
        else{
            if(right == 0){
                ans += ")";
            }
            else{
                right--;
            }
        }
    }
    for(int i = 0; i < right; ++i){
        ans = "(" + ans;
    }
    cout << ans << endl;
    return 0;
}