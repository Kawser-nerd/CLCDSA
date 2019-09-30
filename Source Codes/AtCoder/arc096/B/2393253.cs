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
		long Inf = (long) 1e18;
		
		long[] clk = new long[N + 1];
		long[] clkm = new long[N + 1];
		for(int i=0;i<=N;i++) clkm[i] = -Inf;
		
		clkm[0] = 0;
		for(int i=0;i<N;i++){
			clk[i + 1] = clk[i] - (X[i] - (i > 0 ? X[i - 1] : 0)) + V[i];
			clkm[i + 1] = Math.Max(clkm[i], clk[i + 1]);
		}
		
		long[] iclk = new long[N + 1];
		long[] iclkm = new long[N + 1];
		for(int i=0;i<=N;i++) iclkm[i] = -Inf;
		
		iclkm[0] = 0;
		for(int i=0;i<N;i++){
			iclk[i + 1] = iclk[i] - ((C - X[N - 1 - i]) - (i > 0 ? (C - X[N - 1 - (i - 1)]) : 0)) + V[N - 1 - i];
			iclkm[i + 1] = Math.Max(iclkm[i], iclk[i + 1]);
		}
		
//Console.WriteLine("clk:{0}",String.Join(" ",clk));		
//Console.WriteLine("clkm:{0}",String.Join(" ",clkm));		
//Console.WriteLine("iclk:{0}",String.Join(" ",iclk));		
//Console.WriteLine("iclkm:{0}",String.Join(" ",iclkm));		
		
		long max = iclkm[N];
		for(int i=0;i<N;i++){
			long c = clk[i+1];
			c -= X[i];
			c += iclkm[N - (i + 1)];
//Console.WriteLine("clk - iclk : i:{0}, c;{1}",i, c);			
			max = Math.Max(max, c);
		}
		
		max = Math.Max(max, clkm[N]);
		for(int i=0;i<N;i++){
			long c = iclk[i+1];
			c -= C - X[N - 1 - i];
			c += clkm[N - (i + 1)];
//Console.WriteLine("iclk - clk : i:{0}, c;{1}",i, c);			
			max = Math.Max(max, c);
		}
		
		Console.WriteLine(max);
		
	}
	int N;
	long C;
	long[] X,V;
	public Sol(){
		var d = rla();
		N = (int) d[0]; C = d[1];
		X = new long[N];
		V = new long[N];
		for(int i=0;i<N;i++){
			d = rla();
			X[i] = d[0]; V[i] = d[1];
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