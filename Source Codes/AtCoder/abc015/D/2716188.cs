using System;
class Program{
	static void Main(){
		int w=int.Parse(Console.ReadLine());
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[][] arr=new int[s[0]+1][];
		int[,,] dp=new int[s[1]+1,s[0]+1,w+1];
		arr[0]=new int[2];
		for (int i=1;i<=s[0];i++){
			arr[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		}
		for (int i=1;i<=s[1];i++){
			for (int j=1;j<=s[0];j++){
				for (int k=1;k<=w;k++){
					if(k<arr[j][0]){dp[i,j,k]=dp[i,j-1,k];}
					else{dp[i,j,k]=Math.Max(dp[i,j-1,k],dp[i-1,j-1,k-arr[j][0]]+arr[j][1]);}
				}
			}
		}
		Console.WriteLine(dp[s[1],s[0],w]);
	}
}