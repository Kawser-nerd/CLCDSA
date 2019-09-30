using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		long[] s=sc.La;
		long[] a=sc.La;
		long ans=0,b=s[1],c=0,z=1;
		int m=s[1]==0?0:(int)Math.Log(s[1],2);
		int[] h=new int[m+1];
		for(int i = 0;i<s[0];i++) {
			for(int j = 0;j<=m;j++){
				if((a[i]&(z<<j))!=0){h[j]++;}
			}
		}
		for(int i = 0;i<=m;i++) {
			if(h[i]*2<s[0]){long v=z<<i;c|=v;}
		}
		if(b>=c){
			for(int i = 0;i<s[0];i++) {ans+=a[i]^c;}
		}
		else{
			for(int i = 0;i<s[0];i++) {ans+=a[i]^(b&c);}
			for(int i = m;i>=0;i--) {
				if((b&(z<<i))>0){
					long q=b&(~((z<<(i+1))-1)),o=0;
					q|=(z<<i)-1;
					q&=c;
					for(int j = 0;j<s[0];j++) {o+=a[j]^q;}
					ans=Math.Max(ans,o);
				}
			}
		}
		Console.WriteLine("{0}",ans);
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