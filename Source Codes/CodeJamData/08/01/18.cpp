#include <iostream>
#include <cstdio>
#include <map>

#define foreach(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();++i)

using namespace std;

void process(int t)
{
    int S,Q;
    string str;
    cin >> S;
    getline(cin,str);
    map<string,bool> M;
    for(int i=0;i<S;i++)
    {
	getline(cin,str);
	M[str] = false;
    }

    cin >> Q;
    getline(cin,str);

    int cnt = 0,ret=0;
    
    for(int i=0;i<Q;i++)
    {
	getline(cin,str);
	if(M[str] == false)
	{
	    cnt++;
	    if(cnt == S)
	    {
		foreach(j,M)
		    j->second = false;
		ret++;
		cnt=1;
	    }
	    M[str]=true;
	}
    }

    printf("Case #%d: %d\n",t,ret);
}

int main(void)
{
    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
	process(t);
    }
}
