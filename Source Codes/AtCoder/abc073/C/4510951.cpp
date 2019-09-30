#include <iostream>
#include <cstdio>  
#include <cstring> 
#include <cmath> 
#include <string> 
#include <vector> 
#include <set>   
#include <map>
#include <queue> 
#include <stack> 
#include <algorithm> 

using namespace std;

int main(int argc,char* argv[])
{
    int N;
    map<string,int> mp;
    string str;
    scanf("%d",&N);
   
    for(int i=0;i<N;i++)
    {
        cin>>str;
        if(mp[str]==0)
          mp[str] = 1;
        else
          mp[str] = 0;
    }
    
    map<string,int>::iterator it = mp.begin();
    int cnt = 0;
    for( ;it!=mp.end();it++)
    {
    	if(it->second!=0)
    	  cnt++;
    }
    
    printf("%d",cnt);
	return 0;
}