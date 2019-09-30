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
		
		if(N == 2){
			Console.WriteLine("{0} {1}",1, 2);
			return;
		}
			
		E = new HashSet<int>[N];
		for(int i=0;i<N;i++) E[i] = new HashSet<int>();
		for(int i=0;i<N-1;i++){
			E[A[i]].Add(B[i]);
			E[B[i]].Add(A[i]);
		}
		
		
		int[] farthest = new int[2];
		int[] depth = null;
		int[] parent = null;
		for(int t=0;t<2;t++){
			var rt = farthest[0];
			depth = new int[N];
			parent = new int[N];
			depth[rt] = 0;
			parent[rt] = -1;
			int maxdep = 0;
			int deepest = rt;
			var q = new Queue<int>();
			q.Enqueue(rt);
			while(q.Count > 0){
				var now = q.Dequeue();
				foreach(var nxt in E[now]){
					if(nxt != parent[now]){
						depth[nxt] = depth[now] + 1;
						parent[nxt] = now;
						if(depth[nxt] > maxdep){
							maxdep = depth[nxt];
							deepest = nxt;
						}
						q.Enqueue(nxt);
					}
				}
			}
			farthest[t] = deepest;
		}
		
		int diam = depth[farthest[1]];
		List<int> tops = new List<int>();
		for(int now = farthest[1]; now != farthest[0]; now = parent[now]){
			if(diam % 2 == 0){
				if(depth[now] == diam / 2) tops.Add(now);
			} else {
				if(depth[now] == diam / 2 || depth[now] == diam / 2 + 1) tops.Add(now);
			}
		}
		
		List<List<int>> candis = new List<List<int>>();
		candis.Add(tops);
		if(tops.Count == 1){
			foreach(var nxt in E[tops[0]]){
				candis.Add(new List<int>(){ tops[0], nxt});
			}
		}
		
		long min = long.MaxValue;
		foreach(var ctops in candis){
			
			long[] dp = new long[diam / 2 + 1];
			depth = new int[N];
			parent = new int[N];
			var qq = new Queue<int>();
			foreach(var n in ctops){ 
				depth[n] = 0;
				parent[n] = -1;
				qq.Enqueue(n);
			}
			if(ctops.Count == 2){
				E[ctops[0]].Remove(ctops[1]);
				E[ctops[1]].Remove(ctops[0]);
			}
			while(qq.Count > 0){
				var now = qq.Dequeue();
				int nchild = E[now].Count;
				if(parent[now] != -1) nchild--;
				dp[depth[now]] = Math.Max(dp[depth[now]], nchild);
				foreach(var nxt in E[now]){
					if(nxt != parent[now]){
						depth[nxt] = depth[now] + 1;
						parent[nxt] = now;
						qq.Enqueue(nxt);
					}
				}
			}
			
			
			long ans = (long) ctops.Count;
			for(int i=0;i<dp.Length - 1;i++) ans *= dp[i];
			min = Math.Min(min, ans);
			
			if(ctops.Count == 2){
				E[ctops[0]].Add(ctops[1]);
				E[ctops[1]].Add(ctops[0]);
			}
		}
		Console.WriteLine("{0} {1}", diam / 2 + 1, min);
		
	}
	
	HashSet<int>[] E;
	
	
	
	int N;
	int[] A,B;
	public Sol(){
		N = ri();
		A = new int[N-1]; B = new int[N-1];
		for(int i=0;i<N-1;i++){
			var d = ria();
			A[i] = d[0] - 1; B[i] = d[1] - 1;
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