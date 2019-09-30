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
		
		long[] max = new long[3*N];
		var SH = new SkewHeap<long>();
		long tot = 0;
		for(int i=0;i<N;i++){
			SH.Push(A[i]);
			tot += A[i];
		}
		max[N-1] = tot;
		
		for(int i=N;i<2*N;i++){
			tot += A[i];
			SH.Push(A[i]);
			var mm = SH.Top; SH.Pop();
			tot -= mm;
			max[i] = tot;
		}
		
		long[] min = new long[3*N];
		SH = new SkewHeap<long>();
		tot = 0;
		for(int i=3*N-1;i>=2*N;i--){
			SH.Push(-A[i]);
			tot += A[i];
		}
		min[2*N] = tot;
		for(int i=2*N-1;i>=N;i--){
			tot += A[i];
			SH.Push(-A[i]);
			var mm = SH.Top; SH.Pop();
			tot -= -mm;
			min[i] = tot;
		}
		
		long ans = long.MinValue;
		for(int i=N-1;i<2*N;i++){
			ans = Math.Max(ans,max[i] - min[i+1]);
		}
		
		Console.WriteLine(ans);
		
	}
	
	
	int N;
	long[] A;
	public Sol(){
		N = ri();
		A = rla();
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