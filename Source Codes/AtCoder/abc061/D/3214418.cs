using System;
using System.Collections.Generic;
class Program{
	static List<long>[] li;
	static int[] hf;
	static int k=0;
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long[] h=new long[s[0]+1];
		hf=new int[s[0]+1];
		for(int i=1;i<=s[0];i++){h[i]=long.MinValue;}
		h[1]=0;
		long[][] arr=new long[s[1]][];
		for(int i=0;i<s[1];i++){arr[i]=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}

		int l=0,z=0;
		bool b=true;
		while(b&&l<=s[0]){
			l++;
			b=false;
			for(int i=0;i<s[1];i++){
				if(h[arr[i][0]]!=long.MinValue&&h[arr[i][1]]<h[arr[i][0]]+arr[i][2]){
					h[arr[i][1]]=h[arr[i][0]]+arr[i][2];
					b=true;
					if(l==s[0]){hf[arr[i][1]]=1;z++;}
				}
			}
		}
		if(z>0){
			li=new List<long>[s[0]+1];
			for(int i=1;i<=s[0];i++){li[i]=new List<long>();}
			for(int i=0;i<s[1];i++){li[arr[i][1]].Add(arr[i][0]);}
			fu(s[0]);
		}
		Console.WriteLine("{0}",k>0?"inf":h[s[0]].ToString());
	}
	static void fu(long n){
		k+=hf[n];
		hf[n]=2;
		for(int i=0;i<li[n].Count;i++){
			if(hf[li[n][i]]<2){fu(li[n][i]);}
		}
	}
}