#include<iostream>
using namespace std;
int a,b,c,d,e,f,x[10000],y[10000];
int main()
{
	cin>>a>>b>>c>>d>>e>>f;
	x[0]=y[0]=1;
	for(int i=0;i<=f;i++)
	{
		if(x[i])x[i+100*a]=x[i+100*b]=1;
		if(y[i])y[i+c]=y[i+d]=1;
	}
	int w=100*a,s=0;
	for(int i=100;i<=f;i+=100)
		if(x[i])for(int j=0;j<=min(i/100*e,f-i);j++)
			if(y[j]&&s*i<j*w)w=i,s=j;
	cout<<w+s<<' '<<s<<endl;
	return 0;
}