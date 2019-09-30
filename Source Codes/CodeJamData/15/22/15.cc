#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long i64;
#define fu(i,m,n) for(int i=m; i<n; i++)
#define fr(i,m,n) for(typeof(m) i=m; i!=n; i++)
#define fa(i,c) fr(i,(c).begin(),(c).end())

int comp(const vector<vector<int> >& board, int r, int c) {
    return board[r-1][c]+board[r+1][c] + board[r][c+1]+board[r][c-1];
}

int solve(int R, int C, int N) {

    int S,T;
    {
        int n = N;
        S = 0;

        vector<vector<int> > board(R+2, vector<int>(C+2));
        fu(r,1,R+1) fu(c,1,C+1) board[r][c]=0;

        fu(r,1,R+1) fu(c,1,C+1) if(n && comp(board,r,c)==0) { n--; S+=0; board[r][c]=1; }
        fu(r,1,R+1) fu(c,1,C+1) if(n && comp(board,r,c)==1) { n--; S+=1; board[r][c]=1; }
        fu(r,1,R+1) fu(c,1,C+1) if(n && comp(board,r,c)==2) { n--; S+=2; board[r][c]=1; }
        fu(r,1,R+1) fu(c,1,C+1) if(n && comp(board,r,c)==3) { n--; S+=3; board[r][c]=1; }
        fu(r,1,R+1) fu(c,1,C+1) if(n && comp(board,r,c)==4) { n--; S+=4; board[r][c]=1; }

        assert(n==0);
    }

    {
        int n = R*C-N;
        T = (R-1)*C + (C-1)*R;

        vector<vector<int> > board(R+2, vector<int>(C+2));
        fu(r,1,R+1) fu(c,1,C+1) board[r][c]=1;

        fu(r,1,R+1) fu(c,1,C+1) if(n && comp(board,r,c)==4) { n--; T-=4; board[r][c]=0; }
        fu(r,1,R+1) fu(c,1,C+1) if(n && comp(board,r,c)==3) { n--; T-=3; board[r][c]=0; }
        fu(r,1,R+1) fu(c,1,C+1) if(n && comp(board,r,c)==2) { n--; T-=2; board[r][c]=0; }
        fu(r,1,R+1) fu(c,1,C+1) if(n && comp(board,r,c)==1) { n--; T-=1; board[r][c]=0; }
        fu(r,1,R+1) fu(c,1,C+1) if(n && comp(board,r,c)==0) { n--; T-=0; board[r][c]=0; }

        assert(n==0);
    }

    return min(S,T);

}

int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		cout << "Case #" << ts << ": ";
        int R,C,N;
        cin >> R >> C >> N;
        cout << solve(R,C,N) << endl;
	}
}
