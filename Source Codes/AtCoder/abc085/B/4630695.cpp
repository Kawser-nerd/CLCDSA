//
// Created by ???? on 2019-03-19.
//



#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int b(int N, const vector<int>& d){
    vector<bool> occur(200,false);
    int count = 0;

    for(int i = 0; i < N; i++){
        if(!occur[ d[i] ] ){
            count++;
            occur[ d[i]] = true;
        }
    }

    return count;

}

int b_with_map(int N, const vector<int>& d){
    unordered_map<int, bool>map;

    int count = 0;

    for(int i = 0; i < N; i++){
        if( map.find( d[i] ) == map.end() ){
            map[ d[i] ] = true;
            count++;
        }

    }
    return count;

}

int main(){

    int N; cin >> N;
    vector<int> d(N);
    for(int i = 0; i < N; i++){
        cin >> d[i];
    }
    cout << b_with_map(N, d);

}