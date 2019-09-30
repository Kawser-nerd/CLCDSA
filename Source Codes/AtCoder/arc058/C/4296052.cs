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
		int m=1<<(s[1]+s[2]+s[3]);
		long ans=0;
		long[][] dp=new long[s[0]+1][],dp2=new long[s[0]+1][];
		dp[0]=new long[m];
		dp2[0]=new long[m];
		dp[0][0]=1;
		for(int i=0;i<s[0];i++){
			dp[i+1]=new long[m];
			dp2[i+1]=new long[m];
			for(int j=0;j<m;j++){
				if(dp[i][j]+dp2[i][j]==0){continue;}
				for(int k=1;k<=10;k++){
					int q=((j<<k)|(1<<(k-1)))&(m-1);
					if(((q&(1<<(s[3]-1)))!=0&&(q&(1<<(s[3]+s[2]-1)))!=0&&(q&(1<<(s[3]+s[2]+s[1]-1)))!=0)){
						dp2[i+1][q]=(dp2[i+1][q]+dp[i][j])%mod;
					}
					else{
						dp[i+1][q]=(dp[i+1][q]+dp[i][j])%mod;
					}
					dp2[i+1][q]=(dp2[i+1][q]+dp2[i][j])%mod;
				}
			}
		}
		for(int j=0;j<m;j++){ans=(ans+dp2[s[0]][j])%mod;}
		Console.WriteLine(ans);
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