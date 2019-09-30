using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static string s,z="abcdefghijklmnopqrstuvwxyz";
	static char[] c;
	static int[,] h;
	static int[] g;
	static int m=26,t=0,o=1;
	static bool b=true;
	static void Main(){
		Sc sc=new Sc();
		s=sc.S;
		g=new int[s.Length];
		h=new int[s.Length+1,m];
		for(int i=s.Length-1;i>=0;i--){
			if(t==(1<<m)-1){o++;t=0;}
			t|=1<<(s[i]-'a');
			g[i]=o;
			if(i==s.Length-1){continue;}
			for(int j=0;j<m;j++){h[i,j]=h[i+1,j];}
			h[i,s[i+1]-'a']=i+1;
		}
		if(t==(1<<m)-1){o++;t=0;}
		int q=0;
		while((t&(1<<q))!=0){q++;}
		if(o==1){Console.WriteLine("{0}",z[q]);}
		else{
			c=new char[o];
			Fu((s[0]-'a')==q?0:h[0,q],0);
			Console.WriteLine("{0}",String.Join("",c));
		}
	}
	static void Fu(int n,int a){
		c[a]=s[n];
		if(a==o-1||a>=o-g[n]){return;}
		for(int i=0;i<m&&b;i++){
			if(h[n,i]==0){
				b=false;
				c[a+1]=z[i];
				if(a!=o-2){}
			}
			else{Fu(h[n,i],a+1);}
		}
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