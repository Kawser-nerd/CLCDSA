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
		modComb.Init(200020);
		long mod = (long)1e9+7;
		long ans = 0;
		
		for(int j=B;j<W;j++){
			long a = modComb.nCrMod(j+(H-A-1),(H-A-1));
			long b = modComb.nCrMod(W-j-1+(A-1),(A-1));
			
			long c = a * b % mod;
			ans += c;
			if(ans >= mod) ans -= mod;
		}
		Console.WriteLine(ans);
	}
	int H,W,A,B;
	public Sol(){
		var d = ria();
		H = d[0];
		W = d[1];
		A = d[2];
		B = d[3];
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
class modComb{
	public static long mod=(long)(1e9+7);
	public static long nCrMod(long n,long r){
		if(n<r)return 0;
		if(n<0)return 0;
		if(r<0)return 0;
		if(n==0||r==n||r==0)return 1;
		long a=FactorialMod(n);
		long b=InvMod(FactorialMod(r));
		long c=InvMod(FactorialMod(n-r));
		long ans=(((a*b)%mod)*c)%mod;
		return ans;
	}
	
	static long[] FM;
	static public void Init(int N){
		FM = new long[N];
		FM[0] = FM[1] = 1;
		for(int i=2;i<N;i++){
			FM[i] = FM[i-1] *(long)(i);
			if(FM[i]>=mod)FM[i] %= mod;
		}
	}
	public static long FactorialMod(long n){
		
		if(FM[(int)n]!=0)return FM[(int)n];

		if(n<2)return FM[(int)n]=1;
		long ret=n*FactorialMod(n-1);
		ret%=mod;
		return FM[(int)n]=ret;
	}
	
	static long PowMod(long n,long k){
		
		if(k==0)return 1;
		if(n==0)return 0;
		long ret=1;
		long x=n;
		while(k>0){
			if((k&1)==1){ret*=x;ret%=mod;}
			x*=x;x%=mod;
			k>>=1;
		}
		return ret;
		
	}

	public static long InvMod(long n){
		return PowMod(n,mod-2);
	}
	

}