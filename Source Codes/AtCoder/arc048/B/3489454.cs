using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		long n=long.Parse(Console.ReadLine());
		var hs=new SortedDictionary<int,int[]>();
		int[][] arr=new int[n][];
		for(int i=0;i<n;i++){
			arr[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			if(!hs.ContainsKey(arr[i][0])){hs.Add(arr[i][0],new int[]{0,0,0,0});}
			hs[arr[i][0]][arr[i][1]]++;
		}
		int o=0;
		foreach(KeyValuePair<int,int[]> e in hs){
			hs[e.Key][0]=o;
			o+=e.Value[1]+e.Value[2]+e.Value[3];
		}
		for(int i=0;i<n;i++){
			Console.WriteLine("{0} {1} {2}",hs[arr[i][0]][0]+hs[arr[i][0]][arr[i][1]%3+1],hs[arr[i][0]][(arr[i][1]+1)%3+1]+(n-hs[arr[i][0]][0]-hs[arr[i][0]][1]-hs[arr[i][0]][2]-hs[arr[i][0]][3]),hs[arr[i][0]][arr[i][1]]-1);
		}
	}
}