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
		
		E = new List<int>[N];
		for(int i=0;i<N;i++){
			E[i] = new List<int>();
		}
		
		for(int i=0;i<N-1;i++){
			E[A[i]].Add(B[i]);
			E[B[i]].Add(A[i]);
		}
		
		int tot = dfs(X, -1);
		Console.WriteLine(tot);
		
	}
	
	int dfs(int now, int pre){
		int tot = 0;
		foreach(var nxt in E[now]){
			if(nxt == pre) continue;
			tot += dfs(nxt, now);
		}
		//Console.WriteLine("now:{0} tot:{1}",now,tot);
		if(tot == 0){
			if(now == X) return 0;
			else return 2 * H[now];
		}
		
		if(now != X) tot += 2;
		return tot;
		
	}
	
	
	
	List<int>[] E;
	
	
	int N,X;
	int[] H;
	int[] A,B;
	public Sol(){
		var d = ria();
		N = d[0]; X = d[1] - 1;
		H = ria();
		A = new int[N-1];
		B = new int[N-1];
		for(int i=0;i<N-1;i++){
			d = ria();
			A[i] = d[0] - 1;
			B[i] = d[1] - 1;
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