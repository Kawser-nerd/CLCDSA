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
		try{ checked{
		
		long[] sum = new long[N+1];
		for(int i=0;i<N;i++) sum[i + 1] = sum[i] + A[i];
		
		int NN = (int) 2e5 + 10;
		long[] coef = new long[NN];
		coef[1] = coef[2] = 5;
		for(int i=3;i<NN;i++) coef[i] = coef[i-1] + 2;
		
		long min = long.MaxValue;
		for(int i=N;i>=1;i--){
			long sc = N * X + i * X;
			
			int rest = N % i;
			int len0 = N / i;
//Console.WriteLine("i:{0},rest:{1}, len0:{2}",i, rest, len0);			
			int tot = 0;
			
			sc += coef[len0 + 1] * sum[rest];
			tot += rest;
			
			for(int j=len0;j>=1;j--){
				sc += coef[j] *(sum[tot + i] - sum[tot]);
				tot += i;
			}
			if(min >= sc){
				min = sc;
				continue;
			} else {
				break;
			}
		}
		Console.WriteLine(min);
		return;
		
		
		}} catch {
			throw new Exception("kkk");
		}
	}
	int N;
	long X;
	long[] A;
	public Sol(){
		var d = ria();
		N = d[0]; X = d[1];
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