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
		
		long W0 = W.Min();
		List<long>[] L = new List<long>[4];
		for(int i=0;i<4;i++) L[i] = new List<long>();
		for(int i=0;i<N;i++){
			L[W[i] - W0].Add(V[i]);
		}
		
		for(int i=0;i<4;i++){
			L[i].Sort();
			L[i].Reverse();
		}
		
		
		long[][] Ls = new long[4][];
		for(int i=0;i<4;i++){
			Ls[i] = new long[N+1];
			for(int j=0;j<L[i].Count;j++){
				Ls[i][j+1] = L[i][j] + Ls[i][j];
			}
		}
		
		long max = 0;
		for(int i=0;i<=L[0].Count;i++){
			for(int j=0;j<=L[1].Count;j++){
				if( i+j > N || (W0 * i + (W0+1) * j) > Wl) break;
				for(int k=0;k<=L[2].Count;k++){
					if( i+j+k > N || (W0 * i + (W0+1) * j + (W0+2) * k) > Wl) break;
					int rest = (int) Math.Min(N - i - j - k, ((Wl - (W0 * i + (W0+1) * j + (W0+2) * k)) / (W0+3) ));
					long val = Ls[0][i] + Ls[1][j] + Ls[2][k] + Ls[3][rest];
					max = Math.Max(max,val);
				}
			}
		}
		
		Console.WriteLine(max);
		
		
		
		
		
		
		
	}
	int N;
	long Wl;
	long[] W,V;
	public Sol(){
		var d = ria();
		N = d[0]; Wl = d[1];
		W = new long[N];
		V = new long[N];
		for(int i=0;i<N;i++){
			d = ria();
			W[i] = d[0];
			V[i] = d[1];
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