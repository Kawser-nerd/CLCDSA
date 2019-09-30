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
		
		int T = N*A;
		long[][] dp = new long[N+1][];
		for(int i=0;i<=N;i++)dp[i] = new long[T+1];
		dp[0][0] = 1;
		foreach(var x in X){
			for(int i=N-1;i>=0;i--){
				for(int j=T;j>=0;j--){
					if(dp[i][j] == 0)continue;
					if(j+x <= T){
						dp[i+1][j+x] += dp[i][j];
					}
				}
			}
		}
		
		long sum = 0;
		for(int i=1;i<=N;i++){
			sum += dp[i][i*A];
		}
		Console.WriteLine(sum);
		
	}
	int N,A;
	int[] X;
	public Sol(){
		var d = ria();
		N = d[0]; A = d[1];
		X = ria();
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