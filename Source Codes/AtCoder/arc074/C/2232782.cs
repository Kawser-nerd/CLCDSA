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
		
		bool[][][] forbid = new bool[N+1][][];
		for(int i=0;i<N+1;i++){
			forbid[i] = new bool[N+1][];
			for(int j=0;j<N+1;j++){
				forbid[i][j] = new bool[N+1];
			}
		}
		
		for(int k=0;k<M;k++){
			int r = R[k];
			int l = L[k];
			int x = X[k];
			for(int i=0;i<r;i++){
				for(int j=0;j<r;j++){
					int cnt = 1;
					if(l <= i) cnt++;
					if(l <= j) cnt++;
					if(cnt != x){
						forbid[r][i][j] = true;
						forbid[r][j][i] = true;
						forbid[i][r][j] = true;
						forbid[i][j][r] = true;
						forbid[j][i][r] = true;
						forbid[j][r][i] = true;
					}
				}
			}
		}
		
		int mod = (int)1e9 + 7;
		int[][][] dp = new int[N+1][][];
		for(int i=0;i<N+1;i++){
			dp[i] = new int[N+1][];
			for(int j=0;j<N+1;j++){
				dp[i][j] = new int[N+1];
			}
		}
		
		dp[0][0][0] = 1;
		for(int i=0;i<=N;i++){
			for(int j=0;j<=N;j++){
				for(int k=0;k<=N;k++){
					
					if(forbid[i][j][k]){
						dp[i][j][k] = 0;
						continue;
					}
					int nxt = 1 + Math.Max(Math.Max(i, j), k);
					if(nxt > N) continue;
					dp[nxt][j][k] += dp[i][j][k]; if(dp[nxt][j][k] >= mod) dp[nxt][j][k] -= mod;
					dp[i][nxt][k] += dp[i][j][k]; if(dp[i][nxt][k] >= mod) dp[i][nxt][k] -= mod;
					dp[i][j][nxt] += dp[i][j][k]; if(dp[i][j][nxt] >= mod) dp[i][j][nxt] -= mod;
				}
			}
		}
		
		int tot = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				tot += dp[i][j][N]; if(tot >= mod) tot -= mod;
				tot += dp[i][N][j]; if(tot >= mod) tot -= mod;
				tot += dp[N][i][j]; if(tot >= mod) tot -= mod;
			}
		}
		Console.WriteLine(tot);
		
	}
	int N, M;
	int[] L,R,X;
	public Sol(){
		var d = ria();
		N = d[0]; M = d[1];
		L = new int[M];
		R = new int[M];
		X = new int[M];
		for(int i=0;i<M;i++){
			d = ria();
			L[i] = d[0]; R[i] = d[1]; X[i] = d[2];
		
		}
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