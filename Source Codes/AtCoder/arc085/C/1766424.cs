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
		var mf = new MaxFlow_Dinic();
		
		int NN = N + 2;
		int S = 0, T = N + 1;
		
		mf.Init(NN);
		long tot = 0;
		long Inf = (long) 1e18;
		
		for(int i=1;i<=N;i++){
			if(A[i-1] <= 0){
				mf.AddEdge(S, i, -A[i-1]);
			}
			if(A[i-1] > 0){
				mf.AddEdge(i, T, A[i-1]);
				tot += A[i-1];
			}
			for(int j=i+i;j<=N;j+=i){
				mf.AddEdge(i, j, Inf);
			}
		}
		var f = mf.MaxFlow(S,T);
		Console.WriteLine(tot - f);
	}
	
	
	
	
	
	int N;
	long[] A;
	public Sol(){
		N = ri();
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


class MaxFlow_Dinic{
	// arihon is god
	class Edge {
		public int To,Rev;
		public long Cap;
		public Edge(int to = 0,long cap = 0,int rev = 0){
			To = to;
			Cap = cap;
			Rev = rev;
		}
	}
	
	List<Edge>[] G;
	long[] Level;
	int[] Iter;
	
	static long Inf = (long) 1e18;
	public int N;
	public void Init(int n){
		N = n;
		G = new List<Edge>[N];
		for(int i=0;i<N;i++) G[i] = new List<Edge>();
		Level = new long[N];
		Iter = new int[N];
	}
	
	
	public void AddEdge(int from, int to, long cap){
		G[from].Add(new Edge(to,cap,G[to].Count));
		G[to].Add(new Edge(from,0,G[from].Count-1));
	}
	
	void bfs(int s){
		for(int j=0;j<G.Length;j++)Level[j] = -1;
		var Q = new Queue<int>();
		Level[s] = 0;
		Q.Enqueue(s);
		
		while(Q.Count>0){
			var v = Q.Dequeue();
			foreach(var e in G[v]){
				if(e.Cap > 0 && Level[e.To] < 0){
					Level[e.To] = Level[v] + 1;
					Q.Enqueue(e.To);
				}
			}
		}
	}
	
	long dfs(int v, int t, long f){
		if(v == t) return f;
		for(;Iter[v] < G[v].Count; Iter[v]++){
			var e = G[v][Iter[v]];
			if(e.Cap > 0 && Level[v] < Level[e.To]){
				long d = dfs(e.To, t, Math.Min(f,e.Cap));
				if(d > 0){
					e.Cap -= d;
					G[e.To][e.Rev].Cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	
	public long MaxFlow(int s,int t){
		long flow = 0;
		while(true){
			bfs(s);
			if(Level[t] < 0) return flow;
			Iter = new int[N];
			
			long f;
			while( ( f = dfs(s,t,Inf)) > 0){
				flow += f;
			}
		}
	}
	
}