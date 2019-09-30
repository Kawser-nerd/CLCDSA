using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

class TEST{
	static void Main(){
		Sol mySol =new Sol();
		mySol.Solve();
	}
}

class Sol{
	public void Solve(){
		
		Dictionary<long, List<Pair2>> E = new Dictionary<long, List<Pair2>>();
		int Ext = (int) 1e7;
		long mod = (long)1e9 + 7;
	
		for(int i=0;i<M;i++){
			var p0 = P[i] * mod + C[i];
			var q0 = Q[i] * mod + C[i];
			var p1 = P[i] * mod + Ext;
			var q1 = Q[i] * mod + Ext;
			if(!E.ContainsKey(p0)) E.Add(p0, new List<Pair2>());
			if(!E.ContainsKey(q0)) E.Add(q0, new List<Pair2>());
			if(!E.ContainsKey(p1)) E.Add(p1, new List<Pair2>());
			if(!E.ContainsKey(q1)) E.Add(q1, new List<Pair2>());
			E[p0].Add(new Pair2(q0, 0));
			E[q0].Add(new Pair2(p0, 0));
			E[p0].Add(new Pair2(p1, 1));// ???????????1
			E[q0].Add(new Pair2(q1, 1));
			E[p1].Add(new Pair2(p0, 0));
			E[q1].Add(new Pair2(q0, 0));
		}
		
		long Inf = (long) 1e9;
		Dictionary<long, long> Min = new Dictionary<long, long>();
		var SH = new SkewHeap<Pair2>();
		var pstart = 0 * mod + Ext;
		Min.Add(pstart, 0);
		SH.Push(new Pair2(pstart, 0));
		
		HashSet<long> done = new HashSet<long>();
		
		while(SH.Count > 0){
			var now = SH.Top; SH.Pop();
			var p = now.Pos;
			var c = now.Cost;
			if(done.Contains(p)) continue;
			done.Add(p);
			Min[p] = c;
			if(!E.ContainsKey(p)) continue;
			foreach(var nxt in E[p]){
				var np = nxt.Pos;
				var nc = nxt.Cost;
				if(!Min.ContainsKey(np)) Min.Add(np, Inf);
				if(Min[np] <= c + nc) continue;
				Min[np] = c + nc;
				SH.Push(new Pair2(np, c + nc));
			}
		}
		
		var pend = (N-1) * mod + Ext;
		Console.WriteLine(Min.ContainsKey(pend) ? Min[pend] : -1);
		
		
		
	}
	int N,M;
	int[] P,Q;
	long[] C;
	
