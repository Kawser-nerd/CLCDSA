using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		List<int> li=new List<int>(sc.Ia);
		int[] ans=new int[n];
		int j=0;
		for(int i = n-1;i>=0;i--) {
			j=li.Count-1;
			for(;j>=0;j--) {
				if(li[j]==j+1){
					ans[i]=li[j];
					li.RemoveAt(j);
					break;
				}
			}
			if(j==-1){
				Console.WriteLine(-1);
				break;
			}
		}
		if(j!=-1){Console.WriteLine(String.Join("\n",ans));}
	}
}

public class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public int[] Ia2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}