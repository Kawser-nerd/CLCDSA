#include<iostream>
#include<vector>

using namespace std;

int main (void){
    int N;
    cin >> N;
    vector<int> v;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    int max_iter=0;
    for(int i=0; i<(int)v.size(); i++){
        if(v[i] > v[max_iter])
            max_iter = i;
    }
    int sum=0;
    for(int i=0; i<(int)v.size(); i++){
        if(i != max_iter)
            sum += v[i];
    }
    if(sum > v[max_iter])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}