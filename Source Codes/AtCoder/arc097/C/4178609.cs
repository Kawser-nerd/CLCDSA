using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		Bit bit=new Bit(n*2);
		int[] b=new int[n+1],w=new int[n+1];
		string[] a=new string[n*2];
		int[] r=new int[n*2];
		for(int i = 0;i<n*2;i++) {
			a[i]=sc.S;
			r[i]=int.Parse((a[i].Split())[1]);
			if(a[i][0]=='B'){b[r[i]]=i;}
			else{w[r[i]]=i;}
		}
		long[,,] dp=new long[n+1,n+1,2];
		for(int i = 0;i<=n;i++) {
			bit=new Bit(n*2);
			if(i!=0){
				for(int j = 1;j<i;j++) {bit.Ud(b[j]+1,1);}
				dp[i,0,0]=dp[i-1,0,0]+b[i]-bit.Get(b[i]+1);
				bit.Ud(b[i]+1,1);
			}
			for(int j = 1;j<=n;j++) {
				dp[i,j,0]=dp[i,j-1,0]+w[j]-bit.Get(w[j]+1);
				if(i!=0){dp[i,j,0]=Math.Min(dp[i,j,0],dp[i-1,j,0]+b[i]-dp[i-1,j,1]);}
				if(j!=0){bit.Ud(w[j]+1,1);}
				if(i!=n){dp[i,j,1]=bit.Get(b[i+1]+1);}
			}
			bit.Clear();
		}
		Console.WriteLine("{0}",dp[n,n,0]);
	}
}
public class Bit{
	private int n;
	private long[] bit;
	public Bit(int n){
		this.n=n;
		bit=new long[n+1];
	}
	public void Ud(int a,long p){while(a<=n){bit[a]+=p;a+=a&-a;}}
	public long Get(int n){
		long a=0;
		while(n>0){a+=bit[n];n-=n&-n;}
		return a;
	}
	public long Get2(int n,int m){
		long a=0,b=0;
		while(n>m){a+=bit[n];n-=n&-n;}
		if(n==m){return a;}
		while(n!=m){b+=bit[m];m-=m&-m;}
		return a-b;
	}
	public void Clear(){bit=new long[n+1];}
}

class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
	public object[] Oa{get{return Console.ReadLine().Split();}}
}