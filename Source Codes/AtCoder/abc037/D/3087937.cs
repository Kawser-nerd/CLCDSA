using System;
class Program{
	static long[,] dp;
	static int[][] arr;
	static long ans=0;
	static int[] s;
	const int mod=1000000007;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		arr=new int[s[0]][];
		dp=new long[s[0],s[1]];

		for(int i=0;i<s[0];i++){arr[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}
		for(int i=0;i<s[0];i++){for(int j=0;j<s[1];j++){fu(i,j);}}
		Console.WriteLine("{0}",ans);
	}
	static void fu(int a,int b){
		if(dp[a,b]==0){
			if(a!=0&&arr[a][b]>arr[a-1][b]){fu(a-1,b);dp[a,b]=(dp[a,b]+dp[a-1,b])%mod;}
			if(a!=s[0]-1&&arr[a][b]>arr[a+1][b]){fu(a+1,b);dp[a,b]=(dp[a,b]+dp[a+1,b])%mod;}
			if(b!=0&&arr[a][b]>arr[a][b-1]){fu(a,b-1);dp[a,b]=(dp[a,b]+dp[a,b-1])%mod;}
			if(b!=s[1]-1&&arr[a][b]>arr[a][b+1]){fu(a,b+1);dp[a,b]=(dp[a,b]+dp[a,b+1])%mod;}
			dp[a,b]++;
			ans=(ans+dp[a,b])%mod;
		}
	}
}