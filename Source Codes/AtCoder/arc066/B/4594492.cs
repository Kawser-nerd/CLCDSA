using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		string s=Convert.ToString(sc.L,2);
		int n=s.Length;
		s=" "+s;
		long[,] dp=new long[n+1,3];
		dp[0,0]=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				dp[i,0]=(dp[i-1,0]+dp[i-1,1])%mod;
				dp[i,1]=dp[i-1,1]%mod;
				dp[i,2]=(dp[i-1,1]+dp[i-1,2]*3)%mod;
			}
			else{
				dp[i,0]=dp[i-1,0]%mod;
				dp[i,1]=(dp[i-1,0]+dp[i-1,1])%mod;
				dp[i,2]=(dp[i-1,1]*2+dp[i-1,2]*3)%mod;
			}
		}
		Console.WriteLine("{0}",(dp[n,0]+dp[n,1]+dp[n,2])%mod);
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