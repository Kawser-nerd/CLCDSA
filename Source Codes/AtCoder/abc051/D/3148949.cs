using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[,] dp=new int[s[0]+1,s[0]+1];
		string[,] h=new string[s[0]+1,s[0]+1];
		int[][] arr=new int[s[1]][];
		bool[] b=new bool[s[1]];
		int ans=0;

		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[0];j++){
				if(i!=j){dp[i,j]=int.MaxValue/2;}
			}
		}
		for(int i=0;i<s[1];i++){
			arr[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			dp[arr[i][0],arr[i][1]]=arr[i][2];
			h[arr[i][0],arr[i][1]]=i.ToString();
			dp[arr[i][1],arr[i][0]]=arr[i][2];
			h[arr[i][1],arr[i][0]]=i.ToString();
		}
		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[0];j++){
				for(int k=1;k<=s[0];k++){
					if(dp[j,k]>dp[j,i]+dp[i,k]){
						dp[j,k]=dp[j,i]+dp[i,k];
						h[j,k]=h[j,i]+" "+h[i,k];
					}
				}
			}
		}
		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[0];j++){
				if(h[i,j]!=null){
					int[] q=Array.ConvertAll(h[i,j].Split(),int.Parse);
					foreach(int k in q){b[k]=true;}
				}
			}
		}
		for(int i=0;i<s[1];i++){if(!b[i]){ans++;}}
		Console.WriteLine(ans);
	}
}