#include <iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
int main(void){
    int i,number,n;
    cin >>n;
    vector<pair<int,int> > psi(n);
    for(int i=0;i<n;i++){
        psi[i].second=i+1;
        cin>>psi[i].first;
        
        
    }
    sort(psi.begin(),psi.end());
    reverse(psi.begin(),psi.end());
    for(int i=0;i<n;i++){
        cout<<psi[i].second<<endl;
    }
    return 0;
    
}