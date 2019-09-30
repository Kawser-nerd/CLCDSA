using System;
using System.Collections.Generic;
class Program{
	static List<long[]> he=new List<long[]>();
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int b=-10000,c=0,e=0,a=0,t=0;
		for(int i=2;i<n;i++){s[i]+=s[i-2];}
		for(int i=0;i<n;i++){
			c=-10000;
			for(int j=0;j<n;j++){
				if(i!=j){
					int k=Math.Min(i,j),l=Math.Max(i,j);
					t=s[l-((k^l)&1)]-(k>1?s[k-2]:0);
					a=s[l-((k^l^1)&1)]-(k>0?s[k-1]:0);
					if(c<a){c=a;e=t;}
				}
			}
			if(b<e){b=e;}
		}
		Console.WriteLine(b);
	}
}