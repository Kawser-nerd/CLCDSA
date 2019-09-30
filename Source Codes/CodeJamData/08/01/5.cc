#include<iostream>
#include<string>
#include<map>
using namespace std;

int queries[1024];
int mswitch[1024];

int main(){
	int N; cin >> N;
	for(int t=1; t<=N; t++){
		int S, Q;
		cin >> S;
		map<string,int> engines;
		int en=0; string line; getline(cin, line);
		for(int i=0; i<S; i++){
			getline(cin, line);
			engines[line]=en++;
		}
		cin >> Q; 
		getline(cin,line);
		for(int i=0; i<Q; i++){
			getline(cin, line);
			queries[i]=engines[line];
		}

		if(Q==0)mswitch[0]=0;
		for(int i=Q-1; i>=0; i--){
			mswitch[i]=Q+100;
			for(int j=0; j<S; j++){
				if(j==queries[i])continue;
				int nj=i;
				for(; nj<Q && queries[nj]!=j; nj++);
				if(nj==Q)mswitch[i]=0;
				else mswitch[i]=min(mswitch[i], 1+mswitch[nj]);
			}
		}
		cout << "Case #" << t << ": " << mswitch[0] << "\n";
	}
}
