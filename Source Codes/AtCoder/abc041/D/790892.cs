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
		
		long[] dp =new long[1<<N];
		dp[0] = 1;
		
		for(int t=0;t<(1<<N);t++){
			for(int j=0;j<N;j++){
				if((t&(1<<j)) == 0 && (t & NGs[j]) == 0) {
					dp[t|(1<<j)] += dp[t];
				}
			}
		}
		
		long sum = dp.Last();
		Console.WriteLine(sum);
		
		
		
		
	}
	int N,M;
	int[] NGs;
	public Sol(){
		
		var d = ria();
		N = d[0];
		M = d[1];
		
		NGs = new int[N];
		for(int i=0;i<N;i++){
			NGs[i] = 1<<i;
		}
		
		for(int i=0;i<M;i++){
			d = ria();
			NGs[d[1]-1] |= (1<<(d[0]-1));
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