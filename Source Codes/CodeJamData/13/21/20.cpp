#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> V; int A,N;

void input()
{
	scanf ("%d %d",&A,&N); int i,x;
	V.clear();
	for (i=0;i<N;i++){
		scanf ("%d",&x);
		V.push_back(x);
	}
	sort(V.begin(),V.end());
}

int proc(vector<int> U, long long V)
{
	if (V == 1) return U.size();
	if (U.empty()) return 0;

	int i;
	for (i=0;i<U.size();i++){
		if (U[i] < V) V += U[i];
		else break;
	}
	U.erase(U.begin(),U.begin()+i);
	return min(proc(U,V*2-1)+1,(int)U.size());
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test,Case=1;
	scanf ("%d",&Test); while (Test--){
		input();
		printf ("Case #%d: ",Case++);
		printf ("%d\n",proc(V,A));
	}

	return 0;
}
