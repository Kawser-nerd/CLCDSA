#include <iostream>
#include <vector>
using namespace std;
int main(void){
    
    long long int n;
    
    cin >> n;
    n++;   vector<int> ans;
    int cur = 1;
    long long buf = 0;
    int ket = 0;
    for(int i = 0; 60 > i; i++){
        if(n & (1LL << i))
            ket = max(i,ket);
    }
    for(int i = ket-1; i >= 0; i--){
            ans.insert(ans.begin() + ans.size() / 2, cur);
            ans.insert(ans.begin(), cur);
        cur++;
        if((n >> i) & 1){
            ans.insert(ans.begin(), cur);
            ans.push_back(cur);
            cur++;
        }
        
        
    }
    cout<< ans.size() << endl;
    
    for(auto itr : ans)
        cout << itr << " ";
    cout << endl;
}