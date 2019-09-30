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
		
		int M = 51;
		long Inf = 1L << 53;
		long[][] WF = new long[M][];
		for(int i=0;i<M;i++){
			WF[i] = new long[M];
			for(int j=0;j<M;j++){
				WF[i][j] = i == j ? 0 : Inf;
			}
		}
		
		for(int i=0;i<M;i++){
			for(int j=1;j<M;j++){
				WF[i][i % j] = Math.Min(WF[i][i % j] , 1L << j);
			}
		}
		
		for(int k=0;k<M;k++){
			for(int i=0;i<M;i++){
				for(int j=0;j<M;j++){
					WF[i][j] = Math.Min(WF[i][j], WF[i][k] + WF[k][j]);
				}
			}
		}
		
		for(int i=0;i<N;i++){
			if(WF[A[i]][B[i]] == Inf){
				Console.WriteLine(-1);
				return;
			}
		}
		
		List<int> ans = new List<int>();
		for(int b=50;b>=1;b--){
			WF = new long[M][];
			for(int i=0;i<M;i++){
				WF[i] = new long[M];
				for(int j=0;j<M;j++) WF[i][j] = i == j ? 0 : Inf;
			}
			
			foreach(var j in ans){
				for(int i=1;i<M;i++){
					WF[i][i % j] = Math.Min(WF[i][i % j] , 1L << j);
				}
			}
			for(int j=b-1;j>=1;j--){
				for(int i=1;i<M;i++){
					WF[i][i % j] = Math.Min(WF[i][i % j] , 1L << j);
				}
			}
			for(int k=0;k<M;k++){
				for(int i=0;i<M;i++){
					for(int j=0;j<M;j++){
						WF[i][j] = Math.Min(WF[i][j], WF[i][k] + WF[k][j]);
					}
				}
			}
			
			bool unreach = false;
			for(int i=0;i<N;i++){
				if(WF[A[i]][B[i]] == Inf){
					unreach = true;
				}
			}
			if(unreach) ans.Add(b);
		}
		
		long tot = 0;
		foreach(var n in ans) tot += 1L << n;
		Console.WriteLine(tot);
		
		
	}
	int N;
	int[] A;
	int[] B;
	public Sol(){
		N = ri();
		A = ria();
		B = ria();
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