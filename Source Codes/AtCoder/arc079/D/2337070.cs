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
		
		List<int>[] E = new List<int>[N];
		List<int>[] XE = new List<int>[N];
		for(int i=0;i<N;i++){
			E[i] = new List<int>();
			XE[i] = new List<int>();
		}
		for(int i=0;i<N;i++){
			E[P[i]].Add(i);
			XE[i].Add(P[i]);
		
		}
		
		
		
		var scc = new SCC();
		scc.Init(N, E, XE);
		scc.CalcCompo();
		if(scc.Compo == N){
			Console.WriteLine("POSSIBLE");
			return;
		}
		
		if(scc.Compo == 1){
			Console.WriteLine(N % 2 == 0 ? "POSSIBLE" : "IMPOSSIBLE");
			return;
		}
		
		int M = scc.Compo;
		List<int>[] sc = new List<int>[M];
		for(int i=0;i<M;i++){
			sc[i] = new List<int>();
		}
		
		int cyc = -1;
		for(int i=0;i<N;i++){
			sc[scc.Mem[i]].Add(i);
			if(sc[scc.Mem[i]].Count > 1) cyc = scc.Mem[i];
		}
		
		Pair[] ar = new Pair[N];
		for(int i=0;i<N;i++){
			ar[i] = new Pair(i, scc.Mem[i]);
		}
		
		Array.Sort(ar, (p, q) => p.Order.CompareTo(q.Order));
		Array.Reverse(ar);

//Console.WriteLine(String.Join(" ",ar.Select(p => String.Format("[{0},{1}]",p.Idx,p.Order))));
		
		int[] gr = new int[N];
		for(int i=0;i<N;i++) gr[i] = -1;
		
		foreach(var p in ar){
			if(p.Order == cyc) break;
			int now = p.Idx;
			var hs = new HashSet<int>();
			foreach(var nxt in E[now]) hs.Add(gr[nxt]);
			int g = 0;
			while(hs.Contains(g)) g++;
			gr[now] = g;
		}
		
		int p0 = sc[cyc][0];
		var hss = new HashSet<int>();
		foreach(var nxt in E[p0]){
			hss.Add(gr[nxt]);
		}
		List<int> gg = new List<int>();
		int g0 = 0;
		while(hss.Contains(g0)) g0++;
		gg.Add(g0);
		hss.Add(g0);
		while(hss.Contains(g0)) g0++;
		gg.Add(g0);
		
		// cycle ?List??????
		List<int> loop = new List<int>();
		loop.Add(p0);
		while(true){
			int now = loop[loop.Count - 1];
			foreach(var nxt in E[now]){
				if(scc.Mem[nxt] == cyc){
					loop.Add(nxt);
					break;
				}
			}
			if(loop[loop.Count - 1] == p0){
				loop.RemoveAt(loop.Count - 1);
				break;
			}
		}
		
//Console.WriteLine(String.Join(" -> ",loop));		
		
		
		// p0 ? min?????
		int[] gr0 = new int[N];
		for(int i=0;i<N;i++) gr0[i] = gr[i];
		gr0[p0] = gg[0];
		for(int i= loop.Count - 1; i>=0; i--){
			int now = loop[i];
			var hs = new HashSet<int>();
			foreach(var nxt in E[now]) hs.Add(gr0[nxt]);
			int g = 0;
			while(hs.Contains(g)) g++;
			if(i > 0){
				gr0[now] = g;
				continue;
			}
			if(i == 0){
				if(g == gg[0]){
					Console.WriteLine("POSSIBLE");
					return;
				}
			}
		}
		
		// p0 ? gg[1] ??????nxt?gg[0]??????
		
		int[] gr1 = new int[N];
		for(int i=0;i<N;i++) gr1[i] = gr[i];
		gr1[p0] = gg[1];
		gr1[loop[1]] = gg[0];
		for(int i= loop.Count - 1; i>=1; i--){
			int now = loop[i];
			var hs = new HashSet<int>();
			foreach(var nxt in E[now]) hs.Add(gr1[nxt]);
			int g = 0;
			while(hs.Contains(g)) g++;
			if(i > 1){
				gr1[now] = g;
				continue;
			}
			if(i == 1){
				if(g == gg[0]){
					Console.WriteLine("POSSIBLE");
					return;
				}
			}
		}
		
		Console.WriteLine("IMPOSSIBLE");
		
	}
	
	class Pair{
		public int Idx, Order;
		public Pair(int idx, int order){
			Idx = idx; Order = order;
		}
	}
	
	int N;
	int[] P;
	public Sol(){
		N = ri();
		P = ria();
		for(int i=0;i<N;i++) P[i]--;
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


class SCC {
	
	// Mem: component number for each vertice;
	// Compo: num of Component
	public int[] Mem;
	public int Compo;
	
	public List<int>[] E;
	public List<int>[] XE;
	public int N;
	
	public void Init(int n,List<int>[] e, List<int>[] xe, bool deepCopy = false){
		N = n;
		Mem = new int[N];
		if(!deepCopy){
			E = e;
			XE = xe;
			return;
		}
		
		E = new List<int>[N];
		XE = new List<int>[N];
		for(int i=0;i<N;i++){
			E[i] = new List<int>(e[i]);
			XE[i] = new List<int>(xe[i]);
		}
	}
	
	public void CalcCompo(){
		
		used = new bool[N];
		vs = new List<int>();
		for(int i=0;i<N;i++){
			if(!used[i]) dfs(i);
		}
		
		used = new bool[N];
		int k = 0;
		for(int i=vs.Count-1;i>=0;i--){
			if(!used[vs[i]]) rdfs(vs[i], k++);
		}
		
		Compo = k;
	}
	
	bool[] used;
	List<int> vs;
	
	void dfs(int now){
		used[now] = true;
		foreach(var nxt in E[now]){
			if(!used[nxt]) dfs(nxt);
		}
		vs.Add(now);
	}
	
	void rdfs(int now, int k){
		used[now] = true;
		Mem[now] = k;
		foreach(var nxt in XE[now]){
			if(!used[nxt]) rdfs(nxt, k);
		}
	}
	
}