#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define debug(x) cerr<<#x<<"="<<(x)<<endl;

vector<int> sieve(int max){
	vector<int> composite(max/64+1);
	vector<int> primes(1, 2);
	max=(max-1)/2;
	int i, j, p;
	for(i=1, j=4; j<=max; j+=++i<<2)
		if(!(composite[i>>5]&(1<<(i&31)))){
			primes.push_back(p=2*i+1);
			for(int k=j; k<=max; k+=p)
				composite[k>>5]|=1<<(k&31);
		}
	for(; i<=max; i++)
		if(!(composite[i>>5]&(1<<(i&31))))
			primes.push_back(2*i+1);
	return primes;
}
vector<int> primes(sieve(1000030));


void eval(){
	long long N;
	scanf("%lld", &N);
	long long best=0, worst=1;
	for(int i=0; (long long)primes[i]*primes[i]<=N; i++){
		best++;
		for(long long j=primes[i]; j<=N; j*=primes[i])
			worst++;
	}
	if(N==1)
		best++;
	printf("%lld\n", worst-best);
}

int main(){
	int cases;
	string line;
	getline(cin, line);
	istringstream(line)>>cases;
	for(int i=1; i<=cases; i++){
		cout<<"Case #"<<i<<": ";
		eval();
	}
	return 0;
}
