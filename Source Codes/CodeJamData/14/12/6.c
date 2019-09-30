#include <stdio.h>
int a[1001][1001];
int b[1001][1001];

int go(int root, int n, int parent) {
	int i;
	int m1 = 0, m2 = 0;
	if(root == n) {
		if(a[n][0] < 2) {
			return 1;
		}
		for(i = 1; i <= a[n][0]; i++) {
			int answer = go(root, a[n][i], n);
			if(m1 < answer) {
				m2 = m1;
				m1 = answer;
			}
			else if(m2 < answer) {
				m2 = answer;
			}
		}
		return m1 + m2 + 1;
	}
	else {
		int index;
		for(index = 1; index <= a[n][0]; index++) {
			if(a[n][index] == parent) 
				break;
		}
		if(b[n][index] > 0) {
			return b[n][index];
		}
			
		if(a[n][0] < 3) {
			return 1;
		}
	
		for(i = 1; i <= a[n][0]; i++) {
			if(a[n][i] != parent) {
				int answer = go(root, a[n][i], n);
				if(m1 < answer) {
					m2 = m1;
					m1 = answer;
				}
				else if(m2 < answer) {
					m2 = answer;
				}
			}
		}
		b[n][index] = m1 + m2 + 1;
		return m1 + m2 + 1;
	}
}


int main() {
	int T, N;
	int t, i, j;

	scanf("%d", &T);

	
	for(t=1;t<=T;t++) {
		scanf("%d", &N);
		for(i=0;i<=N;i++) {
			a[i][0] = 0;
		}
		

		for(i = 0;i < N-1;i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[x][ ++a[x][0] ] = y;
			a[y][ ++a[y][0] ] = x;
			b[x][ a[x][0] ] = -1;
			b[y][ a[y][0] ] = -1;
		}

		int root;
		int answer;
		int max = 0;
		for(root = 1; root <= N; root++) {
			answer = go(root, root, -1);
			if( max < answer )
				max = answer;
		}
		printf("Case #%d: %d\n", t, N-max);
	}



}

