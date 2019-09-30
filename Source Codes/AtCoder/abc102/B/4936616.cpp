#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>

using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<*max_element(a.begin(), a.end())-*min_element(a.begin(), a.end())<<endl;
    
    
}