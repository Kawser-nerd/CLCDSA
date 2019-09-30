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
		
		int[][] sum = new int[2][];
		for(int i=0;i<2;i++) sum[i] = new int[N+1];
		for(int i=0;i<N;i++){
			sum[0][i+1] = sum[0][i] + A[0][i];
			sum[1][i+1] = sum[1][i] + A[1][i];
		}
		
		
		int max = 0;
		for(int i=1;i<=N;i++){
			int tot = sum[0][i] + (sum[1][N] - sum[1][i-1]);
			max = Math.Max(max,tot);
		}
		
		Console.WriteLine(max);

		
	}
	int N;
	int[][] A;
	public Sol(){
		N = ri();
		A = new int[2][];
		for(int i=0;i<2;i++) A[i] = ria();
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