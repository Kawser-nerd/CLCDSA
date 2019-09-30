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
		
		if(N == 1){
			Console.WriteLine(0);
			return;
		}
		
		for(int i=0;i<N;i++) Array.Sort(XY[i]);
		Array.Sort(XY,
			(a, b) =>{
			if(a[0] == b[0]) return a[1].CompareTo(b[1]);
			return a[0].CompareTo(b[0]);
			});
		
		var minST = new SegTreeMin[2];
		var maxST = new SegTreeMax[2];
		for(int i=0;i<2;i++){
			minST[i] = new SegTreeMin(N);
			maxST[i] = new SegTreeMax(N);
			for(int j=0;j<N;j++){
				minST[i].Update(j,XY[j][i]);
				maxST[i].Update(j,XY[j][i]);
			}
		}
		
		var SH = new SkewHeap<Pair>();
		for(int i=1;i<N;i++) SH.Push(new Pair(i, XY[i][1]));
		
		long ans = (maxST[0].Max - minST[0].Min) * (maxST[1].Max - minST[1].Min);
		while(SH.Count > 0){
			var p = SH.Top; SH.Pop();
			int idx = p.Pos;
			maxST[0].Update(idx, XY[idx][1]);
			maxST[1].Update(idx, XY[idx][0]);
			minST[0].Update(idx, XY[idx][1]);
			minST[1].Update(idx, XY[idx][0]);
			
			var v = (maxST[0].Max - minST[0].Min) * (maxST[1].Max - minST[1].Min);
			ans = Math.Min(ans, v);
		}
		
		Console.WriteLine(ans);
		
	}
	int N;
	long[][] XY;
	public Sol(){
		N = ri();
		XY = new long[N][];
		for(int i=0;i<N;i++) XY[i] = rla();
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


class SegTreeMin{
	//segment Tree 
	// 0-origin
	protected long[] Data;	
	protected long Inf;	
	protected int N;		
	protected int n;		
	
	public SegTreeMin(int n_){
		N = n_; Inf = (long)1e18;
		n = 1;
		while(n < n_) n *= 2;
		Data = new long[2 * n - 1];
		for(int i=0; i < 2 * n - 1; i++) Data[i] = Inf;
	}
	
	//	   0
	//	 1   2
	//	3 4 5 6
	public void Update(int k,long a){
		k+=n-1;	
		Data[k]=a;
		while(k>0){
			k=(k-1)/2;
			Data[k]=Math.Min(Data[k*2+1],Data[k*2+2]);
		}
	}
	
	
	public long QueryMin(int a, int b){
		return Query(a, b, 0, 0, n);
	}
	//RMQ; [a,b)
	public long Query(int a,int b,int k,int l,int r){
		if(r <= a || b <= l) return Inf;
		if(a <= l && r <= b) return Data[k];
		
		var vl = Query(a, b, k * 2 + 1, l, (l + r) / 2);
		var vr = Query(a ,b, k * 2 + 2, (l + r) / 2, r);
		return Math.Min(vl, vr);
	}
	
	
	public long Min{
		get{ return Data[0];}
	}
	
	
	public void Dump(){
		Console.WriteLine();
		int h = 0;
		int cnt = 0;
		for(int i=0;i<Data.Length;i++){
			Console.Write("{0} ", Data[i]);
			cnt++;
			if(cnt == 1 << h){
				cnt = 0;
				h++;
				Console.WriteLine();
			}
		}
	}
	
}


class SegTreeMax{
	//segment Tree 
	// 0-origin
	protected long[] Data;	
	protected long Inf;	
	protected int N;		 
	protected int n;		
	
	public SegTreeMax(int n_){
		N = n_; Inf = -(long)1e18;
		n = 1;
		while(n < n_) n *= 2;
		Data = new long[2 * n - 1];
		for(int i=0; i < 2 * n - 1; i++) Data[i] = Inf;
	}
	
	//	   0
	//	 1   2
	//	3 4 5 6
	public void Update(int k,long a){
		k += n - 1;	
		Data[k] = a;
		while(k > 0){
			k = (k - 1) / 2;
			Data[k] = Math.Max(Data[k * 2 + 1], Data[k * 2 + 2]);
		}
	}
	
	
	public long QueryMax(int a, int b){
		return Query(a, b, 0, 0, n);
	}
	//RMQ; [a,b)
	public long Query(int a,int b,int k,int l,int r){
		if(r <= a || b <= l) return Inf;
		if(a <= l && r <= b) return Data[k];
		
		var vl = Query(a, b, k * 2 + 1, l, (l + r) / 2);
		var vr = Query(a ,b, k * 2 + 2, (l + r) / 2, r);
		return Math.Max(vl, vr);
	}
	
	
	public long Max{
		get{ return Data[0];}
	}
	
	
	public void Dump(){
		Console.WriteLine();
		int h = 0;
		int cnt = 0;
		for(int i=0;i<Data.Length;i++){
			Console.Write("{0} ", Data[i]);
			cnt++;
			if(cnt == 1 << h){
				cnt = 0;
				h++;
				Console.WriteLine();
			}
		}
	}
	
}


class Pair : IComparable<Pair> {
	public int Pos;
	public long Cost;
	public Pair(int p, long c) {
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