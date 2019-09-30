using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		int[][] a=new int[s[0]][];
		int[][] h=new int[s[0]][];
		string[] ans=new string[s[0]];
		for(int i = 0;i<s[0];i++) {
			char[] c=sc.S.ToCharArray();
			a[i]=new int[s[1]];
			h[i]=new int[s[1]];
			for(int j = 0;j<s[1];j++) {h[i][j]=c[j]-48;}
		}
		for(int i = 0;i<s[0];i++) {
			for(int j = 0;j<s[1];j++) {
				if(h[i][j]!=0){
					a[i+1][j]+=h[i][j];
					h[i+1][j-1]-=h[i][j];
					h[i+1][j+1]-=h[i][j];
					h[i+2][j]-=h[i][j];
					h[i][j]=0;
				}
			}
			ans[i]=String.Join("",a[i]);
		}
		Console.WriteLine(String.Join("\n",ans));
	}
}

class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
}