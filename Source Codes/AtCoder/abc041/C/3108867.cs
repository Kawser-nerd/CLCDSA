using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		var hs=new Dictionary<int,int>();
		for(int i=0;i<n;i++){hs.Add(s[i],i+1);}
		Array.Sort(s,(a,b)=>b-a);
		for(int i=0;i<n;i++){Console.WriteLine("{0}",hs[s[i]]);}
	}
}