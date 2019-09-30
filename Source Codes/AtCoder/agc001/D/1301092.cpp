#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

const int M = 110;

int a2[M];
vector<int>odd;
vector<int>even;
vector<int> a;
vector<int> b;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &a2[i]);
		if(a2[i]&1)odd.push_back(a2[i]);
		else even.push_back(a2[i]);
	}
	if(odd.size()>2){
		puts("Impossible");
	}
	else{
		if(m==1){
			a.push_back(a2[0]);
			if(a2[0]-1!=0)b.push_back(a2[0]-1);		
			b.push_back(1);		
		}
		else{
			if(odd.size()>=1)a.push_back(odd[0]);
			for(int i = 0; i < even.size(); i++){
				a.push_back(even[i]);
			}
			if(odd.size()>=2)a.push_back(odd[1]);
			if(a[0]-1!=0)b.push_back(a[0]-1);
			for(int i = 1; i < a.size()-1; i++){
				b.push_back(a[i]);
			}
			//assert(((int)a.size()-1)>=0);
			b.push_back(a[(int)a.size()-1]+1);
		}
		for(int i = 0; i < a.size(); i++){
			if(i!=0)printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");
		printf("%d\n",(int)b.size());
		for(int i = 0; i < b.size(); i++){
			if(i!=0)printf(" ");
			printf("%d",b[i]);
		}
		printf("\n");
	}

}