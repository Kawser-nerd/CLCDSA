using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[][] arr=new int[s[0]+1][];
		int m1=0,m2=0,ans=int.MaxValue;
		for(int i=1;i<=s[0];i++){
			arr[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			m1+=arr[i][0];
			m2+=arr[i][1];
		}
		int[,,] dp=new int[s[0]+1,m1+1,m2+1];
		for(int i=0;i<=s[0];i++){
			for(int j=0;j<=m1;j++){
				for(int k=0;k<=m2;k++){dp[i,j,k]=9999;}
			}
			dp[i,0,0]=0;
		}
		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=m2;k++){
					if(j>=arr[i][0]&&k>=arr[i][1]){dp[i,j,k]=Math.Min(dp[i-1,j-arr[i][0],k-arr[i][1]]+arr[i][2],dp[i-1,j,k]);}
					else{dp[i,j,k]=dp[i-1,j,k];}
				}
			}
		}
		for(int i=s[1],j=s[2];i<=m1&&j<=m2;i+=s[1],j+=s[2]){ans=Math.Min(ans,dp[s[0],i,j]);}
		ans=ans==9999?-1:ans;
		Console.WriteLine("{0}",ans);
	}
}