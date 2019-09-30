using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static int[] s;
	static int[][] a;
	static int[] dp;
	static int ans=int.MaxValue;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		a=new int[s[0]][];
		dp=new int[1024];
		for(int i=0;i<s[0];i++){a[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}
		fu(0,0,0);
		Console.WriteLine(ans);
	}
	static void fu(int p,int t,int b){
		if(dp[b]==0){dp[b]=p;}
		else if(dp[b]==p){return;}
		if(t>=ans){return;}
		if(p>=s[1]){ans=t;}
		else{
			for(int i=0;i<s[0];i++){
				if((b&(1<<i))==0){
					fu(p+a[i][1]+a[i][0]*(i+1)*100,t+a[i][0],b|(1<<i));
				}
			}
			
			for(int i=s[0]-1;i>=0;i--){
				if((b&(1<<i))==0){
					if(dp[b|(1<<i)]>=s[1]){
						int q=1;
						while(q!=a[i][0]&&t+q<ans){
							p+=(i+1)*100;
							if(p>=s[1]){ans=t+q;break;}
							q++;
						}
					}
					break;
				}
			}
		}
	}
}