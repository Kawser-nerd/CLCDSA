using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[,] dp=new int[s[0]+1,s[0]+1];
		int[][] arr=new int[s[1]][];
		int ans=0;

		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[0];j++){
				if(i!=j){dp[i,j]=int.MaxValue/2;}
			}
		}
		for(int i=0;i<s[1];i++){
			arr[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			dp[arr[i][0],arr[i][1]]=arr[i][2];
			dp[arr[i][1],arr[i][0]]=arr[i][2];
		}
		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[0];j++){
				for(int k=1;k<=s[0];k++){
					dp[j,k]=Math.Min(dp[j,k],dp[j,i]+dp[i,k]);
				}
			}
		}
		for(int i=0;i<s[1];i++){
			if(dp[arr[i][0],arr[i][1]]<arr[i][2]){ans++;}
		}
		Console.WriteLine(ans);
	}
}