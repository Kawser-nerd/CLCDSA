#include<iostream>
#define MAX(a,b) ((a)>(b)?(a):(b))

using namespace std;
int board[600][600];
int nums[600];
int m,n;
bool expand(int x, int y, int size, int start){
	int cur=start;
	for(int i=0; i<size; ++i){
		if(board[x+i][y+size-1]!=cur) return false;
		if(board[x+size-1][y+i]!=cur) return false;
		cur=1-cur;
	}
	return true;
}
int check(int x, int y, int size){
	if(x+size-1>=m || y+size-1>=n) return 0;
	int colch=board[x][y];
	for(int i=x; i<x+size; ++i){
		if(board[i][y]!= colch) return 0;
		int rowch=colch;
		for(int j=y; j<y+size; ++j){
			if(board[i][j]!=rowch) return 0;
			rowch=1-rowch;
		}
		colch= 1-colch;
	}

	while(x+size<m && y+size<n && expand(x,y,size+1, 1-board[x][y+size-1])) 
		size++;
	return size;
}
int main(){
	int cas;
	cin>>cas;
	for(int ca=1; ca<=cas; ++ca){
		cin>>m>>n;
		for(int i=0; i<m; ++i){
			string s;
			cin>>s;
			int next=0;
			for(int j=0; j<n/4; ++j){
				char c=s[j];
				if(isdigit(c))
					c-='0';
				else
					c=c-'A'+10;
				for(int k=3; k>=0; --k){
					board[i][next++]=((c>>k) & 1);
				}
			}
		}
		
		/*
		for(int i=0; i<m; ++i){
			for(int j=0; j<n; ++j){
				cout<<board[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
		*/

		int best=0;
		int tot=n*m;
		int tt;
		memset(nums,0,sizeof(nums));
		while(true){
			int bs=0, bi, bj;
			for(int i=0; i<m; ++i){
				for(int j=0; j<n; ++j){
					if(board[i][j]==-1) continue;
					if((tt=check(i,j,bs+1))){
						bi=i; bj=j; bs=tt;
					}
				}
			}
			
			best=MAX(bs, best);
			if(bs==1){
				break;
			}
			nums[bs]++;
			for(int i=bi; i<bi+bs; ++i){
				for(int j=bj; j<bj+bs; ++j){
					board[i][j]=-1;
				}
			}

//			cout<<bs<<" "<<bi<<" "<<bj<<endl;
			tot-=bs*bs;
			if(tot==0) break;
		}
		int diff=0;
		for(int i=best; i>1; --i)
			if(nums[i])diff++;
		if(tot) diff++;
		cout<<"Case #"<<ca<<": "<<diff<<endl;
		for(int i=best; i>1; --i){
			if(nums[i])
				cout<<i<<" "<<nums[i]<<endl;
		}
		if(tot) cout<<"1 "<<tot<<endl;
	}
}
