#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int N,A,B;
    cin >> N;
    A = N;
    vector<int> v;
    while(A > 0){
        v.push_back(A % 10);
        A /= 10;
    }
    int sum = 0;
    for(int i = 0; i < v.size(); i++){
        sum += v[i];
    }
    if(N %sum == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}