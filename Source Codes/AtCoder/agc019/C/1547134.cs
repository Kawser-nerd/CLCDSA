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
		
		if(X2 < X1){
			X1 *= -1;
			X2 *= -1;
			for(int i=0;i<N;i++) X[i] *= -1;
		}
		if(Y2 < Y1){
			Y1 *= -1;
			Y2 *= -1;
			for(int i=0;i<N;i++) Y[i] *= -1;
		}
		
		X2 -= X1;
		for(int i=0;i<N;i++) X[i] -= X1;
		
		Y2 -= Y1;
		for(int i=0;i<N;i++) Y[i] -= Y1;
		
		var L = new List<Pair>();
		int c = 0;
		for(int i=0;i<N;i++){
			if(InRange(X[i],0,X2) && InRange(Y[i],0,Y2)){
				L.Add(new Pair(X[i],Y[i],c));
				c++;
			}
		}
		
		L.Sort((p,q) => {
			var xc = p.X.CompareTo(q.X);
			return xc == 0 ? p.Y.CompareTo(q.Y) : xc;
		});
		
		int[] dp,route;
		int[] ys = L.Select(p => (int)p.Y).ToArray();
		LIS(ys, out dp, out route);

		int max = 0;
		for(int i=1;i<dp.Length;i++){
			if(dp[i] != int.MaxValue) max = i;
		}
		
		double ans = 100.0 * ((double) X2 + (double) Y2);
		if(max < (int)Math.Min(X2,Y2) + 1){
			ans -= max * 20;
			ans += 0.5 * Math.PI * 10 * max;
			Console.WriteLine(ans);
			return;
		}
		
		max--;
		ans -= max * 20;
		ans += 0.5 * Math.PI * 10 * max;
		ans -= 20;
		ans += Math.PI * 10;
		Console.WriteLine(ans);
	}
	
	void LIS(int[] a, out int[] dp, out int[] route){
		
		int n = a.Length;
		dp = new int[n+1];
		int[] dp2 = new int[n+1];
		route = new int[n];
		dp[0] = int.MinValue;
		dp2[0] = -1;
		for(int i=1;i<=n;i++){
			dp[i] = int.MaxValue;
			dp2[i] = -1;
		}
		
		for(int i=0;i<n;i++){
			int l = 0;
			int r = n + 1;
			while(r - l > 1){
				int c = (l + r) / 2;
				if(dp[c] < a[i]){
					l = c;
				} else {
					r = c;
				}
			}
			dp[r] = a[i];
			dp2[r] = i;
			route[i] = dp2[l];
		}
	}
	
	
	bool InRange(long t, long l, long r){
		return l <= t && t <= r;
	}
	
	class Pair{
		public long X;
		public long Y;
		public int Idx;
		public Pair(long x, long y, int idx){
			X = x; Y = y; Idx = idx;
		}
	}
	
	
	long X1,Y1,X2,Y2;
	int N;
	long[] X,Y;
	public Sol(){
		
		var  d = rla();
		X1 = d[0]; Y1 = d[1]; X2 = d[2]; Y2 = d[3];
		N = ri();
		X = new long[N];
		Y = new long[N];
		for(int i=0;i<N;i++){
			d = rla();
			X[i] = d[0]; Y[i] = d[1];
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