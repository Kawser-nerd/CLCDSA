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
		
		long[] B = new long[N];
		for(int i=0;i<N;i++) B[i] = Math.Max(A[i],0);
		
		long[] asum = new long[N+1];
		long[] bsum = new long[N+1];
		for(int i=0;i<N;i++){
			asum[i+1] = asum[i] + A[i];
			bsum[i+1] = bsum[i] + B[i];
		}
		
		
		long max = - (long) 1e18;
		
		for(int i=0;i+K-1<N;i++){
			long v = 0;
			// [0,i) :any;
			v += bsum[i];
			// [i,i+K) : sum or none
			v += Math.Max(asum[i+K] - asum[i], 0);
			// [i+K,N) : any
			v += bsum[N] - bsum[i+K];
			max = Math.Max(max, v);
		}
		
		Console.WriteLine(max);
		
		
		
	}
	int N, K;
	long[] A;
	public Sol(){
		var d = ria();
		N = d[0]; K = d[1];
		A = rla();
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