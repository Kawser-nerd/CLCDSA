#include <algorithm>
#include <iostream>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <vector>
#include <map>
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using namespace std;



int main(){
    string S;
    cin>>S;
    map <char,int> m;
    vector<char> s;
    vector<int> in,k,ans;
    int len=S.size(),g=0;
    for (int i=0;i<len;i++) m[S[i]]=0;
    for (int i=0;i<len;i++) m[S[i]]=m[S[i]]+1;
    for(auto itr = m.begin(); itr != m.end(); ++itr) in.push_back(itr->second);
    for(int i = 0; i<in.size(); i++){
        if (in[i] % 2 == 1) { g = g + in[i] - 1 ; k.push_back(1); }
        else g=g+in[i];
    }
    if(k.size() ==0){
        cout<<g<<endl;
        return 0;
    }


    while(1){
        if(g==0) break;
        std::vector<int>::iterator minIt = min_element(k.begin(), k.end());
        size_t ind=distance(k.begin(), minIt);
        k[ind]=k[ind]+2;
        g=g-2;


        
    }
    int min = *std::min_element(k.begin(), k.end());
    cout<<min<<endl;
    //for(auto itr: k) cout<<itr<<" "<<endl;






}