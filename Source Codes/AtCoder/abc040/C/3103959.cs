using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[] a=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] dp=new int[2];
		dp[1]=Math.Abs(a[0]-a[1]);
		for(int i=2;i<n;i++){dp[i&1]=Math.Min(Math.Abs(a[i-2]-a[i])+dp[i&1],Math.Abs(a[i-1]-a[i])+dp[(i-1)&1]);}
		Console.WriteLine("{0}",dp[(n-1)&1]);
	}
}