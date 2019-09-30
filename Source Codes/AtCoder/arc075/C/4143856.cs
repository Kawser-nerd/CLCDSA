using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		int[] a=new int[s[0]+1];
		long[][] b=new long[s[0]+1][];
		int[] c=new int[s[0]+1];
		b[0]=new long[2];
		for(int i=1;i<=s[0];i++){
			a[i]=sc.I;
			b[i]=new long[]{b[i-1][0]+a[i]-s[1],i};
		}
		Array.Sort(b,Ca);
		int p=1;
		long ans=0;
		c[b[0][1]]=1;
		for(int i=1;i<=s[0];i++){
			if(b[i][0]!=b[i-1][0]){p++;}
			c[b[i][1]]=p;
		}
		Bit bit=new Bit(p);
		bit.Ud(c[0],1);
		for(int i=1;i<=s[0];i++){
			ans+=bit.Get(c[i]);
			bit.Ud(c[i],1);
		}
		Console.WriteLine(ans);
	}
	static int Ca(long[] a,long[] b){
		if(a[0]>b[0]){return 1;}
		else if(a[0]<b[0]){return -1;}
		else{return 0;}
	}
}
public class Bit{
	private int n;
	private int[] bit;
	public Bit(int n){
		this.n=n;
		bit=new int[n+1];
	}
	public void Ud(int a,int p){while(a<=n){bit[a]+=p;a+=a&-a;}}
	public int Get(int n){
		int a=0;
		while(n>0){a+=bit[n];n-=n&-n;}
		return a;
	}
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
}