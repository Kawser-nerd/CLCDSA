using System;
using System.Collections.Generic;
class Program{
	static List<int> li=new List<int>();
	static int[][] arr=new int[5][];
	static int[] n=new int[26];
	static int[] dp=new int[1<<25];
	static void Main(){
		for(int i=0;i<26;i++){n[i]=-1;}
		for(int i=0;i<5;i++){
			arr[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			for(int j=0;j<5;j++){
				if(arr[i][j]==0){li.Add(i*5+j);}
				else{n[arr[i][j]]=i*5+j;}
			}
		}
		dp[0]=1;
		for(int i=0;i<(1<<25)-1;i++){if(dp[i]>0){
			int b=fb(i)+1;
			if(n[b]==-1){
				for(int j=0;j<li.Count;j++){
					if((i&(1<<li[j]))==0){
						if(li[j]%5!=0&&li[j]%5!=4&&(((i>>(li[j]-1))&5)%5)!=0){}
						else if(li[j]/5!=0&&li[j]/5!=4&&(((i>>(li[j]-5))&1025)%5)!=0){}
						else{dp[i+(1<<li[j])]=(dp[i+(1<<li[j])]+dp[i])%1000000007;}
					}
				}
			}
			else if((i&(1<<n[b]))==0){
				if(n[b]%5!=0&&n[b]%5!=4&&(((i>>(n[b]-1))&5)%5)!=0){}
				else if(n[b]/5!=0&&n[b]/5!=4&&(((i>>(n[b]-5))&1025)%5)!=0){}
				else{dp[i+(1<<n[b])]+=(dp[i+(1<<n[b])]+dp[i])%1000000007;}
			}
		}}
		Console.WriteLine(dp[(1<<25)-1]);
	}
	static int fb(long bits){
	    bits=(bits&0x55555555)+(bits>>1&0x55555555);
	    bits=(bits&0x33333333)+(bits>>2&0x33333333);
	    bits=(bits&0x0f0f0f0f)+(bits>>4&0x0f0f0f0f);
	    bits=(bits&0x00ff00ff)+(bits>>8&0x00ff00ff);
	    return (int)((bits&0x0000ffff)+(bits>>16&0x0000ffff));
	}
}