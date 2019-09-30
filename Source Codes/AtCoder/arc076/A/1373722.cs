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
		
		if (M < N) { var t = M; M = N; N = t;}
		
		if(M == N){
			Console.WriteLine( (((FactorialMod(N) * FactorialMod(M) ) % mod) * 2  ) % mod);
			return; 
		}
		if(M == N + 1){
			Console.WriteLine( (((FactorialMod(N) * FactorialMod(M) ) % mod) * 1  ) % mod);
			return; 
		}
		Console.WriteLine(0);
		
	}
	long N,M;
	public Sol(){
		var d = rla();
		N = d[0]; M = d[1];
	}
	
	const long mod = (long) 1e9 + 7;
	long ModPow(long n,long k){
		
		if(k==0)return 1;
		if(n==0)return 0;
		long ret=1;
		long x=n;
		while(k>0){
			if((k&1)==1){ret*=x;ret%=mod;}
			
			x*=x;x%=mod;
			k>>=1;
		}
		return ret;
		
	}
	long[] FM = new long[200010];
	long FactorialMod(long n){
		
		if(FM[(int)n]!=0)return FM[(int)n];

		if(n<2)return FM[(int)n] = 1;
		long ret = n * FactorialMod(n-1);
		ret %= mod;
		return FM[(int)n] = ret;
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