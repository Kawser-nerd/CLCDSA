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
		
		int[] A = new int[N];
		int[] B = new int[N];
		int[] C = new int[N];
		int x = 1;
		for(int i=0;i<N;i++){
			C[P[i]-1] = x;
			x++;
		}
		
		
		A[0] = C[0];
		B[0] = 0;
		
		for(int i=1;i<N;i++){
			A[i] = A[i-1] + C[i];
			B[i] = -A[i-1];
		}
		
		int Bm = - (B.Min());
		for(int i=0;i<N;i++)B[i] += Bm+1;
		Console.WriteLine(String.Join(" ",A));
		Console.WriteLine(String.Join(" ",B));
	}
	int N;
	int[] P;
	public Sol(){
		N = ri();
		P = ria();
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