using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class TEST{
	static void Main(){
		Sol mySol =new Sol();
		mySol.Solve();
	}
}

class Sol{
	public void Solve(){
		
		long Inf = (long) 1e18;
		long[][] min = new long[H][];
		bool[][] used = new bool[H][];
		for(int i=0;i<H;i++){
			min[i] = new long[W];
			used[i] = new bool[W];
			for(int j=0;j<W;j++) min[i][j] = Inf;
		}
		int[][] m = new int[H][];
		for(int i=0;i<H;i++){
			m[i] = new int[W];
			for(int j=0;j<W;j++) m[i][j] = S[i][j] == '#' ? 1 : 0;
		}
		Init(m);
		
		
		int r0 = 0, c0 = 0;
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(S[i][j] == 'S'){
					r0 = i; c0 = j;
				}
			}
		}
		
		var Q = new Queue<int>();
		min[r0][c0] = 0;
		Q.Enqueue(enc(r0,c0));
		while(Q.Count>0){
			var rc = Q.Dequeue();
			int r = decR(rc);
			int c = decC(rc);
			for(int t=0;t<4;t++){
				int nr = r + dy[t];
				int nc = c + dx[t];
				if(!InRange(nr,0,H) || !InRange(nc,0,W))continue;
				if(S[nr][nc] == '#') continue;
				if(min[nr][nc] != Inf) continue;
				min[nr][nc] = min[r][c] + 1;
				Q.Enqueue(enc(nr,nc));
			}
		}
		long ans = Inf;
		
		
		
		
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(min[i][j] > K) continue;
				if(i == 0 || i == H-1 || j == 0 || j == W-1 && min[i][j] < K){
					Console.WriteLine(1);
					return;
				}
				
				long turn = 0;
				turn = (i - 1)/K + 1 + 1; ans = Math.Min(ans,turn);
				turn = (H-i-1 - 1)/K + 1 + 1; ans = Math.Min(ans,turn);
				turn = (j - 1)/K + 1 + 1; ans = Math.Min(ans,turn);
				turn = (W-j-1 - 1)/K + 1 + 1; ans = Math.Min(ans,turn);
				
			}
		}
		
		
		Console.WriteLine(ans);
	}
	
	int[] dy = new int[] {0, 1, 0, -1};
	int[] dx = new int[] {1, 0, -1, 0};
	bool InRange(int t, int l, int r){
		return l <= t && t < r;
	}
	
	void Init(int[][] M){
		acc = new int[H+1][];
		for(int i=0;i<=H;i++){
			acc[i] = new int[W+1];
			if(i == 0) continue;
			for(int j=1;j<=W;j++){
				acc[i][j] = M[i-1][j-1];
			}
		}
		
		for(int i=1;i<=H;i++){
			for(int j=1;j<=W;j++){
				acc[i][j] += acc[i][j-1];
			}
		}
		for(int j=1;j<=W;j++){
			for(int i=1;i<=H;i++){
				acc[i][j] += acc[i-1][j];
			}
		}
	}
	
	static int[][] acc;
	static int cal(int x1,int y1,int x2,int y2){
		//return num of land [x1,x2)*[y1,y2); left-inclusive / right-noninclusive;
		if(x2<x1||y2<y1)return 0;
		return acc[y2][x2]-acc[y2][x1]-acc[y1][x2]+acc[y1][x1];
	}
	
	
	
	
	
	int enc(int r, int c){ return (r*1024) | c;}
	int decR(int rc){ return rc / 1024;}
	int decC(int rc){ return rc % 1024;}
	
	
	int H,W;
	long K;
	String[] S;
	public Sol(){
		var d = ria();
		H = d[0]; W = d[1]; K = d[2];
		S = new String[H];
		for(int i=0;i<H;i++) S[i] = rs();
		
		
	}

	static String rs(){return Console.ReadLine();}
	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(char sep=' '){return Console.ReadLine().Split(sep);}
	static int[] ria(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>int.Parse(e));}
	static long[] rla(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>long.Parse(e));}
	static double[] rda(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>double.Parse(e));}
}