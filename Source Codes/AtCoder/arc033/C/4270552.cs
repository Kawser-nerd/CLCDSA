using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
static class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		Bit bit=new Bit(200000);
		var sb=new StringBuilder();
		for(int i = 0;i<n;i++) {
			int[] q=sc.Ia;
			if(q[0]==1){bit.Ud(q[1],1);}
			else{
				int lb=0,ub=200000,mid=0;
				while(ub-lb>1){
					mid=(ub+lb)/2;
					if(bit.Get(mid)>q[1]-1){ub=mid;}
					else{lb=mid;}
				}
				sb.Append(ub+"\n");
				bit.Ud(ub,-1);
			}
		}
		Console.Write(sb);
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
	public long Get2(int m,int n){
		long a=0,b=0;
		while(n>m){a+=bit[n];n-=n&-n;}
		if(n==m){return a;}
		while(n!=m){b+=bit[m];m-=m&-m;}
		return a-b;
	}
	public void Clear(){bit=new long[n+1];}
}

public class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}