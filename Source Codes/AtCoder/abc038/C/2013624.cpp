#include <vector>
#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n;
    int start = 0;
    unsigned long long cnt = 1;    
    scanf("%d ", &n);
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    for(int i = 1; i < n; i++){
        if(a[i - 1] < a[i]){
            cnt += i - start + 1;
        }else{
            cnt++;
            start = i;
        }
    }
    cout << cnt;
}