#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>

const int INF = 1000000009;
const long LINF = 1123456789012345678;

long a, b, q;

std::set<long> s, t;

long solve(long x){
	long s1, s2, t1, t2;
	auto its = s.lower_bound(x);
	s2 = *its;
	s1 = *(--its);
	auto itt = t.lower_bound(x);
	t2 = *itt;
	t1 = *(--itt);
	//printf("  %ld %ld %ld %ld\n", s1, s2, t1, t2);
	long ret = LINF;
	ret = std::min(ret, std::max(s2, t2) - x);
	//printf("  (%ld ", ret);
	ret = std::min(ret, x - std::min(s1, t1));
	//printf("%ld ", ret);
	ret = std::min(ret, std::min(s2-x, x-t1) + s2-t1);
	//printf("%ld ", ret);
	ret = std::min(ret, std::min(t2-x, x-s1) + t2-s1);
	//printf("%ld)\n", ret);
	return ret;
}
	

int main(){
	scanf("%ld %ld %ld", &a, &b, &q);
	for(int i = 0; i < a; i++){
		long k;
		scanf("%ld", &k);
		s.insert(k);
	}
	for(int i = 0; i < b; i++){
		long k;
		scanf("%ld", &k);
		t.insert(k);
	}
	s.insert(-LINF);
	s.insert(LINF);
	t.insert(-LINF);
	t.insert(LINF);
	for(int i = 0; i < q; i++){
		long k;
		scanf("%ld", &k);
		printf("%ld\n", solve(k));
	}
	return 0;
}