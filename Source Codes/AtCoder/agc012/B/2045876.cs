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
		
		int Dmax = D.Max();
		int[][] Mp = new int[Dmax + 1][];
		for(int i=0;i<=Dmax;i++){
			Mp[i] = new int[N];
		}
		
		for(int i=0;i<Q;i++){
			Mp[D[i]][V[i]] = Math.Max(Mp[D[i]][V[i]],i + 1);
		}
		
		int[] newest = new int[N];
		for(int i=0;i<N;i++){
			for(int j=0;j<=Dmax;j++) newest[i] = Math.Max(newest[i],Mp[j][i]);
		}
		
		for(int t=1;t<=Dmax;t++){
			for(int tt=t;tt<=Dmax;tt++){
				int[] nxt = new int[N];
				for(int i=0;i<M;i++){
					int a = A[i];
					int b = B[i];
					nxt[a] = Math.Max(nxt[a],Mp[tt][b]);
					nxt[b] = Math.Max(nxt[b],Mp[tt][a]);
				}
				Mp[tt] = nxt;
			}
			for(int i=0;i<N;i++){
				for(int j=0;j<=Dmax;j++) newest[i] = Math.Max(newest[i],Mp[j][i]);
			}
		}
		
		int[] ans = new int[N];
		for(int i=0;i<N;i++){
			ans[i] = newest[i] == 0 ? 0 : C[newest[i] - 1];
		}
		
		Console.WriteLine(String.Join("\n",ans));
		
		
	}
	int N,M,Q;
	int[] A,B;
	int[] V,D,C;
	public Sol(){
		var d = ria();
		N = d[0]; M = d[1];
		A = new int[M];
		B = new int[M];
		for(int i=0;i<M;i++){
			d = ria();
			A[i] = d[0] - 1;
			B[i] = d[1] - 1;
		}
		Q = ri();
		V = new int[Q];
		D = new int[Q];
		C = new int[Q];
		for(int i=0;i<Q;i++){
			d = ria();
			V[i] = d[0] - 1;
			D[i] = d[1];
			C[i] = d[2];
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