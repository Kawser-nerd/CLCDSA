using System;
class Program{
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		Console.WriteLine("{0}",fu(s[1])-fu(s[0]-1));
	}
	static long fu(long q){
		string a=q.ToString();
		int n=a.Length;
		long[,,] dp=new long[n+1,2,2];
		dp[0,0,0]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					int lim=j==1?9:a[i]-'0';
					for(int d=0;d<lim+1;d++){dp[i+1,(j==1||d<lim)?1:0,(k==1||d==4||d==9)?1:0]+=dp[i,j,k];}
				}
			}
		}
		long ans=0;
		for(int j=0;j<2;j++){ans+=dp[n,j,1];}
		return ans;
	}
}