using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class TEST{
	static void Main(){
		int T=int.Parse(Console.ReadLine());
		for(int i=1;i<=T;i++){
			Sol mySol =new Sol(i);
			mySol.Solve();
		}
	}
}

class Sol{
	public void Solve(){
		// small;
		
		long InfD = (long)1e18;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(D[i][j] == -1) D[i][j] = InfD;
			}
		}
		
		for(int k=0;k<N;k++){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					D[i][j] = Math.Min(D[i][j],D[i][k]+D[k][j]);
				}
			}
		}
			
		
		double Inf = 1e18;
		double[][] WF = new double[N][];
		for(int i=0;i<N;i++){
			WF[i] = new double[N];
			for(int j=0;j<N;j++){
				WF[i][j] = Inf;
			}
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(i == j) WF[i][j] = 0.0;
				if(E[i] >= D[i][j]){
					WF[i][j] = (double) D[i][j] / (double) S[i];
				}
			}
		}
		
		for(int k=0;k<N;k++){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					WF[i][j] = Math.Min(WF[i][j],WF[i][k]+WF[k][j]);
				}
			}
		}
		
		List<double> L = new List<double>();
		for(int i=0;i<Q;i++){
			L.Add(WF[U[i]][V[i]]);
		}
		
		Console.WriteLine(String.Join(" ",L));
		
		
	}
	int N,Q;
	int[] E,S;
	long[][] D;
	int[] U,V;
	public Sol(int T){
		Console.Write("Case #{0}: ",T);
		var d = ria();
		N = d[0]; Q = d[1];
		E = new int[N];
		S = new int[N];
		for(int i=0;i<N;i++){
			d = ria();
			E[i] = d[0]; S[i] = d[1];
		}
		D = new long[N][];
		for(int i=0;i<N;i++){
			D[i] = rla();
		}
		U = new int[Q];
		V = new int[Q];
		for(int i=0;i<Q;i++){
			d = ria();
			U[i] = d[0]-1; V[i] = d[1]-1;
		}
	}




	static String rs(){return Console.ReadLine();}
	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(){return Console.ReadLine().Split(' ');}
	static int[] ria(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>int.Parse(e));}
	static long[] rla(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>long.Parse(e));}
	static double[] rda(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>double.Parse(e));}

}

struct Pair{
	public char C;
	public int N;
	public Pair(char c,int n){
		this.N=n;
		this.C=c;
	}
}