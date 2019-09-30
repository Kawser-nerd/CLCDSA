using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static long ans=0;
	static long[] h=new long[5];
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		for(int i=0;i<n;i++){
			string s=Console.ReadLine();
			if(s[0]=='M'){h[0]++;}
			else if(s[0]=='A'){h[1]++;}
			else if(s[0]=='R'){h[2]++;}
			else if(s[0]=='C'){h[3]++;}
			else if(s[0]=='H'){h[4]++;}
		}
		fu(0,0,1);
		Console.WriteLine(ans);
	}
	static void fu(int n,int a,long b){
		if(n==3){ans+=b;}
		else{
			for(int i=a;i<5;i++){
				if(h[i]>0){fu(n+1,i+1,b*h[i]);}
			}
		}
	}
}