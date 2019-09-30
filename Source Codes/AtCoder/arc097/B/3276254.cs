using System;
using System.Collections.Generic;
class Program{
	static int b=1,ans=0;
	static int[] s,p;
	static int[,] h;
	static List<int>[] li;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		p=Array.ConvertAll(("0 "+Console.ReadLine()).Split(),int.Parse);
		h=new int[2,s[0]+1];
		li=new List<int>[s[0]+1];
		for(int i=1;i<=s[0];i++){li[i]=new List<int>();}
		for(int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			li[q[0]].Add(q[1]);
			li[q[1]].Add(q[0]);
		}
		for(;b<=s[0];b++){
			if(h[0,b]==0){fu(b);}
		}
		Console.WriteLine("{0}",ans);
	}
	static void fu(int a){
		ck(a,0);
		ck(p[a],1);
		for(int i=0;i<li[a].Count;i++){
			if(h[0,li[a][i]]==0){fu(li[a][i]);}
		}
	}
	static void ck(int a,int c){
		h[c,a]=b;
		if(h[c^1,a]==b){ans++;}
	}
}