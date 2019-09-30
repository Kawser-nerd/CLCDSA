using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	const long o=1;
	static List<int>[] li;
	static int[] s;
	static int[][] h;
	static int ans=0;
	static void Main(){
		Sc sc=new Sc();
		s=sc.Ia;
		li=new List<int>[s[0]+1];
		int[][] q=new int[s[0]+1][];
		for(int i=1;i<=s[0];i++){li[i]=new List<int>();}
		for(int i=1;i<s[0];i++){
			q[i]=sc.Ia;
			li[q[i][0]].Add(q[i][1]);
			li[q[i][1]].Add(q[i][0]);
		}
		if(s[1]%2==0){
			for(int i=1;i<=s[0];i++){ans=Math.Max(ans,Fu1(i,0,0));}
		}
		else if(s[1]==1){ans=2;}
		else{
			h=new int[s[0]+1][];
			for(int i=1;i<=s[0];i++){h[i]=new int[li[i].Count];}
			for(int i=1;i<=s[0];i++){Fu2(i);}
			for(int i=1;i<s[0];i++){
				int p=2;
				for(int j=0;j<h[q[i][0]].Length;j++){
					if(li[q[i][0]][j]!=q[i][1]){p+=h[q[i][0]][j];}
				}
				for(int j=0;j<h[q[i][1]].Length;j++){
					if(li[q[i][1]][j]!=q[i][0]){p+=h[q[i][1]][j];}
				}
				ans=Math.Max(ans,p);
			}
		}
		Console.WriteLine("{0}",s[0]-ans);
	}
	static int Fu1(int a,int b,int c){
		int p=0;
		if(c<s[1]/2){
			for(int i=0;i<li[a].Count;i++){
				if(li[a][i]!=b){p+=Fu1(li[a][i],a,c+1);}
			}
		}
		return p+1;
	}
	static void Fu2(int a){
		for(int i=0;i<li[a].Count;i++){h[a][i]+=Fu1(li[a][i],a,1);}
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
	public string[] Sa{get{return Console.ReadLine().Split();}}
}