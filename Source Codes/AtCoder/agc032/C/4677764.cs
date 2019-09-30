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
		
		if(!chk1()){
			Console.WriteLine("No");
			return;
		}
		
		List<int>[] E = new List<int>[N];
		for(int i=0;i<N;i++) E[i] = new List<int>();
		for(int i=0;i<M;i++){
			E[A[i]].Add(i);
			E[B[i]].Add(i);
		}
		
		int[] dep = new int[N];
		int[] pe = new int[N];
		var o1 = new List<int>();
		for(int i=0;i<N;i++) dep[i] = -1;
		for(int i=0;i<N;i++) pe[i] = -1;
		dep[0] = 0;
		var q = new Queue<int>();
		q.Enqueue(0);
		bool found = false;
		while(q.Count > 0){
			if(found) break;
			var now = q.Dequeue();
			foreach(var e in E[now]){
				int nxt = A[e] == now ? B[e] : A[e];
				if(e == pe[now]) continue;
				if(dep[nxt] == -1){
					dep[nxt] = dep[now] + 1;
					pe[nxt] = e;
					q.Enqueue(nxt);
					continue;
				}
				found = true;
				o1.Add(e);
				int v = now;
				while(pe[v] != -1){
					int nv = A[pe[v]] == v ? B[pe[v]] : A[pe[v]];
					o1.Add(pe[v]);
					v = nv;
				}
				v = nxt;
				while(pe[v] != -1){
					int nv = A[pe[v]] == v ? B[pe[v]] : A[pe[v]];
					o1.Add(pe[v]);
					v = nv;
				}
				break;
			}
		}
		
		bool[] used = new bool[M];
		foreach(var e in o1){
			used[e] = true;
		}
		
		if(chk2(used)){
			Console.WriteLine("Yes");
			return;
		}
		
		E = new List<int>[N];
		for(int i=0;i<N;i++) E[i] = new List<int>();
		int ec = 0;
		for(int i=0;i<M;i++){
			if(used[i]) continue;
			ec++;
			E[A[i]].Add(i);
			E[B[i]].Add(i);
		}
		
		if(ec == 0){
			Console.WriteLine("No");
			return;
		}
		dep = new int[N];
		pe = new int[N];
		var o2 = new List<int>();
		for(int i=0;i<N;i++) dep[i] = -1;
		for(int i=0;i<N;i++) pe[i] = -1;
		int root = -1;
		for(int i=0;i<N;i++){
			if(E[i].Count > 0){
				root = i;
				break;
			}
		}
		if(root == -1){
			Console.WriteLine("No");
			return;
		}
		dep[root] = 0;
		q = new Queue<int>();
		q.Enqueue(root);
		found = false;
		while(q.Count > 0){
			if(found) break;
			var now = q.Dequeue();
			foreach(var e in E[now]){
				int nxt = A[e] == now ? B[e] : A[e];
				if(e == pe[now]) continue;
				if(dep[nxt] == -1){
					dep[nxt] = dep[now] + 1;
					pe[nxt] = e;
					q.Enqueue(nxt);
					continue;
				}
				found = true;
				o2.Add(e);
				int v = now;
				while(pe[v] != -1){
					int nv = A[pe[v]] == v ? B[pe[v]] : A[pe[v]];
					o2.Add(pe[v]);
					v = nv;
				}
				v = nxt;
				while(pe[v] != -1){
					int nv = A[pe[v]] == v ? B[pe[v]] : A[pe[v]];
					o2.Add(pe[v]);
					v = nv;
				}
				break;
			}
		}
		
		foreach(var e in o2){
			used[e] = true;
		}
		if(o1.Count == 0 || o2.Count == 0){
			Console.WriteLine("No");
			return;
		}
		
		for(int i=0;i<M;i++){
			if(!used[i]){
				var bbb = chk3(used);
//Console.WriteLine(String.Join(" ", used));
if(!bbb) throw new Exception();
				Console.WriteLine(bbb ? "Yes" : "No");
				return;
			}
		}
		
		var h1 = new HashSet<int>();
		foreach(var e in o1){
			h1.Add(A[e]);
			h1.Add(B[e]);
		}
		var h2 = new HashSet<int>();
		foreach(var e in o2){
			h2.Add(A[e]);
			h2.Add(B[e]);
		}
		int ccc = 0;
		foreach(var vv in h2){
			if(h1.Contains(vv)) ccc++;
		}
		Console.WriteLine(ccc >= 3 ? "Yes" : "No");
		
		
	}
	
	bool chk1(){
		int[] deg = new int[N];
		for(int i=0;i<M;i++){
			deg[A[i]]++;
			deg[B[i]]++;
		}
		for(int i=0;i<N;i++){
			if(deg[i] == 0 || deg[i] % 2 == 1){
				return false;
			}
		}
		return true;
	}
	
	bool chk2(bool[] used){
		var UF = new UnionFind(N);
		for(int i=0;i<M;i++){
			if(used[i]) continue;
			UF.Unite(A[i], B[i]);
		}
		int cnt = 0;
		var hs = new HashSet<int>();
		for(int i=0;i<N;i++){
			if(UF.MemCnt(i) == 1) continue;
			hs.Add(UF.MemCnt(i));
			cnt++;
		}
		if(hs.Count == 1){
			var num = hs.ToList()[0];
			if(num == cnt) return false;
		}
		if(hs.Count == 0){
			return false;
		}
		return true;
		
	}
	
	bool chk3(bool[] used){
		
		int[] deg = new int[N];
		for(int i=0;i<M;i++){
			deg[A[i]]++;
			deg[B[i]]++;
		}
		for(int i=0;i<N;i++){
			if(deg[i] % 2 == 1){
				return false;
			}
		}
		var UF = new UnionFind(N);
		for(int i=0;i<M;i++){
			if(used[i]) continue;
			UF.Unite(A[i], B[i]);
		}
		int cnt = 0;
		var hs = new HashSet<int>();
		for(int i=0;i<N;i++){
			if(UF.MemCnt(i) == 1) continue;
			hs.Add(UF.MemCnt(i));
			cnt++;
		}
		if(hs.Count == 1){
			var num = hs.ToList()[0];
			if(num == cnt) return true;
		}
		return false;
		
		
	}
	
	
	
	int N,M;
	int[] A,B;
	public Sol(){
		var d = ria();
		N = d[0]; M = d[1];
		A = new int[M];
		B = new int[M];
		for(int i=0;i<M;i++){
			var dd = ria();
			A[i] = dd[0] - 1;
			B[i] = dd[1] - 1;
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


class UnionFind{
	
	int[] parent;
	int[] mem;
	int compo;
	int N;
	
	public UnionFind(UnionFind v){
		// copy constructor
		N = v.N;
		parent = new int[N];
		mem = new int[N];
		for(int i=0;i<N;i++){
			parent[i] = v.parent[i];
			mem[i] = v.mem[i];
		}
		compo = v.compo;
	}
	public UnionFind(int n_){
		Initialize(n_);
	}
	
	public void Initialize(int n_){
		N = n_;
		parent = new int[N];
		mem=new int[N];
		for(int i=0;i<N;i++){
			parent[i] = i;
			mem[i] = 1;
		}
		compo = N;
	}
	
	public int Parent(int a){
		if(parent[a] == a)return a;
		return parent[a] = Parent(parent[a]);
	}
	
	public bool IsUnited(int a,int b){
		return Parent(a) == Parent(b);
	}
	
	public void Unite(int a,int b){
		a = Parent(a); b = Parent(b);//Parent()??????a?????????parent?root???
		if(a == b)return;
		parent[a] = b;
		mem[b] += mem[a];
		compo -= 1;
	}
	
	public bool IsRoot(int x){
		return x == parent[x];
	}
	public int MemCnt(int x){
		return mem[Parent(x)];
	}
	
	public void Dump(){
		for(int i=0;i<parent.Length;i++){
			Console.Write(i == 0 ? "{0}" : " {0}",parent[i]);
		}
		Console.WriteLine("");
	}
	
	public int Compo{
		get{
			return compo;
		}
	}
	
}