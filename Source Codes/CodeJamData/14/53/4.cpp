#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n;
pair<char, int> ev[2000];
int T, teste;

int entrances[3500];
int exits[3500];

struct compbigexit {
	bool operator() (int a, int b) {
		if (exits[a] != exits[b]) return exits[a] > exits[b];
		return a < b;
	}
};

struct compsmallexit {
	bool operator() (int a, int b) {
		if (exits[a] != exits[b]) return exits[a] < exits[b];
		return a < b;
	}
};

struct compsmallenter {
	bool operator() (int a, int b) {
		if (entrances[a] != entrances[b]) return entrances[a] < entrances[b];
		return a < b;
	}
};

set<int> inside;
set<int,compbigexit> long_exit;
set<int,compsmallexit> premature_exit;
set<int,compsmallenter> premature_enter;

void update(int i) {
	long_exit.erase(i);
	premature_enter.erase(i);
	premature_exit.erase(i);

	if (inside.count(i)){
		long_exit.insert(i);
		if (entrances[i] < exits[i]) 
			premature_enter.insert(i);
	}
	else {
		if (exits[i] < entrances[i]) 
			premature_exit.insert(i);
	}
}

bool is_feasible(int unknown) {
	int clear = 0;
	
	for (int i = 0; i <= 3100; i++) {
		entrances[i] = 6000;
		exits[i] = 6001;
	}	

	for (int i = 0; i < n; i++) {
		if (ev[i].second != 0) {
			if (ev[i].first == 'E') {
				if (entrances[ev[i].second] == 6000)
					entrances[ ev[i].second ] = i;
			}
			else {
				if (exits[ ev[i].second ] == 6001)
					exits[ ev[i].second ] = i;
			}
		}
	}

	for (int i = 0; i <= 3100; i++) update(i);
	
	int throwaway = 3100;

	for (int k = 0; k < n + unknown; k++) {
		if (k < unknown) {
			int mid = -1;

			if (!premature_exit.empty()) mid = *premature_exit.begin();

			if (mid == -1) {
				mid = throwaway--;
			}

			inside.insert(mid);

			update(mid);
		} 

		else {
			int i = k-unknown;
			
			if (ev[i].first == 'E') {
				if (ev[i].second == 0) {
					int mid = -1;

					if (!premature_exit.empty()) mid = *premature_exit.begin();

					if (mid == -1) {
						mid = throwaway--;
					}

					inside.insert(mid);
					update(mid);
				}

				else {
					if (inside.count(ev[i].second)) return false;
					inside.insert(ev[i].second);

					int id = ev[i].second;

					long_exit.erase(id);
					premature_enter.erase(id);
					premature_exit.erase(id);

					bool found = false;
					for (int j = i+1; j < n; j++) {
						if (ev[j].first == 'E' && ev[j].second == ev[i].second) {
							entrances[id] = j;
							found = true;
							break;
						}
					}
					if (!found) entrances[id] = 6000;

					update(id);
				}
			}

			else {
				if (inside.size() == 0) return false;

				if (ev[i].second == 0) {
					int mid = -1;

					if (!premature_enter.empty()) mid = *premature_enter.begin();
					else mid = *long_exit.begin();

					inside.erase(mid);
					update(mid);
				}

				else {
					if (!inside.count(ev[i].second)) return false;
					inside.erase(ev[i].second);

					int id = ev[i].second;

					long_exit.erase(id);
					premature_enter.erase(id);
					premature_exit.erase(id);

					bool found = false;
					for (int j = i+1; j < n; j++) {
						if (ev[j].first == 'L' && ev[j].second == ev[i].second) {
							exits[id] = j;
							found = true;
							break;
						}
					}
					if (!found) exits[id] = 6001;

					update(id);
				}
			}
		}
	}

	return true;
}

int main() {	
	for (scanf("%d", &T) ;T ;T--) {
		printf("Case #%d: ", ++teste);
		fprintf(stderr, "At case %d\n", teste);

		scanf("%d", &n);
		int tot = 0;
		for (int i = 0; i < n; i++) {
			scanf(" %c %d", &ev[i].first, &ev[i].second);
			if (ev[i].first == 'E') tot++;
			else tot--;
		}

		int best = 1000000;
		int st = 0, end = 1100;
		while (st < end && st <= 1000) {
			int mid = (st+end)/2;
			inside.clear();
			long_exit.clear();
			premature_exit.clear();
			premature_enter.clear();

			if (is_feasible(mid)) {
				end = mid;
			}
			else st = mid+1;
		}

		if (st > 1000) printf("CRIME TIME\n");
		else printf("%d\n", st+tot);
	}
}