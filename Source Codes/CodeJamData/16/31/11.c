#include <bits/stdc++.h>
using namespace std;
		set < pair<int,int> > s;
		set< pair<int,int> >::iterator rit;

int main() {
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		cout<<"Case #"<<tt<<": ";
		int k;
		cin>>k;
		s.clear();
		float tot=0;
		for(int i=0;i<k;i++)
		{
			int a;
			cin>>a;
			tot+=a;
			s.insert(make_pair(a,i));
		}
		
		while(!s.empty()){
			rit=s.end();
			rit--;
			
			pair <int,int> l = *rit;
			if(l.first>float(tot)/2)
			{
				printf("Wrong!\n");
				break;
			}
			if(l.first==1&&s.size()%2!=0)
			{	
				cout<<char(l.second+'A')<<" ";
				s.erase(rit);
				tot--;
				continue;
			}
			
			
			s.erase(rit);
			rit=s.end(); 
			rit--;
			pair <int,int> l1 = *rit;
			if(l1.first==l.first)
			{
				s.erase(rit);
				l1.first--;
				l.first--;
				cout<<char(l.second+'A')<<char(l1.second+'A')<<" ";
				if(l.first>0)
				{
					s.insert(l);
					s.insert(l1);
					tot-=2;
				}
			}
			else
			{
				l.first-=2;
				tot-=2;
				if(l.first>0)
					s.insert(l);
				cout<<char(l.second+'A')<<char(l.second+'A')<<" ";
			}
			
			
		
		}
	
		cout<<endl;
	}
	return 0;
}
