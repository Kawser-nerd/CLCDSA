#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
char cs[105];
vector<int> parens;
int insert;
int depth;
int main() {
	scanf("%d",&n);
	scanf("%s",cs);
	for(int i=0;i<n;i++){
		if(cs[i]=='(')depth++;
		else depth--;
		if(depth<0){
			insert++;
			depth++;
		}
	}
	while(insert--)printf("(");
	for(int i=0;i<n;i++){
		printf("%c",cs[i]);
	}
	while(depth--)printf(")");
	printf("\n");
	return 0;
}