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
		
		bool[] P = new bool[N+1];
		for(int i=2;i<=N;i++) P[i] = true;
		for(int i=2;i<=N;i++){
			if(!P[i]) continue;
			for(int j=i+i;j<=N;j+=i) P[j] = false;
		}
		
		long mod = (long) 1e9 + 7;
		
		long ans = 1;
		for(int i=0;i<=N;i++){
			if(!P[i]) continue;
			long p = i;
			long b = 0;
			while(N / p > 0){
				b += (N / p);
				p *= i;
			}
			ans *= (1 + b);
			ans %= mod;
		}
		
		Console.WriteLine(ans);
		
		
		
	}
	int N;
	public Sol(){
		N = ri();
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