// 

#include <vector>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define INF 2000
#define F first
#define S second
typedef pair< int, int > ii;

const int N = 10;

int n, start, finish;
int cost[N][N]; // adjacency matrix
int freq[10]; // number of each digit on the wall

priority_queue< ii, vector< ii >, greater< ii > > pq;

int dist[N];
bool visit[N];

int row, col;

void input ()
{
	cin >> row >> col;
	
	for (int i = 0; i < 10; ++i) 
	for (int j = 0; j < 10; ++j) cin >> cost[j][i]; // reversed
	
	int digit;
	for (int i = 1; i <= row; ++i)
	for (int j = 1; j <= col; ++j) {
		cin >> digit;
		if (digit != -1) ++freq[digit];
	}
}

void init ()
{
	for (int i = 0; i < 10; ++i) dist[i] = INF;
	dist[1] = 0;
	pq.emplace(0, 1);
}

void get_to_every_digit_from_one ()
{
	input();
	init();
	
	int proc;
	while (!pq.empty())
	{
		proc = pq.top().second;
		pq.pop();
		
		if (visit[proc]) continue;
		visit[proc] = true;
		
		int temp;
		int adj;
		for (int i = 0; i < 10; ++i) {
			
			adj = i;
			temp = cost[proc][i] + dist[proc];
			
			if (temp < dist[adj]) {
				dist[adj] = temp;
				pq.emplace(temp, adj);
			}
		}
	}
	
	long long ans = 0;
	for (int i = 0; i < 10; ++i) {
		ans += (long long) dist[i]*freq[i];
	}
	
	cout << ans << "\n";
	
	return;
}

int main ()
{
	get_to_every_digit_from_one();
	return 0;
}