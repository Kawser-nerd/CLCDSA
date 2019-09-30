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
		
		int[] ans = new int[N];
		for(int i=0;i<N;i++) ans[i] = A[i];
		
		ans[0] = 0;
		
		HashSet<int>[] XE = new HashSet<int>[N];
		for(int i=0;i<N;i++){
			XE[i] = new HashSet<int>();
		}
		
		for(int i=1;i<N;i++){
			XE[A[i]].Add(i);
		}
		
		int[] depth = new int[N];
		int[] parent = new int[N];
		for(int i=1;i<N;i++){
			parent[i] = A[i];
		}
		
		var Q = new Queue<int>();
		depth[0] = 0;
		Q.Enqueue(0);
		while(Q.Count > 0){
			var now = Q.Dequeue();
			foreach(var nxt in XE[now]){
				depth[nxt] = depth[now] + 1;
				Q.Enqueue(nxt);
			}
		}
		
		Pair[] P = new Pair[N];
		for(int i=0;i<N;i++) P[i] = new Pair(i, depth[i]);
		Array.Sort(P, (p, q) => p.Depth.CompareTo(q.Depth));
		Array.Reverse(P);
		
		
		int[] dp = new int[N];
		foreach(var p in P){
			int now = p.Idx;
			int m = 0;
			foreach(var nxt in XE[now]){
				m = Math.Max(m, dp[nxt] + 1);
			}
			dp[now] = m;
			if(m == K - 1){
				XE[parent[now]].Remove(now);
				ans[now] = 0;
			}
		}
		
//Console.WriteLine(String.Join(" ",A));
//Console.WriteLine(String.Join(" ",ans));
//Console.WriteLine(String.Join(" ",dp));
		
		int cnt = 0;
		for(int i=0;i<N;i++) if(ans[i] != A[i]) cnt++;
		Console.WriteLine(cnt);
		
	}
	
	class Pair{
		public int Idx, Depth;
		public Pair(int idx, int depth){
			Idx = idx; Depth = depth;
		}
	}
	
	int N, K;
	int[] A;
	public Sol(){
		var d = ria();
		N = d[0]; K = d[1];
		A = ria();
		for(int i=0;i<N;i++) A[i]--;
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