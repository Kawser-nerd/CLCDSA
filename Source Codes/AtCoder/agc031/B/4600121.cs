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
		
		List<int> AA = new List<int>();
		AA.Add(A[0]);
		for(int i=1;i<N;i++) if(AA[AA.Count - 1] != A[i]) AA.Add(A[i]);
		A = AA.ToArray();
		N = A.Length;
		
		
		var di = new Dictionary<int, mlong>();
		for(int i=0;i<N;i++) if(!di.ContainsKey(A[i])) di.Add(A[i], 0);
		var di2 = new Dictionary<int, mlong>();
		for(int i=0;i<N;i++) if(!di2.ContainsKey(A[i])) di2.Add(A[i], 0);
		
		mlong[] dp = new mlong[N];
		dp[0] = 1;
		di[A[0]] = 1;
		di2[A[0]] = 1;
		for(int i=1;i<N;i++){
			dp[i] = dp[i-1] + di[A[i-1]] - di2[A[i-1]];
			
			di[A[i]] += dp[i];
			di2[A[i]] = dp[i];
		}
		mlong ans = dp[N-1] + di[A[N-1]] - di2[A[N-1]];
		Console.WriteLine(ans);
		
	}
	int N;
	int[] A;
	public Sol(){
		N = ri();
		A = new int[N];
		for(int i=0;i<N;i++) A[i] = ri();
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


struct mlong {
	
	const long mod = (long) 1e9 + 7;
	long V;
	
	public mlong(long _v = 0){
		V = _v;
	}
	
	public static mlong operator+(mlong a, mlong b){
		var v0 = a.V + b.V; if(v0 >= mod) v0 -= mod;
		return new mlong(v0);
	}
	public static mlong operator-(mlong a, mlong b){
		var v0 = mod + a.V - b.V; if(v0 >= mod) v0 -= mod;
		return new mlong(v0);
	}
	public static mlong operator*(mlong a, mlong b){
		var v0 = a.V * b.V; if(v0 >= mod) v0 %= mod;
		return new mlong(v0);
	}
	public static mlong operator/(mlong a, mlong b){
		var v0 = a.V * inv(b.V).V; if(v0 >= mod) v0 %= mod;
		return new mlong(v0);
	}
	
	
	public static mlong inv(long x){
		long a = 0, b = 0, c = 0;
		ExtGCD(x, mod, ref a, ref b, ref c);
		return (mlong)((a + mod) % mod);
	}
	
	public static void ExtGCD(long x, long y, ref long a, ref long b, ref long c){
		long r0 = x; long r1 = y;
		long a0 = 1; long a1 = 0;
		long b0 = 0; long b1 = 1;
		long q1, r2, a2, b2;
		while(r1 > 0){
			q1 = r0 / r1;
			r2 = r0 % r1;
			a2 = a0 - q1 * a1;
			b2 = b0 - q1 * b1;
			r0 = r1; r1 = r2;
			a0 = a1; a1 = a2;
			b0 = b1; b1 = b2;
		}
		c = r0;
		a = a0;
		b = b0;
	}
	
	public static mlong ModPow(mlong a, long k){
		if(k == 0) return (mlong) 1;
		if(a == 0) return (mlong) 0;
		mlong x = a;
		mlong ret = 1;
		while(k > 0){
			if(k % 2 == 1) ret *= x;
			x *= x;
			k >>= 1;
		}
		return ret;
	}
	
	
	public static bool operator == (mlong a, mlong b){
		 return a.Equals(b);
	}
	public static bool operator != (mlong a, mlong b){
		 return !(a == b);
	}
	
	public override bool Equals(System.Object obj){
		if(obj  ==  null) return false;
		mlong p  =  (mlong) obj;
		if((System.Object) p  ==  null) return false;
		return p.V  ==  V;
	}
	public override int GetHashCode(){
		return V.GetHashCode();
	}
	
	public static implicit operator mlong(long n){
		return new mlong(n);
	}
	public static implicit operator mlong(int n){
		return new mlong(n);
	}
	public static explicit operator long(mlong n){
		return n.V;
	}
	
	public override String ToString(){
		return V.ToString();
	}
	
	
}