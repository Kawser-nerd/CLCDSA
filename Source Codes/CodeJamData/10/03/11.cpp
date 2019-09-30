#include <cstdio>
#include <cstring>

int r , k , n;
int a[2048];
int used[2048];
long long save[2048];

void read() {
	int i;
	
	scanf ( "%d%d%d" , &r , &k , &n );
	for (i = 1; i <= n; i++) {
		scanf ( "%d" , &a[i] );
		a[n + i] = a[i];
	}
}

void solve() {
	int i , j;
	int cur = 1;
	
	int moves = 0 , now;
	long long cost = 0 , ans = 0;
	
	memset ( used , 0 , sizeof used );
	
	for (i = 1; i <= n; i++) {
		if ( used[cur] )
			break;
		used[cur] = moves + 1;
		save[cur] = cost;
		
		now = k;
		for (j = 0; j < n; j++) 
			if ( now - a[cur + j] >= 0 ) 
				now -= a[cur + j];
			else
				break;
			
		cost += k - now;
		moves ++;
		
		cur += j;
		if ( cur > n ) cur -= n;
	}
	
	if ( moves <= r ) {
		moves -= used[cur] - 1;
		r -= used[cur] - 1;
		ans += save[cur];
		
		ans += (cost - save[cur]) * (r / moves);
		r %= moves;
	} else
		cur = 1;
	
	while ( r -- ) {
		now = k;
		for (j = 0; j < n; j++) 
			if ( now - a[cur + j] >= 0 )
				now -= a[cur + j];
			else
				break;
			
		ans += k - now;
		
		cur += j;
		if ( cur > n ) cur -= n;
	}
	
	printf ( "%lld\n" , ans );
}

int main() {
	int cases;
	int i;
	
	scanf ( "%d" , &cases );
	for (i = 1; i <= cases; i++) {
		printf ( "Case #%d: " , i );
		
		read();
		solve();
		
//		return 0;
	}
	
	return 0;
}
