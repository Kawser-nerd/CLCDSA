using System;
using System.Collections.Generic;
class Program{
	static long[] s;
	static long[] kr,kg,kz;
	static List<long>[] arr;
	static void Main(){
		long n=long.Parse(Console.ReadLine());
		s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long h=long.Parse(Console.ReadLine());
		arr=new List<long>[n+1];
		kr=new long[n+1];
		kg=new long[n+1];
		kz=new long[n+1];
		for(long i=1;i<=n;i++){arr[i]=new List<long>();kr[i]=128;kg[i]=128;kz[i]=0;}
		kg[s[1]]=0;kz[s[1]]=1;

		for(long i=0;i<h;i++){
			long[] q=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
			arr[q[0]].Add(q[1]);
			arr[q[1]].Add(q[0]);
		}
		fu(s[0],0);
		Console.WriteLine(kz[s[0]]%1000000007);
	}
	static void fu(long b,long k){
		if(b==s[1]){
			if(kr[b]>k){kr[b]=k;}
		}
		else if(kr[b]>k){
			kr[b]=k;
			kz[b]=0;
			foreach(long i in arr[b]){
				fu(i,k+1);
				if(kg[b]>kg[i]+1){
					kg[b]=kg[i]+1;
					kz[b]=kz[i];
				}
				else if(kg[b]==kg[i]+1){
					kz[b]+=kz[i];
				}
			}
		}
	}
}