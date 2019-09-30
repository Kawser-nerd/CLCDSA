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
		
		var MF = new MaxFlow_Dinic();
		int HW = H * W;
		int N = 2 * HW + 2;
		int source = 2 * HW;
		int sink = source + 1;
		MF.Init(N);
		
		int Inf = (int) 1e9;
		int rcs = 0, rct = 0;
		
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(S[i][j] == '.') continue;
				
				if(S[i][j] == 'o') {MF.AddEdge(i * W + j, i * W + j + HW, 1);}
				if(S[i][j] == 'S') {MF.AddEdge(i * W + j, i * W + j + HW, Inf); rcs = i * W + j;}
				if(S[i][j] == 'T') {MF.AddEdge(i * W + j, i * W + j + HW, Inf); rct = i * W + j;}
				
				for(int ii=0;ii<H;ii++){
					if(ii == i) continue;
					if(S[ii][j] != '.') MF.AddEdge(i * W + j + HW, ii * W + j, Inf);
				}
				for(int jj=0;jj<W;jj++){
					if(jj == j) continue;
					if(S[i][jj] != '.') MF.AddEdge(i * W + j + HW, i * W + jj, Inf);
				}
			}
		}
		
		if(rcs / W == rct  / W || rcs % W == rct  % W){
			Console.WriteLine(-1);
			return;
		} 
		
		MF.AddEdge(source, rcs, Inf);
		MF.AddEdge(rct + HW, sink, Inf);
		
		var ans = MF.MaxFlow(source, sink);
		Console.WriteLine(ans);
		
	}
	int H,W;
	String[] S;
	public Sol(){
		var d = ria();
		H = d[0]; W = d[1];
		S = new String[H];
		for(int i=0;i<H;i++) S[i] = rs();
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