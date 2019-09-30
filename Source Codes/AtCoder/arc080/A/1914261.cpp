#include<iostream>
using namespace std;
int main ()  
{  
    int n;  
    cin>>n;
    if(n>=2&&n<=100000)
	{
		int a=0,b=0,m,t;  
    	for(int i=0;i<n;i++)  
    	{  
        	cin>>t;
			if(t<1&&t>1000000000)
			goto loop;  
        	if(t%2==0)  
        	a++;  
        	if(t%4==0)  
        	b++;  
    	}  
    	m=a-b;  
    	if(n<=2*b+m&&m!=0)  
    	cout<<"Yes";  
    	else if(n<=2*b+1&&m==0)  
    	cout<<"Yes";  
    	else  
    	loop: cout<<"No";  
	}
    cout<<endl;
    return 0;
}