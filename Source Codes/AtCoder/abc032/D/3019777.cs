using System;
class Program{
	static int[][] arr;
	static long[] r;
	static int[] s;
	static long ans=0;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		arr=new int[s[0]+1][];
		r=new long[s[0]+2];
		
		long v=0,m=0;
		for(int i=1;i<=s[0];i++){
			arr[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			v=Math.Max(v,arr[i][0]);
			m+=arr[i][0];
		}
		
		if(s[0]<=30){
			for(int i=s[0];i>0;i--){r[i]=arr[i][0]+r[i+1];}
			fu(1,0,0);
		}
		else if(v<=1000){
			long[,] dp=new long[s[0]+1,m+1];
			for(int i=1;i<=m;i++){
				dp[0,i]=s[1]+1;
			}
			for(int i=1;i<=s[0];i++){
				for(int j=1;j<=m;j++){
					if(j>=arr[i][0]){
						dp[i,j]=Math.Min(arr[i][1]+dp[i-1,j-arr[i][0]],dp[i-1,j]);
					}
					else{dp[i,j]=dp[i-1,j];}
					if(j>=arr[i][0]){}
				}
			}
			for(long i=m;i>=0;i--){
				if(dp[s[0],i]<=s[1]){ans=i;break;}
			}
		}
		else{
			long[,] dp=new long[s[0]+1,s[1]+1];
			for(int i=1;i<=s[0];i++){
				for(int j=1;j<=s[1];j++){
					if(j>=arr[i][1]){
						dp[i,j]=Math.Max(dp[i-1,j],dp[i-1,j-arr[i][1]]+arr[i][0]);
					}
					else{dp[i,j]=dp[i-1,j];}
				}
			}
			ans=dp[s[0],s[1]];
		}
		Console.WriteLine("{0}",ans);
	}
	static void fu(int a,long b,long c){
		if(a>s[0]){ans=Math.Max(ans,b);}
		else if(ans<b+r[a]){
			if(c+arr[a][1]<=s[1]){fu(a+1,b+arr[a][0],c+arr[a][1]);}
			fu(a+1,b,c);
		}
	}
}