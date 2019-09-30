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
		
		long[][] WF = new long[N][];
		for(int i=0;i<N;i++){
			WF[i] = (long[]) A[i].Clone();
		}
		
		for(int k=0;k<N;k++){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					WF[i][j] = Math.Min(WF[i][j],WF[i][k] + WF[k][j]);
				}
			}
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(WF[i][j] != A[i][j]){
					Console.WriteLine(-1);
					return;
				}
			}
		}
		
		List<Pair> L = new List<Pair>();
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				L.Add(new Pair(i*1000+j,A[i][j]));
			}
		}
		L.Sort((p,q) => p.Dist.CompareTo(q.Dist));
		
		long Inf = (long)1e18;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				WF[i][j] = i == j ? 0 : Inf;
			}
		}
		
		long tot = 0;
		foreach(var p in L){
			int f = (int) p.FT/1000;
			int t = (int) p.FT%1000;
			if(WF[f][t] > A[f][t]){
				WF[f][t] = WF[t][f] = p.Dist;
				tot += p.Dist;
				for(int i=0;i<N;i++){
					for(int j=0;j<N;j++){
						WF[i][j] = Math.Min(WF[i][j],WF[i][f]+WF[f][t]+WF[t][j]);
						WF[i][j] = Math.Min(WF[i][j],WF[i][t]+WF[t][f]+WF[f][j]);
					}
				}
			}
		}
		
		Console.WriteLine(tot);
		
	}
	
	class Pair{
		public long FT;
		public long Dist;
		public Pair(long ft, long dist){
			FT = ft; Dist = dist;
		}
	}
	
	
	int N;
	long[][] A;
	public Sol(){
		N = ri();
		A = new long[N][];
		for(int i=0;i<N;i++) A[i] = rla();
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