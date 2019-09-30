using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	const long o=1;
	static Bit bit;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia,a=sc.Ia;
		long ans=0;
		int[][] h=new int[s[0]][];
		for(int i = 0;i<s[0];i++) {h[i]=new int[]{a[i],i+1};}
		Array.Sort(h,(u,v)=>u[0]-v[0]);
		bit=new Bit(s[0]);
		var hs=new Dictionary<string,int>();
		bit.Ud(h[0][1],1);
		ans=h[s[2]-1][0]-h[0][0];
		for(int i = 1;i<=s[0]-s[2];i++) {
			if(h[i+s[2]-1][0]-h[i][0]<ans){
				int p=0;
				for(int j = i;;j++) {
					long q=bit.Get(h[j][1]);
					int l=Fu(0,h[j][1],q)+(q==0?0:1),r=Fu(h[j][1],s[0]+1,q+1)-1;
					string t=l+" "+r;
					
					if(r-l-(hs.ContainsKey(t)?hs[t]:0)+1>=s[1]){
						if(j-i-p+1==s[2]){
							ans=h[i+s[2]-1+p][0]-h[i][0];
							break;
						}
					}
					else{
						p++;
						if(i+s[2]-1+p>=s[0]){break;}
						else if(h[i+s[2]-1+p][0]-h[i][0]>=ans){break;}
					}
					if(hs.ContainsKey(t)){hs[t]++;}
					else{hs.Add(t,1);}
				}
				hs.Clear();
			}
			bit.Ud(h[i][1],1);
		}
		Console.WriteLine("{0}",ans);
	}
	static int Fu(int lb,int ub,long q){
		int mid=0;
		while(ub-lb>1){
			mid=(ub+lb)/2;
			if(bit.Get(mid)>=q){ub=mid;}
			else{lb=mid;}
		}
		return ub;
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