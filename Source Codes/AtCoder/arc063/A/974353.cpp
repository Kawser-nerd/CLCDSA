#include <iostream>
#include <string>

using namespace std;

#define REP(i,m,n) for(int i=m;i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define ALL(x) (x).begin(),(x).end()


int main(){
	string str;
	cin >> str;
	int counter = 0;
	char before = str[0], after;
	REP(i,1,str.size()){
		after = str[i];
		if(after != before) counter++;
		before = after;
	}
	printf("%d\n", counter);

	return 0;
}