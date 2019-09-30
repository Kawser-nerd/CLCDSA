using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] a=new int[s[0]+1];
		int[,,] dp=new int[s[0]+1,s[0]+1,2];
		int ans=0;
		for(int i=1;i<=s[0];i++){
			a[i]=a[i-1]+int.Parse(Console.ReadLine());
			for(int j=i;j>0;j--){
				if(i==1){dp[i,1,0]=1;dp[i,1,1]=Math.Min(a[i],s[1]);break;}
				double d=1.0*dp[i-1,j-1,0]/a[i-1];
				dp[i,j,0]=(int)(d==Math.Ceiling(d*a[i])/a[i]?Math.Ceiling(d*a[i])+1:Math.Ceiling(d*a[i]));
				dp[i,j,0]=dp[i-1,j,0]!=0?Math.Min(dp[i,j,0],dp[i-1,j,0]):dp[i,j,0];
				dp[i,j,1]=dp[i-1,j-1,1]+(a[i]-a[i-1])-(dp[i-1,j-1,1]==a[i-1]?1:0);
				dp[i,j,1]=dp[i-1,j,0]!=0?dp[i-1,j,1]+(a[i]-a[i-1]):dp[i,j,1];
				dp[i,j,1]=Math.Min(dp[i,j,1],s[1]);
			}
		}
		for(int j=s[0];j>0;j--){
			if(dp[s[0],j,0]<=dp[s[0],j,1]&&dp[s[0],j,1]==s[1]){ans=j;break;}
		}
		Console.WriteLine(ans);
	}
}