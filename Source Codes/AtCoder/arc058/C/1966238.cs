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
		
		int T = X + Y + Z;
		long mod = (long) 1e9 + 7;
		
		long[] dp = new long[1<<T];
		dp[0] = 1;
		for(int i=0;i<N;i++){
			long[] ndp = new long[1<<T];
			for(int j=0;j<(1<<T);j++){
				if(dp[j] == 0) continue;
				for(int k=1;k<=10;k++){
					// 0|12345|1234567|12345
					int nxt = 0;
					if(k <= X) nxt |= (1 << k);
					for(int x=1;x<X;x++){
						if(((j >> x) & 1) == 0) continue;
						if(x + k <= X){
							nxt |= (1 << (x + k));
						}
					}
					if(((j >> X) & 1) == 1){
						if(k <= Y){
							nxt |= (1 << (X + k));
						}
					}
					for(int y=1;y<Y;y++){
						if(((j >> (X + y)) & 1) == 0) continue;
						if(y + k <= Y){
							nxt |= (1 << (X + y + k));
						}
					}
					if(((j >> (X + Y)) & 1) == 1){
						if(k <= Z){
							nxt |= (1 << (X + Y + k));
						}
					}
					for(int z=1;z<Z;z++){
						if(((j >> (X + Y + z)) & 1) == 0) continue;
						if(z + k <= Z){
							nxt |= (1 << (X + Y + z + k));
						}
					}
					
					if(nxt < (1<<T)){
						ndp[nxt] += dp[j];
						if(ndp[nxt] >= mod) ndp[nxt] -= mod;
					}
				}
			}
			dp = ndp;
		}
		
		long notcontain = 0;
		foreach(var n in dp){
			notcontain += n;
			if(notcontain >= mod) notcontain -= mod;
		}
		
		long tot = 1;
		for(int i=0;i<N;i++){
			tot *= 10;
			tot %= mod;
		}
		
		long ans = (tot - notcontain + mod) % mod;
		Console.WriteLine(ans);
		
		
	}
	int N, X, Y ,Z;
	public Sol(){
		var d = ria();
		N = d[0]; X = d[1]; Y = d[2]; Z = d[3];
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