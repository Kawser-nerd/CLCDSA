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
		
		int NN = N+2;
		double[][] dist = new double[NN][];
		for(int i=0;i<NN;i++) dist[i] = new double[NN];
		for(int i=0;i<NN;i++){
			for(int j=i+1;j<NN;j++){
				if((X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]) < (R[i]+R[j])*(R[i]+R[j]) ){
					dist[i][j] = dist[j][i] = 0;
				}else{
					dist[i][j] = dist[j][i] = Math.Sqrt((double)((X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]))) - (double)(R[i]+R[j]);
				}
			}
		}
		
//for(int i=0;i<NN;i++) Console.WriteLine(String.Join(" ",dist[i]));
		
		double[] Min = new double[NN];
		for(int i=1;i<NN;i++) Min[i] = 1e15;
		
		bool[] used=new bool[NN];
		int cntused=0;
		
		var SH=new SkewHeap<Pair>();
		SH.Push(new Pair(0,0));
		
		while(SH.Count>0){
			var p=SH.Top;SH.Pop();
			int now=p.Pos;
			if(used[now]){
				continue;
			}
			used[now]=true;
			Min[now]=p.Cost;
			cntused++;
			if(cntused == NN){
				break;
			}
			for(int j=0;j<NN;j++){
				if(Min[j]>Min[now]+dist[now][j]){
					Min[j] = Min[now]+dist[now][j];
					SH.Push(new Pair(j,Min[j]));
				}
			}
		}
		
		Console.WriteLine(Min[NN-1]);
	}
	int Xs,Ys,Xt,Yt;
	int N;
	long[] X,Y,R;
	public Sol(){
		
		var d = ria();
		Xs = d[0]; Ys = d[1];
		Xt = d[2]; Yt = d[3];
		
		N = ri();
		X = new long[N+2];
		Y = new long[N+2];
		R = new long[N+2];
		
		X[0] = Xs;X[N+1] = Xt;
		Y[0] = Ys;Y[N+1] = Yt;
		
		for(int i=0;i<N;i++){
			var dd = rla();
			X[i+1] = dd[0];
			Y[i+1] = dd[1];
			R[i+1] = dd[2];
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
	public double Cost;
	public Pair(int p, double c) {
		Pos = p; Cost = c;
	}
	public int CompareTo(Pair t) {
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