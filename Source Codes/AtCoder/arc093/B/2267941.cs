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
		
		int N = 100;
		int[][] m = new int[N][];
		for(int i=0;i<N;i++) m[i] = new int[N];
		
		int N2 = N / 2;
		
		for(int i=0;i<N;i++) for(int j=0;j<N2;j++) m[i][j] = 1;
		
		for(int i=1;i<N;i+=2) for(int j=1;j<N2-1;j+=2) if(A > 1) { m[i][j] = 0; A--; }
		for(int i=1;i<N;i+=2) for(int j=N2+1;j<N-1;j+=2) if(B > 1) { m[i][j] = 1; B--; }
		
		Console.WriteLine("{0} {1}", N, N);
		Console.WriteLine(String.Join("\n",m.Select(ar => String.Join("", ar.Select(n => n == 0 ? "." : "#")))));
		
		
	}
	int A, B;
	public Sol(){
		var d = ria();
		A = d[0]; B = d[1];
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