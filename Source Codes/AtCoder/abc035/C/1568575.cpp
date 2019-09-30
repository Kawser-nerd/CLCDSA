#include <iostream>

constexpr int MAX=2*(int)1e5+2;

int n,q;

int board[MAX];

int l[MAX],r[MAX];

int main() {

    std::cin>>n>>q;

    for(int i=0;i<q;++i)
        std::cin>>l[i]>>r[i];

    for(int i=0;i<q;++i){
        ++board[l[i]];
        --board[r[i]+1];
    }

    for(int i=1;i<=n;++i)
        board[i]+=board[i-1];

    for(int i=1;i<=n;++i)
        std::cout<<board[i]%2;

    std::cout<<std::endl;

    return 0;
}