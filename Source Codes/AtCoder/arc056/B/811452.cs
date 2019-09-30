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
		
		bool[] visit = new bool[N];
		int[] BN = new int[N];
		for(int i=0;i<N;i++)BN[i] = -1;
		SkewHeap<Pair> SH = new SkewHeap<Pair>();
		//visit[S] = true;
		
		SH.Push(new Pair(S,S));
		BN[S] = S;
		
		while(SH.Count>0){
			var p = SH.Top; SH.Pop();
			if(visit[p.Pos])continue;
			visit[p.Pos] = true;
			BN[p.Pos] = p.Cost;
//Console.WriteLine("{0} {1}",p.Pos,p.Cost);
			foreach(var nxt in E[p.Pos]){
				if(BN[nxt] < p.Cost){
					BN[nxt] = Math.Min(p.Cost,nxt);
					SH.Push(new Pair(nxt,BN[nxt]));
				}
			}
		}
//Console.WriteLine(String.Join(" ",BN));
		var sb = new StringBuilder();
		for(int i=0;i<N;i++){
			if(BN[i] >= i){
				sb.AppendLine((i+1).ToString());
			}
		}
		Console.Write(sb.ToString());
	}
	
	
	
	
	int N,M,S;
	List<int>[] E;
	public Sol(){
		var d = ria();
		N = d[0]; M = d[1]; S = d[2] - 1;
		E = new List<int>[N];
		for(int i=0;i<N;i++){
			E[i] = new List<int>();
		}
		for(int i=0;i<M;i++){
			d = ria();
			int f = d.Max() - 1;
			int t = d.Min() - 1;
			E[f].Add(t);
			E[t].Add(f);
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
 
class Pair : IComparable<Pair> {
	public int Pos;
	public int Cost;
	public Pair(int p, int c) {
		Pos = p; Cost = c;
	}
	public int CompareTo(Pair t) {
		return this.Cost > t.Cost ? -1 : this.Cost < t.Cost ? 1 : 0;
		//return this.Cost > t.Cost ? 1 : this.Cost < t.Cost ? -1 : 0;
	}
}
 
 
class SkewHeap<T> where T:IComparable<T>{
	public int Count{
		get{return cnt;}
		private set{cnt=value;}
	}
	
	public SkewHeap(){
		root=null;
		this.Count=0;
	}
	
	public void Push(T v){
		NodeSH<T> p=new NodeSH<T>(v);
		root=NodeSH<T>.Meld(root,p);
		this.Count++;
	}
	
	public void Pop(){
		if(root==null)return;
		root=NodeSH<T>.Meld(root.L,root.R);
		this.Count--;
	}
	
	public T Top{
		get{return root.Val;}
	}
	
	int cnt;
	NodeSH<T> root;
	
	class NodeSH<S> where S : IComparable<S> {
		public NodeSH<S> L, R;
		public S Val;
 
		public NodeSH(S v){
			Val = v;
			L = null; R = null;
		}
		public static NodeSH<S> Meld(NodeSH<S> a, NodeSH<S> b){
			if(a == null)return b;
			if (b == null) return a;
			if (a.Val.CompareTo(b.Val) > 0) swap(ref a, ref b);
			a.R = Meld(a.R, b);
			swap(ref a.L, ref a.R);
			return a;
		}
 
		static void swap<U>(ref U x, ref U y) {
			U t = x; x = y; y = t;
		}
	}
}