	class Pair2 : IComparable<Pair2> {
		public long Pos;
		public long Cost;
		public Pair2(long p, long c) {
			Pos = p; Cost = c;
		}
		public int CompareTo(Pair2 t) {
			//return this.Cost > t.Cost ? -1 : this.Cost < t.Cost ? 1 : 0;
			return this.Cost > t.Cost ? 1 : this.Cost < t.Cost ? -1 : 0;
		}
	}
	public Sol(){
		using(var r = new FastIn()){
		N = r.ReadInt(); M = r.ReadInt();
		P = new int[M];
		Q = new int[M];
		C = new long[M];
		for(int i=0;i<M;i++){
			P[i] = r.ReadInt() - 1; Q[i] = r.ReadInt() - 1; C[i] = r.ReadInt();
		}
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


class FastIn:IDisposable {
	int Size;
	byte[] Mem;
	int ptr;
	int rsize;
	bool unfinished;
	Stream stdin;
	void Init(int n) {
		Size = n;
		Mem = new byte[Size];
		rsize=(stdin=Console.OpenStandardInput()).Read(Mem, 0, Size);
		ptr = 0;
		unfinished=(rsize == Size);
	}
	void Next() {
		if (unfinished == false) return;
		rsize=stdin.Read(Mem, 0, Size);
		ptr = 0;
		unfinished = (rsize == Size);
	}
	
	~FastIn(){
		stdin.Dispose();
	}
	void IDisposable.Dispose(){
		stdin.Dispose();
	}
	public void Dispose(){
		stdin.Dispose();
	}
	
	public FastIn() {
		Init(100000);
	}
	public FastIn(int n) {
		Init(n);
	}
	public int ReadInt() {
		int ret = 0;
		int sig = 1;
		while (ptr < rsize && Mem[ptr] != ' ' && Mem[ptr] != '\n' && Mem[ptr] != '\r' ) {
			if(ret==0 && Mem[ptr] == '-'){
				sig *= -1; ptr++; continue;
			}
			ret = ret * 10 + Mem[ptr++] - '0';
			if (ptr == Size) Next();
		}
		while (ptr < rsize && (Mem[ptr] == ' ' || Mem[ptr] == '\n' || Mem[ptr] == '\r') ) {
			ptr++;
			if (ptr == Size) Next();
		}
		return ret*sig;
	}
	public uint ReadUint() {
		uint ret = 0;
		uint sig = 1;
		while (ptr < rsize && Mem[ptr] != ' ' && Mem[ptr] != '\n' && Mem[ptr] != '\r' ) {
			ret = ret * 10 + Mem[ptr++] - '0';
			if (ptr == Size) Next();
		}
		while (ptr < rsize && (Mem[ptr] == ' ' || Mem[ptr] == '\n' || Mem[ptr] == '\r') ) {
			ptr++;
			if (ptr == Size) Next();
		}
		return ret*sig;
	}
	public long ReadLong() {
		long ret = 0;
		long sig = 1;
		while (ptr < rsize && Mem[ptr] != ' ' && Mem[ptr] != '\n' && Mem[ptr] != '\r' ) {
			if(ret==0 && Mem[ptr] == '-'){
				sig *= -1; ptr++; continue;
			}
			ret = ret * 10 + Mem[ptr++] - '0';
			if (ptr == Size) Next();
		}
		while (ptr < rsize &&  (Mem[ptr] == ' ' || Mem[ptr] == '\n' || Mem[ptr] == '\r')  ) {
			ptr++;
			if (ptr == Size) Next();
		}
		return ret*sig;
	}
	
	public double ReadDouble() {
		double ret = 0;
		double sig = 1;
		bool dot = false;
		double keta = 0.1;
		while (ptr < rsize && Mem[ptr] != ' ' && Mem[ptr] != '\n' && Mem[ptr] != '\r' ) {
			if(ret==0 && Mem[ptr] == '-'){
				sig *= -1; ptr++;
				if (ptr == Size) Next();
				continue;
			}
			if(Mem[ptr] == '.'){
				dot = true;
				ptr++;
				if (ptr == Size) Next();
				continue;
			}
			if(!dot){
				ret = ret * 10 + Mem[ptr++] - '0';
				if (ptr == Size) Next();
			}else{
				ret = ret + (Mem[ptr++] - '0')*keta;
				keta /= 10.0;
				if (ptr == Size) Next();
			}
		}
		while (ptr < rsize && (Mem[ptr] == ' ' || Mem[ptr] == '\n' || Mem[ptr] == '\r') ) {
			ptr++;
			if (ptr == Size) Next();
		}
		return ret*sig;
	}

	public String ReadStr() {
		//2byte???NG
		StringBuilder sb = new StringBuilder();
		while (ptr < rsize && Mem[ptr] != ' ' && Mem[ptr] != '\n' && Mem[ptr] != '\r') {
			sb.Append((char)Mem[ptr++]);
			if (ptr == Size && unfinished) Next();
		}
		while (ptr < rsize &&  (Mem[ptr] == ' ' || Mem[ptr] == '\n' || Mem[ptr] == '\r') ) {
			ptr++;
			if (ptr == Size && unfinished) Next();
		}
		return sb.ToString();
	}
	public String ReadLine() {
		//??????(split/parse?????????????
		StringBuilder sb = new StringBuilder();
		while (ptr < rsize && Mem[ptr] != '\n' && Mem[ptr] != '\r') {
			sb.Append((char)Mem[ptr++]);
			if (ptr == Size && unfinished) Next();
		}
		while (ptr < rsize &&  (Mem[ptr] == ' ' || Mem[ptr] == '\n' || Mem[ptr] == '\r')) {
			ptr++;
			if (ptr == Size && unfinished) Next();
		}
		return sb.ToString();
	}
}