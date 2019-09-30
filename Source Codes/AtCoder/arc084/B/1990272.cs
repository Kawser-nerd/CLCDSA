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
		
		int Inf = (int) 1e9;
		int[] min = new int[K];
		for(int i=0;i<K;i++) min[i] = Inf;
		
		var SH = new SkewHeap<Pair>();
		
		for(int i=1;i<=9;i++){
			if(min[i % K] > i){
				min[i % K] = i;
				SH.Push(new Pair(i % K, i));
			}
		}
		
		bool[] used = new bool[K];
		while(SH.Count > 0){
			var p = SH.Top; SH.Pop();
			int now = p.Pos;
			int cost = p.Cost;
			if(used[now]) continue;
			used[now] = true;
			for(int j=0;j<10;j++){
				var nxt = (now * 10 + j) % K;
				if(min[nxt] > cost + j){
					min[nxt] = cost + j;
					SH.Push(new Pair(nxt, min[nxt]));
				}
			}
		}
		
		Console.WriteLine(min[0]);
		
		
		
	}
	int K;
	public Sol(){
		K = ri();
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
		//return this.Cost > t.Cost ? -1 : this.Cost < t.Cost ? 1 : 0;
		return this.Cost > t.Cost ? 1 : this.Cost < t.Cost ? -1 : 0;
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