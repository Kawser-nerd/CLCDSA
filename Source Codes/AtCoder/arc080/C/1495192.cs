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
		
		var ST = new SegTree[2];
		for(int i=0;i<2;i++) ST[i] = new SegTree(N);
		for(int i=0;i<N;i++){
			ST[i%2].Update(i,A[i]);
		}
		
		List<int> ans = new List<int>();
		int Inf = (int) 1e9;
		
		var SH = new SkewHeap<Pair>();
		
		var minIdx = QueryMinIdx(0,N,ST);
		SH.Push(new Pair(0, N, A[minIdx[0]], A[minIdx[1]]));
		
		int[] Idx = new int[N+2];
		for(int i=0;i<N;i++) Idx[A[i]] = i;
		
		
		while(SH.Count>0){
			var p = SH.Top; SH.Pop();
			int l = p.L;
			int r = p.R;
			int a = p.A;
			int b = p.B;
			int aidx = Idx[a];
			int bidx = Idx[b];
			
			ans.Add(a);
			ans.Add(b);
			ST[aidx % 2].Update(aidx,Inf);
			ST[bidx % 2].Update(bidx,Inf);
			if(aidx - l > 1){
				var midx = QueryMinIdx(l,aidx,ST);
				SH.Push(new Pair(l, aidx, A[midx[0]], A[midx[1]]));
			}
			if(bidx - (aidx+1) > 1){
				var midx = QueryMinIdx(aidx+1,bidx,ST);
				SH.Push(new Pair(aidx+1, bidx, A[midx[0]], A[midx[1]]));
			}
			if(r - (bidx + 1) > 1){
				var midx = QueryMinIdx(bidx+1,r,ST);
				SH.Push(new Pair(bidx+1, r, A[midx[0]], A[midx[1]]));
			}
		}
		
		Console.WriteLine(String.Join(" ",ans));
		
	}
	
	int[] QueryMinIdx(int l, int r, SegTree[] st){
		// [l, r)
		var ret = new int[2];
		var md1 = st[l%2].QueryMinIdx(l,r);
		ret[0] = md1;
		var md2 = st[(l%2)^1].QueryMinIdx(md1,r);
		ret[1] = md2;
		return ret;
	}
	
	int N;
	int[] A;
	public Sol(){
		N = ri();
		A = ria();
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
	public int L,R;//[,)
	public int A,B;
	public Pair(int l, int r, int a, int b) {
		L = l; R = r; A = a; B = b;
	}
	public int CompareTo(Pair t) {
		//return this.Cost > t.Cost ? -1 : this.Cost < t.Cost ? 1 : 0;
		//return this.Cost > t.Cost ? 1 : this.Cost < t.Cost ? -1 : 0;
		if(this.A.CompareTo(t.A) != 0) return this.A.CompareTo(t.A);
		return this.B.CompareTo(t.B);
	}
}


class SegTree{
	//segment Tree 
	// 0-origin
	public int[] Data;	
	public int[] Idx;	
	public int Inf;	
	public int N;		//size 
	public int n;		//size (power of 2);
	
	// constructor
	public SegTree(int n_){
		N = n_; Inf = (int)1e9;
		n = 1;
		while(n < n_) n *= 2;
		Data = new int[2*n - 1];
		Idx = new int[2*n - 1];
		for(int i=0;i<2*n-1;i++) Data[i] = Inf;
	}
	
	//	   0
	//	 1   2
	//	3 4 5 6
	public void Update(int k, int a){
		k+=n-1;	
		Data[k]=a;
		Idx[k] = k - (n - 1);
		while(k>0){
			k=(k-1)/2;
			Data[k] = Math.Min(Data[k*2+1], Data[k*2+2]);
			Idx[k] = Data[k*2+1] < Data[k*2+2] ? Idx[k*2+1] : Idx[k*2+2];
		}
	}
	
	
	
	//RMQ;
	//	[a,b) 
	//	call: Query(a,b,0,0,n) 
	public int QueryMin(int a, int b){
		return Query(a, b, 0, 0, n);
	}
	public int QueryMinIdx(int a, int b){
		return QueryIdx(a, b, 0, 0, n);
	}

	public int Query(int a,int b,int k,int l,int r){
		// [a,b) not overwraps [l,r) => return Inf
		if(r<=a || b<=l) return Inf;
		// [a,b) include [l,r) => return Data[k];
		if(a<=l && r<=b)return Data[k];
		// or return min(left,right)
		var vl = Query(a,b,k*2+1,l,(l+r)/2);
		var vr = Query(a,b,k*2+2,(l+r)/2,r);
		return Math.Min(vl,vr);
	}
	public int QueryIdx(int a,int b,int k,int l,int r){
		// [a,b) not overwraps [l,r) => return Inf
		if(r<=a || b<=l) return -1;
		// [a,b) include [l,r) => return Data[k];
		if(a<=l && r<=b)return Idx[k];
		// or return min(left,right)
		var vl = Query(a,b,k*2+1,l,(l+r)/2);
		var vr = Query(a,b,k*2+2,(l+r)/2,r);
		var vlidx = QueryIdx(a,b,k*2+1,l,(l+r)/2);
		var vridx = QueryIdx(a,b,k*2+2,(l+r)/2,r);
		return vl < vr ? vlidx : vridx;
	}
	
	
	public int Min{
		get{ return Data[0]; }
	}
	public int MinIdx{
		get{ return Idx[0]; }
	}
	
	public void UniqInit(int val){
		for(int i=0+n-1;i<N+n-1;i++) Data[i] = val;
		int l = n-1; int r = N+n-1-1;
		while(l > 0){
			l = (l-1)/2; r = (r-1)/2;
			for(int i=l;i<=r;i++) Data[i] = val;
		}
	}
	public void UniqInit(int[] vs){
		for(int i=0+n-1;i<N+n-1;i++) {
			Data[i] = vs[i-(n-1)];
			Idx[i] = i - (n-1);
		}
		for(int i=n-2;i>=0;i--){
			Data[i] = Math.Min(Data[2*i+1],Data[2*i+2]);
			Idx[i] = Data[2*i+1] < Data[2*i+2] ? Idx[2*i+1] : Idx[2*i+2];
		}
	}
	
	public void Dump(){
		Console.WriteLine();
		int h = 0;
		int cnt = 0;
		for(int i=0;i<Data.Length;i++){
			Console.Write("{0} ",Data[i]);
			cnt++;
			if(cnt == 1<<h){
				cnt = 0;
				h++; 
				Console.WriteLine();
			}
		}
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