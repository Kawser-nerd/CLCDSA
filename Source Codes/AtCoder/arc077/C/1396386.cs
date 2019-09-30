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
		
		long ini = 0;
		for(int i=0;i<N-1;i++){
			var x = A[i] < A[i+1] ? A[i+1] - A[i] : M - (A[i]-A[i+1]);
			var y = 1 + (0 <= A[i+1] ? A[i+1] - 0 : M - (0 - A[i+1]));
//Console.WriteLine("{0} {1}",x,y);
			ini += Math.Min(y,x);
		}
		
		var imos = new int[M+2];
		for(int i=0;i<N-1;i++){
			int ma = A[i] <= A[i+1] ? A[i+1] - A[i] : M - (A[i]-A[i+1]);
			
			imos[A[i+1]] -= (-1);
			if(A[i+1] - (ma - 1) >= 0){
				imos[A[i+1]-(ma - 1)] += -1;
			} else {
				imos[0] += -1;
				
				imos[M] -= -1;
				imos[M - (ma-1 - A[i+1])] += -1;
			}
			
			imos[A[i+1]] += (ma - 1);
			imos[A[i+1]+1] -= (ma - 1);
		}
		
		long[] sum = new long[M+2];
		for(int i=0;i<M;i++){
			sum[i] += imos[i];
			if(i>0) sum[i] += sum[i-1];
		}
		
		long ans = ini;
		long cur = ini;
		for(int i=0;i<M-1;i++){
			cur += sum[i];
			ans = Math.Min(ans,cur);
		}
		Console.WriteLine(ans);
		
	}
	int N,M;
	int[] A;
	public Sol(){
		var d = ria();
		N = d[0]; M = d[1];
		A = ria();
		for(int i=0;i<N;i++) A[i]--;
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