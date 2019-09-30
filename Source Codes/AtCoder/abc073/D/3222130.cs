using System;
using System.Collections.Generic;
class Program{
	static bool[] b;
	static int[] arr,s,r;
	static long ans=long.MaxValue,k=0;
	static long[,] dp;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		r=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		b=new bool[s[2]];
		arr=new int[s[2]];
		dp=new long[s[0]+1,s[0]+1];
		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[0];j++){
				if(i!=j){dp[i,j]=long.MaxValue/2;}
			}
		}
		for(int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			dp[q[0],q[1]]=q[2];
			dp[q[1],q[0]]=q[2];
		}
		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[0];j++){
				for(int k=1;k<=s[0];k++){
					dp[j,k]=Math.Min(dp[j,k],dp[j,i]+dp[i,k]);
				}
			}
		}
		fu1(0,0);
		Console.WriteLine("{0}",ans);
	}
	static void fu1(int a,int m){
		for(int i=0;i<s[2];i++){
			if(!b[i]){
				if(a!=0){k+=dp[m,r[i]];}
				if(a==s[2]-1){ans=Math.Min(ans,k);}
				else{
					b[i]=true;
					fu1(a+1,r[i]);
					b[i]=false;
				}
				if(a!=0){k-=dp[m,r[i]];}
			}
		}
	}
}