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
		
		int[][] W = new int[NN][];
		for(int i=0;i<NN;i++){
			W[i] = new int[N];
		}
		int[][] B = new int[NN][];
		for(int i=0;i<NN;i++){
			B[i] = new int[N];
		}
		for(int i=0;i<NN;i++){
			if(C[i] == 'W'){
				W[i][A[i]] = 1;
			} else {
				B[i][A[i]] = 1;
			}
			if(i < NN - 1){
				for(int j=0;j<N;j++){
					W[i+1][j] = W[i][j];
					B[i+1][j] = B[i][j];
				}
			}
		}
		
		int[][] SW = new int[NN][];
		int[][] SB = new int[NN][];
		for(int i=0;i<NN;i++){
			SW[i] = new int[N + 1];
			for(int j=0;j<N;j++){
				SW[i][j+1] = SW[i][j] + W[i][j];
			}
			SB[i] = new int[N + 1];
			for(int j=0;j<N;j++){
				SB[i][j+1] = SB[i][j] + B[i][j];
			}
		}
		
		int[] Binv = new int[N];
		int[] Winv = new int[N];
		for(int i=0;i<NN;i++){
			if(C[i] == 'B'){
				Binv[A[i]] = i;
			} else {
				Winv[A[i]] = i;
			}
		}
		
		
		
		int M = N + 1;
		int MM = M * M;
		long[] min = new long[MM];
		long Inf = (long) 1e18;
		for(int i=0;i<MM;i++) min[i] = Inf;
		min[N * M + N] = 0;
		
		for(int bb = N; bb >= 0; bb--){
			for(int ww = N; ww >= 0; ww--){
				long cost = min[bb * M + ww];
				int done = N - bb + N - ww;
				
				// choose next w
				if(ww > 0){
					int ii = Winv[ww - 1];
					int lw = SW[ii][ww - 1];
					int lb = SB[ii][bb];
					int r = NN - done - lw - lb - 1;
					
					int npos = bb * M + (ww - 1);
					min[npos] = Math.Min(min[npos], cost + r);
				}
				
				// choose next b
				if(bb > 0){
					int ii = Binv[bb - 1];
					int lw = SW[ii][ww];
					int lb = SB[ii][bb - 1];
					int r = NN - done - lw - lb - 1;
					
					int npos = (bb - 1) * M + ww;
					min[npos] = Math.Min(min[npos], cost + r);
				}
			}
		}
		
		Console.WriteLine(min[0]);
		
		
	}
	int NN;
	
	int N;
	char[] C;
	int[] A;
	public Sol(){
		N = ri();
		NN = N * 2;
		C = new char[NN];
		A = new int[NN];
		for(int i=0;i<NN;i++){
			var ss = rsa();
			C[i] = ss[0][0];
			A[i] = int.Parse(ss[1]) - 1;
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
	public long Cost;
	public Pair(int p, long c) {
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