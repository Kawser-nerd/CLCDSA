#include <iostream>
#include <vector>

using namespace std;

//=================================================================
// Begginer Contest 116 B
int main(){
    vector<int> v(1000000, 0);
    int s;
    cin >> s;
    v[s] = 1;

    for(int i=2;i<1000000;i++){
        if(s%2==0){
            s = s/2;
        }else{
            s = 3*s+1;
        }

        if(v[s]!=0){
            v[s] = i;
            break;
        }
        v[s]=i;
    }
    cout << v[s] << endl;
}