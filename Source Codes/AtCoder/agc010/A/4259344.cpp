#include<iostream>
#include<cstdio>
using namespace std;
int cnt_odd,cnt_even;
int main(){
	int n;
	scanf("%d",&n);
	int temp;
	for(int i = 0;i < n;i ++){
		scanf("%d",&temp);
		if((temp & 1) == 0){
			cnt_even++;
		}
		else{
			cnt_odd ++;
		}
	}
	if((cnt_odd & 1) != 0){
		printf("NO");
		return 0;
	}
	printf("YES");
	return 0;
}