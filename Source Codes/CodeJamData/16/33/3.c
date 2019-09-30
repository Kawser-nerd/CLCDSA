#include <bits/stdc++.h>
#include <time.h>       /* time */

using namespace std;
int h[1000]={};
int main() {
  srand (time(NULL));
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		cout<<"Case #"<<tt<<": ";
		int a,b,c,k;
		vector <int> ans;
vector <int> ans1;
		cin>>a>>b>>c>>k;
		for(int hh=0;hh<=10000;hh++)
		{		memset(h,0,sizeof h);
					ans1.clear();
			for(int i1=1;i1<=a;i1++)
				for(int i2=1;i2<=b;i2++)
					for(int j=0;j<10;j++)
					{

						int i3=rand()%c+1;
						if(h[i1*100+i2*10+i3]==1)
							continue;
						if(h[i1*100+i3]==k)
							continue;
						if(h[i2*10+i3]==k)
							continue;
						if(h[i1*100+i2*10]==k)
							continue;
						ans1.push_back(i1*100+i2*10+i3);
						h[i1*100+i2*10+i3]++;
						h[i1*100+i2*10]++;
						h[i1*100+i3]++;
						h[i2*10+i3]++;
						
					}
			if(ans1.size()>ans.size())
				ans=ans1;
		}
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]/100<<" "<<(ans[i]/10)%10<<" "<<ans[i]%10<<endl; 		
	}
	
	return 0;
}
