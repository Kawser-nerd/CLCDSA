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
		
		var E = new List<int>[N];
		for(int i=0;i<N;i++) E[i] = new List<int>();
		for(int i=0;i<N-1;i++){
			E[A[i]].Add(B[i]);
			E[B[i]].Add(A[i]);
		}
		
		int root = V[0];
		int[] depth = new int[N];
		int[] parent = new int[N];
		depth[root] = 0;
		parent[root] = -1;
		var Q = new Queue<int>();
		Q.Enqueue(root);
		while(Q.Count > 0){
			var now = Q.Dequeue();
			foreach(var nxt in E[now]){
				if(nxt == parent[now]) continue;
				parent[nxt] = now;
				depth[nxt] = depth[now] + 1;
				Q.Enqueue(nxt);
			}
		}

		for(int i=0;i<K;i++){
			if(P[0] % 2 != ((P[i] % 2) ^ (depth[V[i]] % 2))){
				Console.WriteLine("No");
				return;
			}
		}

//Console.WriteLine(String.Join(" ",depth));		
		
		int[] R = new int[N];
		int[] L = new int[N];
		int Inf = (int) 1e9;
		for(int i=0;i<N;i++) {
			R[i] = Inf;
			L[i] = -Inf;
		}
		
		for(int i=0;i<K;i++){
			R[V[i]] = L[V[i]] = P[i];
		}
		
		Q = new Queue<int>();
		Q.Enqueue(root);
		while(Q.Count > 0){
			var now = Q.Dequeue();
			if(L[now] > R[now]){
				Console.WriteLine("No");
				return;
			}
			foreach(var nxt in E[now]){
				if(nxt == parent[now]) continue;
				L[nxt] = Math.Max(L[nxt], L[now] - 1);
				R[nxt] = Math.Min(R[nxt], R[now] + 1);
				Q.Enqueue(nxt);
			}
		}
		
		Pair[] pp = new Pair[N];
		for(int i=0;i<N;i++) pp[i] = new Pair(i, depth[i]);
		Array.Sort(pp, (p, q) => -1 * (p.Depth.CompareTo(q.Depth)));
		for(int i=0;i<N;i++){
			var now = pp[i].Pos;
			if(L[now] > R[now]){
				Console.WriteLine("No");
				return;
			}
			if(now == root) continue;
			int nxt = parent[now];
			L[nxt] = Math.Max(L[nxt], L[now] - 1);
			R[nxt] = Math.Min(R[nxt], R[now] + 1);
		}
		
		int[] ans = new int[N];
		Q = new Queue<int>();
		Q.Enqueue(root);
		ans[root] = R[root];
		while(Q.Count > 0){
			var now = Q.Dequeue();
			foreach(var nxt in E[now]){
				if(nxt == parent[now]) continue;
				if(L[nxt] <= ans[now] - 1 && ans[now] - 1 <= R[nxt]){
					ans[nxt] = ans[now] - 1;
				} else if (L[nxt] <= ans[now] + 1 && ans[now] + 1 <= R[nxt]) {
					ans[nxt] = ans[now] + 1;
				} else {
					Console.WriteLine("No");
					return;
				}
				Q.Enqueue(nxt);
			}
		}
		
		
		Console.WriteLine("Yes");
		for(int i=0;i<N;i++) Console.WriteLine(ans[i]);
	}
	
	class Pair{
		public int Pos,Depth;
		public Pair(int pos, int depth){
			Pos = pos; Depth = depth;
		}
	}
	
	
	int N;
	int[] A,B;
	int K;
	int[] V,P;
	
	public Sol(){
		N = ri();
		A = new int[N - 1];
		B = new int[N - 1];
		for(int i=0;i<N-1;i++){
			var d = ria();
			A[i] = d[0] - 1; B[i] = d[1] - 1;
		}
		K = ri();
		V = new int[K];
		P = new int[K];
		for(int i=0;i<K;i++){
			var d = ria();
			V[i] = d[0] - 1; P[i] = d[1];
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