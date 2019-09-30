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
		
		
		List<long> L = new List<long>();
		if(N == S){
			L.Add(N+1);
		}
		
		for(long b=2;b*b<=N;b++){
			if(digSum(N,b) == S) {
				L.Add(b);
			}
		}
		
		
		
		for(long x=1;x*x<=N;x++){
			// N = xb + y;
			// S = x + y
			long y = S - x;
			if( (N - y)%x == 0){
				long b = (N-y)/x;
				if(b*x + y == N && x<b && y<b && x>=0 && y>= 0)L.Add(b);
			}
		}
		if(L.Count == 0){
			Console.WriteLine(-1);
			return;
		}
		Console.WriteLine(L.Min());
		
		
	}
	
	static long digSum(long n,long b){
		long ret = 0;
		while(n>0){
			ret += n%b;
			n /= b;
		}
		return ret;
	}
	
	long N,S;
	public Sol(){
		N = rl();
		S = rl();
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