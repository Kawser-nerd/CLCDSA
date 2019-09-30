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
		int NN = 2 * N + 2;
		int src = 2 * N;
		int sinc = src + 1;
		mf.Init(NN);
		for(int i=0;i<N;i++){
			mf.AddEdge(src, i, (int) 1);
		}
		for(int i=0;i<N;i++){
			mf.AddEdge(i + N, sinc, (int) 1);
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(A[i] < C[j] && B[i] < D[j]) mf.AddEdge(i, j + N, 1);
			}
		}
		
		Console.WriteLine(mf.MaxFlow(src, sinc));
	}
	int N;
	int[] A,B,C,D;
	public Sol(){
		N = ri();
		A = new int[N]; B = new int[N];
		C = new int[N]; D = new int[N];
		for(int i=0;i<N;i++){
			var d = ria();
			A[i] = d[0]; B[i] = d[1];
		}
		for(int i=0;i<N;i++){
			var d = ria();
			C[i] = d[0]; D[i] = d[1];
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


class MaxFlow_Dinic{
	// arihon is god
	class Edge {
		public int To,Cap,Rev;
		public Edge(int to = 0,int cap = 0,int rev = 0){
			To = to;
			Cap = cap;
			Rev = rev;
		}
	}
	
	List<Edge>[] G;
	int[] Level;
	int[] Iter;
	
	static int Inf = (int) 1e9;
	public int N;
	public void Init(int n){
		N = n;
		G = new List<Edge>[N];
		for(int i=0;i<N;i++) G[i] = new List<Edge>();
		Level = new int[N];
		Iter = new int[N];
	}
	
	
	public void AddEdge(int from, int to, int cap){
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
	
	int dfs(int v, int t, int f){
		if(v == t) return f;
		for(;Iter[v] < G[v].Count; Iter[v]++){
			var e = G[v][Iter[v]];
			if(e.Cap > 0 && Level[v] < Level[e.To]){
				int d = dfs(e.To, t, Math.Min(f,e.Cap));
				if(d > 0){
					e.Cap -= d;
					G[e.To][e.Rev].Cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	
	public int MaxFlow(int s,int t){
		int flow = 0;
		while(true){
			bfs(s);
			if(Level[t] < 0) return flow;
			Iter = new int[N];
			
			int f;
			while( ( f = dfs(s,t,Inf)) > 0){
				flow += f;
			}
		}
	}
	
}