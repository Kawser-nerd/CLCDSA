using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		long ans=0;
		List<int[]> li=new List<int[]>();
		List<long[]> ho=new List<long[]>();
		long[,] a=new long[n,n];
		for(int i=0;i<n;i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			for(int j=i+1;j<n;j++){
				li.Add(new int[]{q[j],i,j});
			}
		}
		li.Sort((u,v)=>u[0]-v[0]);
		foreach(int[] i in li){
			if(a[i[1],i[2]]==0||a[i[1],i[2]]>i[0]){
				ans+=i[0];
				a[i[1],i[2]]=i[0];
				a[i[2],i[1]]=i[0];
			}
			else if(a[i[1],i[2]]<i[0]){
				ans=-1;
				break;
			}
			for(int j=0;j<n;j++){
				if(a[i[1],j]!=0&&j!=i[2]){ho.Add(new long[]{j,i[2],i[0]+a[i[1],j]});}
				if(a[j,i[2]]!=0&&j!=i[1]){ho.Add(new long[]{j,i[1],i[0]+a[j,i[2]]});}
			}
			foreach(long[] j in ho){
				if(a[j[0],j[1]]==0||a[j[0],j[1]]>j[2]){
					a[j[0],j[1]]=j[2];
					a[j[1],j[0]]=j[2];
				}
			}
			ho.Clear();
		}
		Console.WriteLine("{0}",ans);
	}
}