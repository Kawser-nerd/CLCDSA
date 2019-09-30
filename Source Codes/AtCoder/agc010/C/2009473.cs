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
		
		
		int[] depth = new int[N];
		int[] parent = new int[N];
		var Q = new Queue<int>();
		Q.Enqueue(0);
		parent[0] = -1;
		while(Q.Count > 0){
			var now = Q.Dequeue();
			foreach(var nxt in E[now]){
				if(nxt == parent[now]) continue;
				parent[nxt] = now;
				depth[nxt] = depth[now] + 1;
				Q.Enqueue(nxt);
			}
		}
		
		Pair[] P = new Pair[N];
		for(int i=0;i<N;i++) P[i] = new Pair(i, depth[i]);
		Array.Sort(P, (p,q) => p.Depth.CompareTo(q.Depth));
		Array.Reverse(P);
		
		long[] up = new long[N];
		
		
		foreach(var p in P){
			var now = p.Idx;
			if(now == 0) break;
			if(E[now].Count == 1){
				up[now] = A[now];
				continue;
			}
			
			long sum = 0;
			long max = -1;
			foreach(var nxt in E[now]){
				if(nxt != parent[now]){
					sum += up[nxt];
					max = Math.Max(up[nxt], max);
				}
			}
			
			if(E[now].Count == 2){
				
				if(sum != A[now]){
					Console.WriteLine("NO");
					return;
				}
				
				up[now] = sum;
				continue;
			}
			
			long v = sum - A[now];
			if(v < 0){
				Console.WriteLine("NO");
				return;
			}
			
			up[now] = A[now] - v;
			if(up[now] < 0){
				Console.WriteLine("NO");
				return;
			}
			
			sum += up[now];
			max = Math.Max(max, up[now]);
			if(2 * max > sum){
				Console.WriteLine("NO");
				return;
			}
			
		}
		
		if(E[0].Count == 1){
			Console.WriteLine(up[E[0][0]] == A[0] ? "YES" : "NO");
		} else {
			long tot = 0;
			foreach(var nxt in E[0]) tot += up[nxt];
			Console.WriteLine( A[0] * 2 == tot ? "YES" : "NO");
		}
		
		
	}
	
	class Pair{
		public int Idx,Depth;
		public Pair(int idx, int depth){
			Idx = idx; Depth = depth;
		}
	}
	
	int N;
	long[] A;
	List<int>[] E;
	public Sol(){
		N = ri();
		A = rla();
		E = new List<int>[N];
		for(int i=0;i<N;i++) E[i] = new List<int>();
		for(int i=0;i<N-1;i++){
			var d = ria();
			E[d[0] - 1].Add(d[1] - 1);
			E[d[1] - 1].Add(d[0] - 1);
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