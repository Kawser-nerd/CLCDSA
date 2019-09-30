using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		long[,,,,] dp=new long[n+1,4,4,4,2];
		dp[1,0,0,0,0]=1;
		dp[1,0,0,1,0]=1;
		dp[1,0,0,2,0]=1;
		dp[1,0,0,3,0]=1;
		long ans=0;
		for(int i = 2;i<=n;i++) {
			for(int j = 0;j<4;j++) {
				for(int k = 0;k<4;k++) {
					for(int l = 0;l<4;l++) {
						if(j==1&&k==2&&l==3){continue;}
						if(j==1&&k==3&&l==2){continue;}
						if(j==2&&k==1&&l==3){continue;}
						for(int m = 0;m<4;m++) {
							if(j==0&&k==2&&l==3&&m==1){continue;}
							if(j==2&&k==0&&l==3&&m==1){continue;}
							if(j==2&&k==2&&l==3&&m==1){continue;}
							dp[i,j,k,l,0]+=dp[i-1,m,j,k,0];
							dp[i,j,k,l,0]%=mod;
						}
						if(i==n){ans=(ans+dp[i,j,k,l,0])%mod;}
					}
				}
			}
		}
		Console.WriteLine(ans);
	}
}

public class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public int[] Ia2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}