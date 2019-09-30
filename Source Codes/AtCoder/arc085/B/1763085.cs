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
		
		N += 2;
		bo = new bool[2,N];
		memo = new long[2,N];
		
		AA = new long[N];
		AA[0] = Z; AA[1] = W;
		for(int i=0;i<N-2;i++) AA[i+2] = A[i];
		
		Console.WriteLine(dfs(0,1));
		
		
	}
	
	long dfs(int t, int l){
		if(bo[t, l]) return memo[t, l];
		
		if(t == 0){
			long max = Math.Abs(AA[N-1] - AA[l]);
			for(int i=l+1;i<N-1;i++){
				max = Math.Max(max, dfs(1,i));
			}
			bo[t, l] = true;
			return memo[t,l] = max;
		}
		if(t == 1){
			long min = Math.Abs(AA[N-1] - AA[l]);
			for(int i=l+1;i<N-1;i++){
				min = Math.Min(min, dfs(0,i));
			}
			bo[t, l] = true;
			return memo[t,l] = min;
		}
		return 0;
		
		
		
	}
	
	long[,] memo;
	long[] AA;
	bool[,] bo;
	
	int N;
	long Z,W;
	long[] A;
	public Sol(){
		var d = ria();
		N = d[0]; Z = d[1]; W = d[2];
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