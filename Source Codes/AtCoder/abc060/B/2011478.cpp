#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int a, b, c;
int main()
{
	scanf("%d%d%d", &a, &b, &c);
	for(int i = 1; i < 1000000; i++)
	{
		if(((i * a) % b == c % b)) 
    	{
    		printf("YES\n");
    		return 0;
		}
	}
	printf("NO\n");
}