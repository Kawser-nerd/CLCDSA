using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] g=new int[s[0]+1];
		for(int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			g[q[1]-1]|=1<<(q[0]-1);
		}
		long[] dp=new long[1<<s[0]];
		dp[0]=1;
		for(int i=0;i<(1<<s[0]);i++){
			for(int j=0;j<s[0];j++){
				if(((1<<j)&i)==0&&(i&g[j])==g[j]){dp[i|(1<<j)]+=dp[i];}
			}
		}
		Console.WriteLine("{0}",dp[(1<<s[0])-1]);
	}
}