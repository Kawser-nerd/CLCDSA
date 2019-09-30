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
    vector<int> nums(3);
    int k;

    for(int i=0; i<3; i++){
        cin >> nums[i];
    }
    cin >> k;
    sort(nums.begin(), nums.end());
    cout << nums[0]+nums[1]+nums[2]*int(pow(2,k));
    

    return 0;
}