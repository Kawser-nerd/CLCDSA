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
		
		var h = new HashSet<long>();
		h.Add(0);
		for(int i=0;i<N;i++) h.Add(A[i]);
		var l = h.ToList();
		l.Sort();
		var dic = new Dictionary<long,int>();
		for(int i=0;i<l.Count;i++) dic.Add(l[i], i);
		
		
		long max = 0;
		List<int> pos = new List<int>();
		for(int i=0;i<N;i++){
			if(max < A[i]){
				pos.Add(i);
				max = A[i];
			}
		}
		
		var cntBT = new BIT(N);
		var totBT = new BIT(N);
		for(int i=0;i<N;i++){
			cntBT.Add(dic[A[i]] + 1, 1);
			totBT.Add(dic[A[i]] + 1, A[i]);
		}
		
		long total = A.Sum();
		long done = 0;
		long[] ans = new long[N];
		for(int i = pos.Count - 1; i > 0; i--){
			long del = (total - totBT.Sum(dic[A[pos[i - 1]]])) - A[pos[i-1]] * (N - cntBT.Sum(dic[A[pos[i - 1]]]));
			ans[pos[i]] = del - done;
			done = del;
		}
		ans[0] = total - done;
		Console.WriteLine(String.Join("\n",ans));
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

class BIT{
	int MM;
	int n;
	long[] bit;
	public BIT(int n_){
		n = n_;
		MM = 1 << 2;
		while(MM < n * 2) MM <<= 1;
		bit = new long[MM + 1];
	}
	//1-origin!!
	public void Add(int i, long x){
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