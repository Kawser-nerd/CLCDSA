#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;
typedef long long LL;
int m(int a, int b){
	int a1 = a/4;
	int a2 = a % 4;
	int b1 = b/4;
	int b2 = b%4;
	int c = (a1+b1)%2;
	if(a2 == 0 || b2 == 0) return (c*4+a2+b2)%8;
	if(a2 == b2)           return (c*4+4)%8;
	if(a2 == 1 && b2 == 2) return (c*4+3)%8;
	if(a2 == 2 && b2 == 3) return (c*4+1)%8;
	if(a2 == 3 && b2 == 1) return (c*4+2)%8;
	if(a2 == 2 && b2 == 1) return (c*4+7)%8;
	if(a2 == 3 && b2 == 2) return (c*4+5)%8;
	if(a2 == 1 && b2 == 3) return (c*4+6)%8;
}
main() {
	FILE *fin = freopen("C-large.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("C-large.out", "w", stdout);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		LL l, x;
		cin >> l >> x;
		string k;
		cin >> k;
		int prodseg = 0;

		/*cout << endl;
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				cout << m(i,j) << " ";
			}
			cout << endl;
		}*/

		for(LL i = 0; i < l; i++){
			int num = k[i] - 'h';
			prodseg = m(prodseg, num);
		}
		//cout << prodseg << endl;
		int total = 0;
		for(LL i = 0; i < (x%4); i++){
			total = m(prodseg, total);
		}
		if(total != 4){
			cout << "NO" << endl;
			continue;
		}
		LL minleft = -1;
		int lprod = 0;
		for(LL i = 0; i < 5*l; i++){
			int num = k[i%l] - 'h';
			lprod = m(lprod, num);
			if(lprod == 1){
				minleft = i+1;
				break;
			}
		}
		LL minright = -1;
		int rprod = 0;
		for(LL i = 5*l-1; i >=0; i--){
			int num = k[i%l] - 'h';
			rprod = m(num, rprod);
			if(rprod == 3){
				minright = 5*l-i;
				break;
			}
		}
		if(minleft == -1 || minright == -1){
			cout << "NO" << endl;
			continue;
		}
		if(minleft + minright < l*x){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}
	exit(0);
}