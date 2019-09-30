#include<iostream>



using namespace std;
int main()
{   int x=0; int max=0; int z=1; int N; cin>>N; char str[N];
 for(int m=0;m<N;m++)
     { cin>>str[m];
	 }
     for(int i=0;i<N;i++)
{      if(str[i]=='I')
        {       x++;
      if(x>=max)
       {      max=x;}
else {      z=1;} }
      else if(str[i]=='D')
{

      x--;
if(x>=max)
       {      max=x;}
else {      z=1;}
}
      else
continue;
}
cout<<max;
return 0;

              
}