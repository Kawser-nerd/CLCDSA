#include <iostream>
#include <algorithm>
using namespace std; 



int main()
{
	//freopen("D:\\patin.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int sum = 0;
	int tmp;
	for(int i = 0;i < n;++i){
		scanf("%d",&tmp);
		sum += tmp-1;
	}	
	printf("%d\n",sum);
	return 0;	
}