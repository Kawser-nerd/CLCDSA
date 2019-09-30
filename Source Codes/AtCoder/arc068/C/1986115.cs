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
		
		
		Pair[] P = new Pair[N];
		for(int i=0;i<N;i++) P[i] = new Pair(i, R[i] - L[i] + 1);
		Array.Sort(P, (p,q) => p.Len.CompareTo(q.Len));
		
		var ST = new SegTree(M+1);
		int bigger = N;
		int ptr = 0;
		var ans = new List<long>();
		for(int i=1;i<=M;i++){
			long cnt = 0;
			while(ptr < N && P[ptr].Len <= i){
				ST.AddRange(L[P[ptr].Idx] , R[P[ptr].Idx] + 1, 1);
				bigger--;
				ptr++;
			}
			cnt += bigger;
			for(int j=0;j<=M;j+=i){
				cnt += ST.At(j);
			}
			ans.Add(cnt);
		}
		
		Console.WriteLine(String.Join("\n",ans));
		
	}
	
	class Pair{
		public int Idx, Len;
		public Pair(int idx, int len){
			Idx = idx; Len = len;
		}
	}
	
	
	int N,M;
	int[] L,R;
	public Sol(){
		var d = ria();
		N = d[0]; M = d[1];
		L = new int[N];
		R = new int[N];
		for(int i=0;i<N;i++){
			d = ria();
			L[i] = d[0]; R[i] = d[1];
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


class SegTree{
	//segment Tree 
	// range add / point value query
	// 0-origin
	protected long[] Data;	
	protected long Inf;	
	protected int N;		
	protected int n;		
	
	public SegTree(int n_){
		N = n_; Inf = (long)1e18;
		n = 1;
		while(n < n_) n *= 2;
		Data = new long[2 * n - 1];
		for(int i=0; i < 2 * n - 1; i++) Data[i] = 0;
	}
	
	//	   0
	//	 1   2
	//	3 4 5 6
	
	public long At(int k){
		long ret = 0;
		k += n - 1;
		ret = Data[k];
		while(k > 0){
			k = (k - 1) / 2;
			ret += Data[k];
		}
		return ret;
	}
	
	public void AddRange(int a, int b, long v){
		Query(a, b, v, 0, 0, n);
	}
	
	//Range Sum; [a,b)
	public void Query(int a, int b, long v, int k, int l, int r){
		if(r <= a || b <= l) return;
		if(a <= l && r <= b) {
			Data[k] += v;
			return;
		}
		Query(a, b, v, k * 2 + 1, l, (l + r) / 2);
		Query(a ,b, v, k * 2 + 2, (l + r) / 2, r);
		return;
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