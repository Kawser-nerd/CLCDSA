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
		
		for(int i=0;i<N;i++) A[i] -= K;
		long[] sum = new long[N+1];
		for(int i=0;i<N;i++) sum[i+1] = sum[i] + A[i];
		long Inf = (long) 1e18;
		
		HashSet<long> H = new HashSet<long>();
		H.Add(-Inf);
		H.Add(Inf);
		H.Add(0);
		foreach(var v in sum) H.Add(v);
		var L = H.ToList();
		L.Sort();
		var dic = new Dictionary<long,int>();
		for(int i=0;i<L.Count;i++) dic.Add(L[i], i);
		
		int NN = N * 2;
		var BT = new BIT(NN);
		for(int i=1;i<=N;i++) BT.Add(dic[sum[i]] + 1,1);
		
		long ans = 0;
		ans += N - BT.Sum(dic[L[dic[0]]]);
		BT.Add(dic[sum[1]] + 1, -1);
		BT.Add(dic[-Inf] + 1, 1);
		for(int i=1;i<N;i++){
			ans += N - BT.Sum(dic[L[dic[sum[i]]]]);
			BT.Add(dic[sum[i+1]] + 1, -1);
			BT.Add(dic[-Inf] + 1, 1);
		}
		
		Console.WriteLine(ans);
	}
	
	int N;
	long K;
	long[] A;
	public Sol(){
		var d = ria();
		N = d[0]; K = d[1];
		A = new long[N];
		for(int i=0;i<N;i++) A[i] = rl();
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

class BIT{
	int MM;
	int n;
	long[] bit;
	public BIT(int n_){
		n = n_;
		MM = 1;
		while(MM < n * 2) MM <<= 1;
		bit = new long[MM + 1];
	}
	//1-origin!!
	public void Add(int i,long x){
		while(i <= n){
			bit[i] += x;
			i += (i&-i);
		}
	}
	
	// i=>sum(a_1,...,a_i)
	// i=0 -> return 0;
	public long Sum(int i){
		long s = 0;
		while(i > 0){
			s += bit[i];
			i -= (i&-i);
		}
		return s;
	}
}