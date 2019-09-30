using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
static class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		int[] h=new int[26];
		int[] p=new int[s[1]];
		int l=0,m=1<<s[1];
		for(int i = 0;i<s[1];i++) {
			string[] q=sc.Sa;
			h[q[0].ToCharArray()[0]-'A']=i;
			p[i]=int.Parse(q[1]);
			if(i==s[1]-1){l=q[0].ToCharArray()[0]-'A';}
		}
		string b=sc.S;
		int[,] dp=new int[m,s[1]];
		for(int i=0;i<m;i++){
			for(int j=0;j<s[1];j++){dp[i,j]=int.MinValue;}
		}
		for(int i=0;i<b.Length;i++){
			int z=h[b[i]-'A'],v=(1<<z)&(m-1);
			for(int j=v;j<m;j=(j+1)|v){
				int q=int.MinValue;
				for(int k=0;k<s[1];k++){
					if((j&(1<<k))==0){continue;}
					if(dp[j,k]!=int.MinValue){
						if(z!=k){q=Math.Max(q,dp[j,k]+p[z]);}
						else{q=Math.Max(q,dp[j,k]+s[2]+p[z]);}
					}
					if((j&v)!=0&&((j&(~v))&(1<<k))!=0&&dp[j&(~v),k]!=int.MinValue){q=Math.Max(q,dp[j&(~v),k]+p[z]);}
				}
				dp[j,z]=Math.Max(dp[j,z],q);
			}
			dp[1<<z,z]=Math.Max(dp[1<<z,z],p[z]);
		}
		int ans=0;
		for(int i=0;i<m;i++){
			int q=i==m-1?s[3]:0;
			for(int j=0;j<s[1];j++){
				if(dp[i,j]!=int.MinValue){ans=Math.Max(ans,dp[i,j]+q);}
			}
		}
		Console.WriteLine("{0}",ans);
	}
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