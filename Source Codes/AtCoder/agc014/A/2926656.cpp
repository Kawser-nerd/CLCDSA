#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		if(a%2!=0||b%2!=0||c%2!=0)cout<<"0"<<endl;
		else if(a==b&&b==c){cout<<"-1"<<endl;}
		else
		{
		    int count=0;
		    for(;;)
		    {
			    int t1,t2,t3;
			    t1=(b+c)/2;t2=(a+c)/2;t3=(a+b)/2;
			    a=t1;b=t2;c=t3;
			    count++;
			    if(a%2!=0||b%2!=0||c%2!=0)
			    {  
				    cout<<count<<endl;break;
			    }
		    }   
		}
	}
	return 0;
}