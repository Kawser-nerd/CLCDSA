using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;


class TEST{
	static void Main(){
		Sol mySol =new Sol();
		mySol.Solve();
	}
}

class Sol{
	public void Solve(){
		
		int ans = N;
		
		switch(K%2){
			
			case 0:
			// there exists the center vertex when diam%2 == 0
			
			for(int i=0;i<N;i++){
				
				int[] depth = new int[N];
				int[] parent = new int[N];
				int root = i;
				depth[root] = 0;
				parent[root] = -1;
				
				var Q = new Queue<int>();
				Q.Enqueue(root);
				while(Q.Count>0){
					var now = Q.Dequeue();
					foreach(var nxt in E[now]){
						if(nxt != parent[now]){
							parent[nxt] = now;
							depth[nxt] = depth[now] + 1;
							Q.Enqueue(nxt);
						}
					}
				}
				int mustRemove = depth.Count(e => e > K/2);
				ans = Math.Min(ans,mustRemove);
			}
			break;
			
			
			
			case 1:
			// there exists the center edge when diam%2 == 1
			
			for(int i=0;i<N;i++){
				
				int[] depth = new int[N];
				int[] parent = new int[N];
				int root = i;
				foreach(var adj in E[root]){
					if(adj < root)continue;
					
					depth[root] = 0;
					parent[root] = adj;
					depth[adj] = 0;
					parent[adj] = root;
					
					var Q = new Queue<int>();
					Q.Enqueue(root);
					Q.Enqueue(adj);
					
					while(Q.Count>0){
						var now = Q.Dequeue();
						foreach(var nxt in E[now]){
							if(nxt != parent[now]){
								parent[nxt] = now;
								depth[nxt] = depth[now] + 1;
								Q.Enqueue(nxt);
							}
						}
					}
//Console.WriteLine(String.Join(" ",depth));					
					int mustRemove = depth.Count(e => e > K/2);
					ans = Math.Min(ans,mustRemove);
				}
			}
			break;
			
		}
		
		Console.WriteLine(ans);
	}
	
	int N,K;
	List<int>[] E;
	public Sol(){
		var d = ria();
		N = d[0];
		K = d[1];
		E = new List<int>[N];
		for(int i=0;i<N;i++){
			E[i] = new List<int>();
		}
		for(int i=0;i<N-1;i++){
			d = ria();
			E[d[0]-1].Add(d[1]-1);
			E[d[1]-1].Add(d[0]-1);
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