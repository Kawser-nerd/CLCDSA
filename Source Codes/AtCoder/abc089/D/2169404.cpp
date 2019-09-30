#include<iostream>
#include<cstdlib>

int main()
{
    int H, W, D, A;
    std::cin >> H >> W >> D;
    int i1[H*W+1], j1[H*W+1], s[H*W+1];
    
    for(int i=0; i<H; i++)
    {
        for(int j=0; j<W; j++)
        {
            std::cin >> A;
            i1[A] = i;
            j1[A] = j;
        }
    }

    for(int i=1; i<=D; i++)
    {
        for(int j=0; i+D*j<=H*W; j++)
        {
            s[i+D*j] = j==0 ? 0 : s[i+D*(j-1)]+abs(i1[i+D*(j-1)]-i1[i+D*j])+abs(j1[i+D*(j-1)]-j1[i+D*j]);
        }
    }
    
    int Q;
    std::cin >> Q;
    int L, R;
    
    for(int i=0; i<Q; i++)
    {
        std::cin >> L >> R;
        std::cout << s[R]-s[L] << std::endl;
    }
    
    return 0;
}