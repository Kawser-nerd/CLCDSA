#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int maxcolour=0;
bool running=false;

int proc(vector<int> &colours,vector<vector<int> > &walls,int start,int end) {
	int minv=10000;
	int curv=1;
	int cvertex=start;
	int newcolour=1;
	//clog << "startproc " << start << " to " << end << endl;
	// find which vertex will lead to end vertex
	/*int wallindexend=upper_bound(walls[end].begin(),walls[end].end(),start)-walls[end].begin();
	if (wallindexend==walls[end].size()) wallindexend=end-1;
	else wallindexend=walls[end][wallindexend];*/
	while (cvertex!=end) {
		while (newcolour==colours[start] || newcolour==colours[end]) newcolour++;
		curv++;
		int wallindex=lower_bound(walls[cvertex].begin(),walls[cvertex].end(),end+(cvertex!=start))-walls[cvertex].begin()-1;
		if (wallindex==-1) {
			//cvertex++;
			int newvertex=cvertex+1;
			if (newvertex==end) break;

			if (newcolour>maxcolour) {
				//if (cvertexwallindexend)
				if (colours[cvertex]==maxcolour || colours[end]==maxcolour) {
					if (colours[cvertex]==maxcolour-1 || colours[end]==maxcolour-1) colours[newvertex]=maxcolour-2;
					else colours[newvertex]=maxcolour-1;
				}
				else colours[newvertex]=maxcolour;
			}
			else colours[newvertex]=newcolour++;

			cvertex=newvertex;
			//continue;
		}
		else {
			// follow last wall less than end
			int newvertex=walls[cvertex][wallindex];
			//for (int k=0;k<walls[cvertex].size();k++) clog << walls[cvertex][k] << " ";
			//clog << endl;
			if (newvertex!=end) {
				//colours[newvertex]=newcolour++;

				if (newcolour>maxcolour) {
					if (colours[cvertex]==maxcolour || colours[end]==maxcolour) {
						if (colours[cvertex]==maxcolour-1 || colours[end]==maxcolour-1) colours[newvertex]=maxcolour-2;
						else colours[newvertex]=maxcolour-1;
					}
					else colours[newvertex]=maxcolour;
				}
				else colours[newvertex]=newcolour++;

			}
			//if (cvertex==0 && newvertex==0) {clog << "eee" << endl; return 0;}
			int vers = proc(colours,walls,cvertex,newvertex);
			if (minv>vers) minv=vers;

			cvertex=newvertex;
		}
	}

	if (newcolour<=maxcolour && running) cout << "error" << endl;
	if (minv>curv) minv=curv;
	return minv;
}

int main() {
	int T;

	cin >> T;

	for (int t=1;t<=T;t++) {
		int N, M;
		cin >> N >> M;

		vector<int> colours;
		vector<int> U, V;

		vector<vector<int> > walls;
		for (int i=0;i<N;i++) {
			walls.push_back(vector<int>());
			colours.push_back(-1);
		}
		for (int i=0;i<M;i++) {
			int z;
			cin >> z;
			U.push_back(z);
		}
		for (int i=0;i<M;i++) {
			int z;
			cin >> z;
			V.push_back(z);
		}
		for (int i=0;i<M;i++) {
			int u=U[i],v=V[i];
			u--;
			v--;
			if (v<u) {int t=v;v=u;u=t;}
			walls[u].push_back(v);
			//clog << "w " << u << " gets " << v << endl;
		}
		for (int i=0;i<N;i++) {
			sort(walls[i].begin(),walls[i].end());
		}

		// start at vertex 0, which shall be predetermined
		//clog << "start" << endl;
		maxcolour=N;
		colours[0]=2;
		colours[N-1]=1;
		running=false;
		maxcolour=proc(colours,walls,0,N-1);
		//clog << "maxcolour: " << maxcolour << endl;
		/*cout << N << " " << M << endl;
		for (int i=0;i<M;i++) {
			cout << U[i] << " ";
		}
		cout << endl;
		for (int i=0;i<M;i++) {
			cout << V[i] << " ";
		}
		cout << endl;*/
		running=true;
		proc(colours,walls,0,N-1);


		cout << "Case #" << t << ": " << maxcolour << endl << colours[0];
		for (int i=1;i<N;i++) {
			cout << " " << colours[i];
		}
		cout << endl;
	}

	return 0;
}