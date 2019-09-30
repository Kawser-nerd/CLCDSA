using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] a=new int[s[0]+1];
		long[] dp=new long[s[0]+1];
		
		for (int i=1;i<=s[0];i++){a[i]=int.Parse(Console.ReadLine());}
		dp[0]=1;
		int[] b=new int[s[1]+1];
		b[0]=1;
		int h=0;
		long c=0;
		
		for (int i=1;i<=s[0];i++){
			b[a[i]]++;
			if(b[a[i]]>1){
				b[a[h]]--;
				c=(c-dp[h]);
				h++;
				while(b[a[h]]<2){
					b[a[h]]--;
					c=(c-dp[h]);
					h++;
				}
			}
			c=(c+dp[i-1]);
			dp[i]=c%1000000007;
		}
		Console.WriteLine(dp[s[0]]);
	}
}