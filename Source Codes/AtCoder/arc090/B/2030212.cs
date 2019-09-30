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
		if(M == 0){
			Console.WriteLine("Yes");
			return;
		}
		
		List<int>[] E = new List<int>[N];
		for(int i=0;i<N;i++) E[i] = new List<int>();
		
		int[] Ind = new int[N];
		for(int i=0;i<M;i++){
			E[L[i]].Add(i);
			Ind[R[i]]++;
		}
		
		long[] dist = new long[N];
		long minf = -(long) 1e18;
		var Q = new Queue<int>();
		for(int i=0;i<N;i++){
			dist[i] = minf;
			if(Ind[i] == 0 && E[i].Count > 0) Q.Enqueue(i);
		}
		
		if(Q.Count == 0){
			Console.WriteLine("No");
			return;
		}
		while(Q.Count > 0){
			var now = Q.Dequeue();
			foreach(var ni in E[now]){
				int nxt = R[ni];
				long Di = D[ni];
				if(dist[now] == minf && dist[nxt] == minf){
					dist[now] = 0;
					dist[nxt] = Di;
					Ind[nxt]--;
					if(Ind[nxt] == 0) Q.Enqueue(nxt);
				} else if(dist[now] == minf && dist[nxt] != minf){
					dist[now] = dist[nxt] - Di;
					Ind[nxt]--;
					if(Ind[nxt] == 0) Q.Enqueue(nxt);
				} else if(dist[now] != minf && dist[nxt] == minf){
					dist[nxt] = dist[now] + Di;
					Ind[nxt]--;
					if(Ind[nxt] == 0) Q.Enqueue(nxt);
				} else if(dist[now] != minf && dist[nxt] != minf){
					if(dist[now] + Di == dist[nxt]){
						Ind[nxt]--;
						if(Ind[nxt] == 0) Q.Enqueue(nxt);
					} else {
						Console.WriteLine("No");
						return;
					}
				}
			}
		}
		
		Console.WriteLine("Yes");
		
		
	}
	int N,M;
	int[] L,R;
	long[] D;
	public Sol(){
		
		var d = ria();
		N = d[0];
		M = d[1];
		if(M == 0) return;
		L = new int[M];
		R = new int[M];
		D = new long[M];
		
		for(int i=0;i<M;i++){
			d = ria();
			L[i] = d[0] - 1;
			R[i] = d[1] - 1;
			D[i] = d[2];
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