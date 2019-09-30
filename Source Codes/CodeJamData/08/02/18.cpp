#include <iostream>
#include <cstdio>
#include <map>
#include <queue>

#define foreach(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define MP make_pair

using namespace std;

typedef pair<int,int> PII;

int parse(string a)
{
    int tmp1 = (a[0]-'0')*10 + a[1]-'0';
    int tmp2 = (a[3]-'0')*10 + a[4];
    return tmp1*60+tmp2;
}

void process(int t)
{
    vector<pair<int,int> > V;
    int turn,NA,NB;
    cin >> turn;
    cin >> NA >> NB;
    for(int i=0;i<NA;i++)
    {
	string t1,t2;
	cin >> t1 >> t2;
	V.push_back(MP(parse(t1),3));
	V.push_back(MP(parse(t2)+turn,0));
    }
    for(int i=0;i<NB;i++)
    {
	string t1,t2;
	cin >> t1 >> t2;
	V.push_back(MP(parse(t1),2));
	V.push_back(MP(parse(t2)+turn,1));
    }

    sort(V.begin(),V.end());
    int ha,hb,ra,rb;
    ha=hb=ra=rb=0;
    for(int i=0;i<V.size();i++)
    {
	int a,b;
	a = V[i].first;
	b = V[i].second;
	switch(b)
	{
	case 3:
	    if(ha == 0)
		ra++;
	    else
		ha--;
	    break;
	case 0:
	    hb++;
	    break;
	case 2:
	    if(hb == 0)
		rb++;
	    else
		hb--;
	    break;
	case 1:
	    ha++;
	    break;
	}
    }
    printf("Case #%d: %d %d\n",t,ra,rb);
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
