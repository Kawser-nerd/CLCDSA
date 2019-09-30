#include<iostream>
#include<string>
#include<cmath>

std::string S;

int T;

int x,y,q,res;

int main(){

    std::cin>>S>>T;

    for(auto&& s:S){
        if(s=='L')x--;
        if(s=='R')x++;
        if(s=='U')y++;
        if(s=='D')y--;
        if(s=='?')q++;
    }

    if(T==1)
    res=abs(x)+abs(y)+q;
    else
    if(abs(x)+abs(y)>q)
    res=abs(x)+abs(y)-q;
    else
    if(S.size()%2)
    res=1;
    else
    res=0;
    
    

    std::cout<<res<<std::endl;
    return 0;
}