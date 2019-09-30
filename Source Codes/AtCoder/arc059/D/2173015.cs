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
	const long mod = (long) 1e9 + 7;
	public void Solve(){
		
		long[] dp = new long[N+1];
		dp[0] = 1;
		for(int i=0;i<N;i++){
			long[] nxt = new long[N+1];
			for(int j=0;j<N;j++){
				if(dp[j] == 0) continue;
				if(j == 0){
					nxt[0] += dp[j]; if(nxt[0] >= mod) nxt[0] -= mod;
				} else {
					nxt[j - 1] += dp[j]; if(nxt[j - 1] >= mod) nxt[j - 1] -= mod;
					nxt[j - 1] += dp[j]; if(nxt[j - 1] >= mod) nxt[j - 1] -= mod;
				}
				nxt[j + 1] += dp[j]; if(nxt[j + 1] >= mod) nxt[j + 1] -= mod;
			}
			dp = nxt;
		}
		Console.WriteLine(dp[S.Length]);
		
		
	}
	int N;
	String S;
	public Sol(){
		N = ri();
		S = rs();
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