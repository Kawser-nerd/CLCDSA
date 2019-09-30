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
		
		List<int>[] E = new List<int>[N];
		for(int i=0;i<N;i++) E[i] = new List<int>();
		for(int i=1;i<N;i++){
			E[Parent[i]].Add(i);
		}
		
		int[] depth = new int[N];
		var Q = new Queue<int>();
		depth[0] = 0;
		Q.Enqueue(0);
		while(Q.Count>0){
			var now = Q.Dequeue();
			foreach(var nxt in E[now]){
				depth[nxt] = depth[now] + 1;
				Q.Enqueue(nxt);
			}
		}
		
		var L = new List<Pair>();
		for(int i=0;i<N;i++){
			L.Add(new Pair(i,depth[i]));
		}
		L.Sort((p,q) => -1 * p.Depth.CompareTo(q.Depth));
		
		int[] min = new int[N];
		int Inf = (int)1e9;
		for(int i=0;i<N;i++) min[i] = Inf;
		
		foreach(var now in L.Select(p => p.Pos)){
			if(E[now].Count == 0){
				min[now] = 0;
				continue;
			}
			
			var dp = new Dictionary<int,int>();
			dp.Add(0,0);
			foreach(var c in E[now]){
				int a = X[c];
				int b = min[c];
				var nxt = new Dictionary<int,int>();
				foreach(var k in dp.Keys){
					if(k + a <= X[now]){
						if(!nxt.ContainsKey(k + a)) nxt.Add(k + a,dp[k]+b);
						nxt[k+a] = Math.Min(nxt[k+a],dp[k]+b);
					}
					if(k + b <= X[now]){
						if(!nxt.ContainsKey(k + b)) nxt.Add(k + b,dp[k]+a);
						nxt[k+b] = Math.Min(nxt[k+b],dp[k]+a);
					}
				}
				if(nxt.Count == 0){
					Console.WriteLine("IMPOSSIBLE");
					return;
				}
				dp = nxt;
			}
			
			foreach(var k in dp.Keys){
				min[now] = Math.Min(min[now],dp[k]);
			}
		}
		
		Console.WriteLine(min[0] == Inf ? "IMPOSSIBLE" : "POSSIBLE");
		
	}
	
	class Pair{
		public int Pos,Depth;
		public Pair(int pos, int dep){
			Pos = pos; Depth = dep;
		}
	}
	
	int N;
	int[] Parent;
	int[] X;
	public Sol(){
		N = ri();
		int[] d = null;
		if(N != 1){
			d = ria();
		} else {
			rs();
		}
		Parent = new int[N];
		Parent[0] = -1;
		for(int i=1;i<N;i++) Parent[i] = d[i-1]-1;
		
		X = ria();
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