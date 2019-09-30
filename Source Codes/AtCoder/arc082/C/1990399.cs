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
	const long mod = 998244353;
	public void Solve(){
		
		long tot = ModPow(2, N);
		tot += mod - N - 1; if(tot >= mod) tot -= mod;
		tot += mod - ((long) N * (long) (N - 1) / 2 ) % mod; if(tot >= mod) tot -= mod;
		HashSet<long> H = new HashSet<long>();
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				
				List<int> L = new List<int>();
				L.Add(i);
				L.Add(j);
				long vx = X[j] - X[i];
				long vy = Y[j] - Y[i];
				for(int k=0;k<N;k++){
					if(k == i || k == j) continue;
					long wx = X[k] - X[i];
					long wy = Y[k] - Y[i];
					if(vx * wy - vy * wx == 0){
						L.Add(k);
					}
				}
				if(L.Count == 2) continue;
				L.Sort();
				var hash = L[0] * 1L + L[1] * 1000L + L[2] * 1000000L;
				if(H.Contains(hash)) continue;
				
				H.Add(hash);
				int NN = L.Count;
				long three = ModPow(2, NN);
				three += mod - NN - 1; if(three >= mod) three -= mod;
				three += mod - ((long) NN * (long) (NN - 1) / 2 ) % mod; if(three >= mod) three -= mod;
				
				tot += mod - three; if(tot >= mod) tot -= mod;
				
			}
		}
		
		Console.WriteLine(tot);
		
		
		
		
	}
	
	long ModPow(long x, long k){
		if(k == 0) return 1;
		if(x == 0) return 0;
		long ret = 1;
		long v = x;
		while(k > 0){
			if((k & 1) == 1){
				ret *= v;
				if(ret >= mod) ret %= mod;
			}
			v *= v;
			if(v >= mod) v %= mod;
			k >>= 1;
		}
		return ret;
	}
	
	
	int N;
	long[] X,Y;
	public Sol(){
		N = ri();
		X = new long[N];
		Y = new long[N];
		for(int i=0;i<N;i++){
			var d = rla();
			X[i] = d[0]; Y[i] = d[1];
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