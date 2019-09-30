#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> vec(n);
    int64_t sum = 0;
    for(int i=0; i<vec.size(); i++){
        cin>>vec[i];
    }
    for(int i=0; i<n-k+1; i++) {
        for(int j=i; j<i+k; j++) {
            sum += vec[j];
        }
    }
    cout<<sum<<endl;
}