using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static List<int>[] li;
	static bool[] b;
	static int t=0;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		li=new List<int>[s[0]+1];
		b=new bool[s[0]+1];
		int f=0,x=0,f1=0,f2=0;
		for(int i=1;i<=s[0];i++){li[i]=new List<int>();}
		for(int i=0;i<s[1];i++){
			int[] q=sc.Ia;
			li[q[0]].Add(q[1]);
			li[q[1]].Add(q[0]);
		}
		string ans="Yes";
		for(int i=1;i<=s[0];i++){
			if(li[i].Count%2==1){ans="No";break;}
			if(li[i].Count==4){
				if(f==0){f1=i;}
				else{f2=i;}
				f++;
			}
			if(li[i].Count>=6){x++;}
		}
		if(x==0&&f<2){ans="No";}
		else if(x==0&&f==2){
			b[f1]=true;
			Fu(f1,f2);
			if(t!=2){ans="No";}
		}
		Console.WriteLine("{0}",ans);
	}
	static void Fu(int a,int g){
		if(a==g){t++;return;}
		b[a]=true;
		for(int i=0;i<li[a].Count;i++){
			if(!b[li[a][i]]){Fu(li[a][i],g);}
		}
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