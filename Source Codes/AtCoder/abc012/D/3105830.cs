using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[][] arr=new int[s[1]][];
		int[,] dp=new int[s[0]+1,s[0]+1];
		int ans=int.MaxValue;
		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[0];j++){
				if(i!=j){dp[i,j]=int.MaxValue/2;}
			}
		}
		for(int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			dp[q[0],q[1]]=q[2];
			dp[q[1],q[0]]=q[2];
		}
		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[0];j++){
				for(int k=1;k<=s[0];k++){
					dp[j,k]=Math.Min(dp[j,k],dp[j,i]+dp[i,k]);
				}
			}
		}
		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[0];j++){
				dp[i,0]=Math.Max(dp[i,0],dp[i,j]);
			}
			ans=Math.Min(ans,dp[i,0]);
		}
		Console.WriteLine("{0}",ans);
	}
}