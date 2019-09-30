#include<iostream>

int N,Q;

int l,r;

int res[200001];

int t;

int main(){

    std::cin>>N>>Q;

    for(int i=0;i<Q;i++){
        std::cin>>l>>r;
        res[l-1]++;
        res[r]--;
    }

    for(int i=0;i<N;i++){
    t+=res[i];
    std::cout<<t%2;
    }

    std::cout<<std::endl;

    return 0;
}