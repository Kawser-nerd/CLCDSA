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
		
		int N = S.Length;
		long[] dp = new long[4];
		long mod = (long) 1e9 + 7;
		dp[0] = 1;
		for(int i=0;i<N;i++){
			long[] nxt = new long[4];
			
			if(S[i] == 'A' || S[i] == '?'){
				for(int j=0;j<4;j++){
					nxt[j] += dp[j]; if(nxt[j] >= mod) nxt[j] -= mod;
				}
				nxt[1] += dp[0]; if(nxt[1] >= mod) nxt[1] -= mod;
			}
			if(S[i] == 'B'|| S[i] == '?'){
				for(int j=0;j<4;j++){
					nxt[j] += dp[j]; if(nxt[j] >= mod) nxt[j] -= mod;
				}
				nxt[2] += dp[1]; if(nxt[2] >= mod) nxt[2] -= mod;
			}
			if(S[i] == 'C'|| S[i] == '?'){
				for(int j=0;j<4;j++){
					nxt[j] += dp[j]; if(nxt[j] >= mod) nxt[j] -= mod;
				}
				nxt[3] += dp[2]; if(nxt[3] >= mod) nxt[3] -= mod;
			}
			dp = nxt;
		}
		
		Console.WriteLine(dp[3]);
		
	}
	String S;
	public Sol(){
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