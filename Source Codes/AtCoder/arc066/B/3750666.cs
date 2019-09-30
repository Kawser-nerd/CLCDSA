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
	const long mod = (long) 1e9 + 7;
	public void Solve(){
		
		
		int M = 63;
		int[] B = new int[M];
		for(int i=0;i<M;i++){
			B[i] = (int)((N >> i) & 1);
		}
		
		mlong[][] dp1 = new mlong[M][];
		mlong[][] dp2 = new mlong[M][];
		for(int i=0;i<M;i++){
			dp1[i] = new mlong[2];
			dp2[i] = new mlong[2];
		}
		
		dp1[0][0] = 1;
		dp2[0][0] = 1;
		
		for(int i=0;i<M-1;i++){
			dp1[i + 1][0] += dp1[i][0];	// (0, 0);
			dp1[i + 1][0] += dp1[i][0];	// (1, 0);
			dp1[i + 1][1] += dp1[i][0];	// (1, 1);
			dp1[i + 1][0] += dp1[i][1];	// (0, 0);
			dp1[i + 1][1] += dp1[i][1];	// (1, 0);
			dp1[i + 1][1] += dp1[i][1];	// (1, 1);
			
			if(B[i] == 1){
				dp2[i + 1][0] += dp1[i][0];	// (0, 0);
				dp2[i + 1][1] += dp1[i][0];	// (1, 1);
				dp2[i + 1][1] += dp1[i][1];	// (1, 0);
			}
			
			if(B[i] == 1){
				dp2[i + 1][0] += dp2[i][0];	// (1, 0);
				dp2[i + 1][0] += dp2[i][1];	// (0, 0);
				dp2[i + 1][1] += dp2[i][1];	// (1, 1);
			}
			if(B[i] == 0){
				dp2[i + 1][0] += dp2[i][0];	// (0, 0);
				dp2[i + 1][1] += dp2[i][0];	// (1, 1);
				dp2[i + 1][1] += dp2[i][1];	// (1, 0);
			}
		}
		
		Console.WriteLine(dp2[M-1][0]);
		
	}
	long N;
	public Sol(){
		N = rl();
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