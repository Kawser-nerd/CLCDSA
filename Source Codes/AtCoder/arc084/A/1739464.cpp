/*
http://arc084.contest.atcoder.jp/tasks/arc084_a
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=100010;
int a[MAXN],b[MAXN],c[MAXN];
int sizeA=1,sizeB=1,sizeC=1;
long long sumB[MAXN];
long long sumC[MAXN];
int getCnt(int array[], int size, int target) {
	int left=0, right=size-1;
	int ansP=-1;
	while (left<=right) {
		int mid=(left+right)>>1;
		if (array[mid] >= target)
			right = mid-1;
		else
			left=mid+1, ansP=mid;
	}
	return ansP;
}

int main() {
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	for (int i=0;i<n;i++)
		cin>>b[i];
	for (int i=0;i<n;i++)
		cin>>c[i];
	sort(a, a+n);
	sort(b, b+n);
	sort(c, c+n);

	sizeA=sizeB=sizeC=n;
	for (int i=0; i<sizeB; i++) {
		int ansP = getCnt(a, sizeA, b[i]);
		if (ansP == -1)
			sumB[i] = 0;
		else
			sumB[i] = ansP+1;
	}
	for (int i=1;i<sizeB;i++)
		sumB[i] += sumB[i-1];
	long long result = 0;
	for (int i=0;i<sizeC;i++) {
		int ansP = getCnt(b, sizeB, c[i]);
		if (ansP !=-1)
			result += sumB[ansP];
	}
	cout<<result<<endl;
	return 0;
}