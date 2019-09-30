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
		
		for(int i=0;i<N;i++) Array.Sort(Q[i]);
		
		/*
		if(N == 1){
			int cnt = 0;
			for(int j=0;j<P;j++){
				int r = 10 * Q[0][j] / (9 * R[0]);
				int l = 10 * Q[0][j] / (11 * R[0]); if(10 * Q[0][j] % (11 * R[0]) != 0) l++;
				if(l <= r) cnt++;
			}
			Console.WriteLine(cnt);
			return;
		}
		*/
		int[][] ll = new int[N][];
		int[][] rr = new int[N][];
		for(int i=0;i<N;i++){
			ll[i] = new int[P];
			rr[i] = new int[P];
			for(int j=0;j<P;j++){
				int r = 10 * Q[i][j] / (9 * R[i]);
				int l = 10 * Q[i][j] / (11 * R[i]); if(10 * Q[i][j] % (11 * R[i]) != 0) l++;
				ll[i][j] = l;
				rr[i][j] = r;
			}
		}
		
		int NP = P*N;
		int NV = NP*2 + 2;
		int src = NP*2;
		int dst = NP*2+1;
		int Inf = (int)1e6;
		var MF = new MaxFlow_Dinic();
		MF.Init(NV);
		
		for(int i=0;i<N;i++){
			for(int j=0;j<P;j++){
				if(ll[i][j] <= rr[i][j]) MF.AddEdge(i*P+j,i*P+j+NP,1);
			}
		}
		
		for(int j=0;j<P;j++){
			MF.AddEdge(src,j,Inf);
		}
		for(int j=0;j<P;j++){
			MF.AddEdge((N-1)*P+j+NP,dst,Inf);
		}
		for(int i=0;i<N-1;i++){
			for(int j=0;j<P;j++){
				for(int k=0;k<P;k++){
					if(Intersects(ll[i][j],rr[i][j],ll[i+1][k],rr[i+1][k])){
						MF.AddEdge(i*P+j+NP,(i+1)*P+k,Inf);
					}
				}
			}
		}
		var res = MF.MaxFlow(src,dst);
		Console.WriteLine(res);
	}
	
	bool Intersects(int l0,int r0,int l1,int r1){
		if(l0 > r0) return false;
		if(l1 > r1) return false;
		if(l0 <= l1 && l1 <= r0) return true;
		if(l0 <= r1 && r1 <= r0) return true;
		if(l1 <= l0 && l0 <= r1) return true;
		if(l1 <= r0 && r0 <= r1) return true;
		return false;
	}
	
	
	int N,P;
	int[] R;
	int[][] Q;
	public Sol(int T){
		Console.Write("Case #{0}: ",T);
		var d = ria();
		N = d[0]; P = d[1];
		R = ria();
		Q = new int[N][];
		for(int i=0;i<N;i++) Q[i] = ria();
	}

	static public bool NextPermutaion<T>(T[] A)where T:IComparable<T>{
		for(int i=A.Length-2;i>=0;i--){
			if(A[i].CompareTo(A[i+1])<0){
				int trgt=Array.FindLastIndex(A,x=>A[i].CompareTo(x)<0);
				Swap(ref A[i],ref A[trgt]);
				Array.Reverse(A,i+1,A.Length-(i+1));
				return true;
			}
		}
		Array.Reverse(A);
		return false;
	}
	static void Swap<T>(ref T x, ref T y){
		T t=x;x=y;y=t;
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
