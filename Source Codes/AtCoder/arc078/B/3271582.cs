using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		List<int>[] arr=new List<int>[n+1];
		int[] h=new int[n+1],z=new int[2];
		for(int i=1;i<=n;i++){arr[i]=new List<int>();}
		for(int i=1;i<n;i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			arr[q[0]].Add(q[1]);
			arr[q[1]].Add(q[0]);
			h[i]=-1;
		}
		List<int>[] li=new List<int>[2];
		li[0]=new List<int>();
		li[1]=new List<int>();
		li[0].Add(1);
		li[1].Add(n);
		h[1]=0;h[n]=1;
		z[0]=1;z[1]=1;
		int t=0;
		while(li[t].Count>0){
			int k=li[t].Count;
			while(k>0){
				for(int i=0;i<arr[li[t][0]].Count;i++){
					if(h[arr[li[t][0]][i]]==-1){
						li[t].Add(arr[li[t][0]][i]);
						h[arr[li[t][0]][i]]=t;
						z[t]++;
					}
				}
				li[t].RemoveAt(0);
				k--;
			}
			if(li[t^1].Count>0){t^=1;}
		}
		Console.WriteLine("{0}",z[0]>z[1]?"Fennec":"Snuke");
	}
}