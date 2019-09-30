#include <iostream>
using namespace std;

int main(){
    int waste; cin >> waste;
    string s;
    cin >> s;

    int nums[4] = {0};
    
    for(int i = 0; i < s.size(); i++){
        nums[s[i] - '1']++;
    }

    

    int min = INT_MAX, max = INT_MIN;
    for(int i = 0; i < 4; i++){
        if(nums[i] > max) max = nums[i];
        if(nums[i] < min) min = nums[i];
    }
    
    cout << max << " " << min << endl;
        
    return 0;
}