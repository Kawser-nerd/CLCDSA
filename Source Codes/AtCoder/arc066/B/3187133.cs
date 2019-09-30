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
		
		long mod = (long) 1e9 + 7;
		
		int L = 63;
		int[] B0 = new int[L];
		for(int i=0;i<L;i++){
			B0[i] = (int)((N >> i) & 1);
		}
		
		long ans = 0;
		
		// sum < N;
		for(int i=0;i<L;i++){
			var B = (int[]) B0.Clone();
			if(B0[i] == 0) continue;
			
			B[i] = 0;
			long[] dp = new long[2];
			dp[0] = 1;
			for(int j=0;j<i;j++){
				var nxt = new long[2];
				nxt[0] += dp[0]; //(0, 0)
				nxt[0] += dp[0]; //(1, 0)
				nxt[1] += dp[0]; //(1, 1);
				nxt[0] += dp[1]; //(0, 0)
				nxt[1] += dp[1]; //(1, 0)
				nxt[1] += dp[1]; //(1, 1);
				
				nxt[0] %= mod;
				nxt[1] %= mod;
				dp = nxt;
				
			}
			for(int j=i;j<L;j++){
				var nxt = new long[2];
				if(B[j] == 0){
					nxt[0] += dp[0]; // (0, 0);
					nxt[1] += dp[0]; // (1, 1);
					nxt[1] += dp[1]; // (1, 0);
				} else {
					nxt[0] += dp[0]; // (1, 0);
					nxt[1] += dp[1]; // (1, 1);
					nxt[0] += dp[1]; // (0, 0);
				}
				
				nxt[0] %= mod;
				nxt[1] %= mod;
				dp = nxt;
				
			}
			ans += dp[0];
			ans %= mod;
		}
		
		// sum == N;
		for(int i=0;i<1;i++){
			var B = (int[]) B0.Clone();
			long[] dp = new long[2];
			dp[0] = 1;
			for(int j=0;j<i;j++){
				var nxt = new long[2];
				nxt[0] += dp[0]; //(0, 0)
				nxt[0] += dp[0]; //(1, 0)
				nxt[1] += dp[0]; //(1, 1);
				nxt[0] += dp[1]; //(0, 0)
				nxt[1] += dp[1]; //(1, 0)
				nxt[1] += dp[1]; //(1, 1);
				
				nxt[0] %= mod;
				nxt[1] %= mod;
				dp = nxt;
				
			}
//Console.WriteLine(String.Join(" ", dp));
			for(int j=i;j<L;j++){
				var nxt = new long[2];
				if(B[j] == 0){
					nxt[0] += dp[0]; // (0, 0);
					nxt[1] += dp[0]; // (1, 1);
					nxt[1] += dp[1]; // (1, 0);
				} else {
					nxt[0] += dp[0]; // (1, 0);
					nxt[1] += dp[1]; // (1, 1);
					nxt[0] += dp[1]; // (0, 0);
				}
				
				nxt[0] %= mod;
				nxt[1] %= mod;
				dp = nxt;
//Console.WriteLine(String.Join(" ", dp));
				
			}
			ans += dp[0];
			ans %= mod;
		}
		
		Console.WriteLine(ans);
		
	}
	long N;
	public Sol(){
		N = rl();
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