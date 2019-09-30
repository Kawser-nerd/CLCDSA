#include<stdio.h>
#include<string.h>
#define MAXNUM 10000000

int isValid(long long num){
	long long tmp = num, rvTmp = 0;
	while(tmp > 0){
		rvTmp = rvTmp*10 + tmp%10;
		tmp /= 10;
	}
	return rvTmp == num;
}

int bSearch(long long A, long long nums[], int p){
	int st=0, ed=p-1, mid;
	if(A == 1)
		return -1;
	while(st<=ed){
		mid = (st+ed)>>1;
		if(nums[mid] == A)
			return mid-1;
		else if(nums[mid] > A)
			ed = mid-1;
		else
			st = mid+1;
	}
	return ed;
}

int main(){
	int T, nCase = 1, idxA, idxB, p=0;
	long long A, B, nums[50], i, res;
	memset(nums, 0, sizeof(nums));

	freopen("C-large-1.in", "r", stdin);
	freopen("C-large-1.out", "w", stdout);

	for(i=1; i<=MAXNUM; i++){
		if(isValid(i) && isValid(i*i)){
			nums[p++] = i*i;
		}
	}

	scanf("%d", &T);
	while(T--){
		scanf("%Ld%Ld", &A, &B);
		idxA = bSearch(A, nums, p);
		idxB = bSearch(B, nums, p);
		if(nums[idxB+1] == B)
			idxB++;

		res = idxB - idxA;
		printf("Case #%d: %Ld\n", nCase, res);
		nCase++;
	}
	return 0;
}
