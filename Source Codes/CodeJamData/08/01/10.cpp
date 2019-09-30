#include<iostream>
#include<map>
#include<vector>
using namespace std;
string readln(){
	char buffor[200];
	char *c=buffor;
	while((*c=getchar())!='\n') c++;
	*c=0;
	return buffor;
}

int readInt(){
	int k; scanf(" %d ",&k);
	return k;
}

int main(){
	for(int test=1, testCount=readInt(); test <= testCount; test++){
		int n = readInt();
		map<string,int> M;
		for(int i=0; i<n; i++)
			M[readln()]=i;
		int q = readInt();
		vector<int> L(n);
		for(int i=0; i<q; i++){
			int j=M[readln()];
			int minV=1000000;
			for(int r=0; r<n; r++)
				if(r!=j)
					minV<?=L[r];
			L[j]=minV+1;
		}
		printf("Case #%d: %d\n", test, *min_element(L.begin(), L.end()));
	}
	return 0;
}
	
