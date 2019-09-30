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
		dp = new long[2][];
		for(int i=0;i<2;i++) dp[i] = new long[N];
		Console.WriteLine(dfs(0, -1));
	}
	
	const long mod = (long) 1e9 + 7;
	long[][] dp;
	
	long dfs(int now, int pre){
		
		long w = 1;
		long all = 1;
		foreach(var nxt in E[now]){
			if(nxt == pre) continue;
			dfs(nxt, now);
			all *= (dp[0][nxt] + dp[1][nxt]); all %= mod;
			w *= dp[0][nxt]; w %= mod;
		}
		
		dp[0][now] = all;
		dp[1][now] = w;
		
		return (all + w) % mod;
	}
	
	
	
	
	int N;
	List<int>[] E;
	public Sol(){
		N = ri();
		E = new List<int>[N];
		for(int i=0;i<N;i++){
			E[i] = new List<int>();
		}
		for(int i=0;i<N-1;i++){
			var d = ria();
			E[d[0] - 1].Add(d[1] - 1);
			E[d[1] - 1].Add(d[0] - 1);
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