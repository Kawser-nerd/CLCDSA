#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<algorithm>
using std::cout;
using std::cin;
using std::endl;

int main(void){
    int n;
    std::string s;
    cin>>n;
    cin>>s;
    int cum_w[300003]={};
    int cum_e[300003]={};
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='W')
        {
            cum_w[i]=cum_w[i-1]+1;
            cum_e[i]=cum_e[i-1];
        }
        else
        {
            cum_w[i]=cum_w[i-1];
            cum_e[i]=cum_e[i-1]+1;
        }
    }

    int min=300003;
    int m1;
    for(int i=1;i<=n;i++)
    {
        m1=cum_w[i-1]+cum_e[n]-cum_e[i];
        if(m1<min)min=m1;
    }

    cout<<min<<endl;
	
    return 0;
}