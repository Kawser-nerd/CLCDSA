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
		
		var L = new List<Edge>();
		Array.Sort(P, (p,q) => p.X.CompareTo(q.X) == 0 ? p.Y.CompareTo(q.Y) : p.X.CompareTo(q.X));
		for(int i=0;i<N-1;i++){
			L.Add(new Edge(P[i].Idx, P[i+1].Idx, Math.Min(Math.Abs(P[i+1].X - P[i].X), Math.Abs(P[i+1].Y - P[i].Y))));
			L.Add(new Edge(P[i+1].Idx, P[i].Idx, Math.Min(Math.Abs(P[i+1].X - P[i].X), Math.Abs(P[i+1].Y - P[i].Y))));
		}
		Array.Sort(P, (p,q) => p.Y.CompareTo(q.Y) == 0 ? p.X.CompareTo(q.X) : p.Y.CompareTo(q.Y));
		for(int i=0;i<N-1;i++){
			L.Add(new Edge(P[i].Idx, P[i+1].Idx, Math.Min(Math.Abs(P[i+1].X - P[i].X), Math.Abs(P[i+1].Y - P[i].Y))));
			L.Add(new Edge(P[i+1].Idx, P[i].Idx, Math.Min(Math.Abs(P[i+1].X - P[i].X), Math.Abs(P[i+1].Y - P[i].Y))));
		}
		
		L.Sort( (p, q) => p.Cost.CompareTo(q.Cost));
		var UF = new UnionFind(N);
		long cost = 0;
		foreach(var e in L){
			if(UF.IsUnited(e.Fr, e.To)) continue;
			cost += e.Cost;
			UF.Unite(e.Fr, e.To);
		}
		Console.WriteLine(cost);
		
	}
	int N;
	Pair[] P;
	public Sol(){
		N = ri();
		P = new Pair[N];
		for(int i=0;i<N;i++){
			var d = ria();
			P[i] = new Pair(d[0],d[1],i);
		}
	}
	
	class Pair{
		public int X,Y,Idx;
		public Pair(int x, int y, int idx){
			X = x; Y = y; Idx = idx;
		}
	}
	class Edge{
		public int Fr, To, Cost;
		public Edge(int f, int t, int c){
			Fr = f; To = t; Cost = c;
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
	public UnionFind(int n_){
		Initialize(n_);
	}
	
	public void Initialize(int n_){
		N=n_;
		parent=new int[N];
		mem=new int[N];
		for(int i=0;i<N;i++){
			parent[i]=i;
			mem[i]=1;
		}
		compo=N;
	}
	
	public int Parent(int a){
		if(parent[a]==a)return a;
		return parent[a]=Parent(parent[a]);
	}
	
	public bool IsUnited(int a,int b){
		return Parent(a)==Parent(b);
	}
	
	public void Unite(int a,int b){
		a=Parent(a);b=Parent(b);//Parent()??????a?????????parent?root???
		if(a==b)return;
		parent[a]=b;
		mem[b]+=mem[a];
		compo-=1;
	}
	
	public bool IsRoot(int x){
		return x==parent[x];
	}
	public int MemCnt(int x){
		return mem[Parent(x)];
	}
	
	public void Dump(){
		for(int i=0;i<parent.Length;i++){
			Console.Write(i==0?"{0}":" {0}",parent[i]);
		}
		Console.WriteLine("");
	}
	
	public int Compo{
		get{
			return compo;
		}
	}
	
}