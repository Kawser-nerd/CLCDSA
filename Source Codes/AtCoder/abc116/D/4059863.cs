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
		
		long Inf = (long) 1e18;
		long[] ma = new long[N + 1];
		for(int i=0;i<=N;i++) ma[i] = - Inf;
		Pair[] P = new Pair[N];
		for(int i=0;i<N;i++) P[i] = new Pair(i, D[i]);
		
		Array.Sort(P, (p, q) => -1 * (p.D.CompareTo(q.D)));
		var SH = new SkewHeap<Pair>();
		int[] cnt = new int[N];
		long tD = 0;
		var h = new HashSet<int>();
		for(int i=0;i<K;i++){
			tD += D[P[i].Idx];
			cnt[T[P[i].Idx]]++;
			h.Add(T[P[i].Idx]);
			if(cnt[T[P[i].Idx]] > 1){
				SH.Push(P[i]);
			}
		}
		
		ma[h.Count] = tD;
		for(int i=K;i<N;i++){
			int nt = T[P[i].Idx];
			if(h.Contains(nt)) continue;
			if(SH.Count == 0) continue;
			h.Add(nt);
			var p = SH.Top; SH.Pop();
			tD -= p.D;
			tD += P[i].D;
			ma[h.Count] = Math.Max(tD, ma[h.Count]);
		}
		
		long ans = - Inf;
		for(int i=0;i<=N;i++){
			if(ma[i] == - Inf) continue;
			ans = Math.Max(ans, (long)i * (long) i + ma[i]);
		}
		
		Console.WriteLine(ans);
	}
	
	class Pair :IComparable<Pair> {
		public int Idx;
		public long D;
		public Pair(int idx, long d){
			Idx = idx; D = d;
		}
		public int CompareTo(Pair t) {
			return D.CompareTo(t.D);
		}
		
	}
	
	int N,K;
	int[] T;
	long[] D;
	public Sol(){
		var d = ria();
		N = d[0]; K = d[1];
		T = new int[N];
		D = new long[N];
		for(int i=0;i<N;i++){
			d = ria();
			T[i] = d[0] - 1; D[i] = d[1];
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