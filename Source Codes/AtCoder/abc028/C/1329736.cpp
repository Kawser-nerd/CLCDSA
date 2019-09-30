#include <iostream>
#include <set>
using namespace std;

int main(){
    int num[5];
    for(int i = 0; i < 5; ++i){ cin >> num[i]; }    
    set<int> st{0};
    auto itr = st.begin();
    
    for(int i = 0; i < 1 << 5; i++){
        int tempSum = 0;
        int bitSum = 0;
        for(int j = 0; j < 5; ++j){
            if(i >> j & 1){ ++bitSum; }
        }
        if(bitSum == 3)
        for(int j = 0; j < 5; ++j){
            if(i >> j & 1) tempSum += num[j];
        }
        st.insert(tempSum);
    }
    for(int i = 0; i < st.size()- 3; ++i){ ++itr; }
    cout << *itr << endl;

    return 0;
}