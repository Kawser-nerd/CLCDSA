#include <iostream>

using namespace std;

int main()
{
	int a,b,c;
  	cin >> a >> b >> c;
  
  	if(a + b >= c - 1)
    {
     	printf("%d",b+c);
    }
	else
    {
    	printf("%d",b + (a+b+1));
    }
	return 0;
}