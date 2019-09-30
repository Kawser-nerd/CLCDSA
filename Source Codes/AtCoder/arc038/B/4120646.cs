using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		string[] a=new string[s[0]];
		bool[,] b=new bool[s[0],s[1]];
		for(int i = 0;i<s[0];i++) {a[i]=sc.S;}
		for(int i = s[0]-1;i>=0;i--) {
			for(int j = s[1]-1;j>=0;j--) {
				if(b[i,j]||a[i][j]=='#'){continue;}
				if(i!=0){b[i-1,j]=true;}
				if(j!=0){b[i,j-1]=true;}
				if(i!=0&&j!=0){b[i-1,j-1]=true;}
			}
		}
		Console.WriteLine(b[0,0]?"First":"Second");
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