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
		
		if(N == 1){
			Console.WriteLine(A[0] == 0 ? 0 : -1);
			return;
		}
		
		if(A[0] != 0){
			Console.WriteLine(-1);
			return;
		}
		
		long tot = 0;
		
		int r = 0;
		while(r < N){
			while(r <N - 1 && A[r+1] == A[r] + 1) r++;
//Console.WriteLine("r:{0}",r);
			tot += A[r];
			if(r == N - 1){
				r++;
				continue;
			}
			if(r < N - 1 && A[r+1] <= A[r]){
				r++;
				continue;
			}
			Console.WriteLine(-1);
			return;
		}
		
		Console.WriteLine(tot);
		
		
		
		
		
		
	}
	int N;
	long[] A;
	public Sol(){
		N = ri();
		A = new long[N];
		for(int i=0;i<N;i++) A[i] = rl();
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