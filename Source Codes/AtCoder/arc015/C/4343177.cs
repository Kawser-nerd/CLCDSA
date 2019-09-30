using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
static class Program{
	const int mod=1000000007;
	const long o=1;
	static Dictionary<string,List<Ss>> hs=new Dictionary<string,List<Ss>>();
	static Ss ans1=new Ss("",1),ans2=new Ss("",0);
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		for(int i = 0;i<n;i++) {
			string[] s=sc.Sa;
			if(!hs.ContainsKey(s[0])){
				hs.Add(s[0],new List<Ss>());
				hs[s[0]].Add(new Ss("",1));
			}
			hs[s[0]].Add(new Ss(s[2],int.Parse(s[1])));
			if(!hs.ContainsKey(s[2])){
				hs.Add(s[2],new List<Ss>());
				hs[s[2]].Add(new Ss("",0));
			}
			else{
				Ss q=hs[s[2]][0];
				q.n=0;
				hs[s[2]][0]=q;
			}
			hs[s[2]].Add(new Ss(s[0],1.0/int.Parse(s[1])));
		}

		foreach(KeyValuePair<string,List<Ss>> e in hs){
			Fu(e.Key,e.Key,1);
		}
		Console.WriteLine("{0}{1}={2}{3}",ans1.n,ans1.s,Math.Round(ans2.n),ans2.s);
	}
	static void Fu(string s,string n,double d){
		Ss q=hs[n][0];
		q.s=s;
		hs[n][0]=q;
		for(int i=1;i<hs[n].Count;i++){
			if(hs[hs[n][i].s][0].s!=s){Fu(s,hs[n][i].s,d*hs[n][i].n);}
		}
		if(d>ans2.n){
			ans1.s=s;
			ans2.s=n;
			ans2.n=d;
		}
	}
}
public struct Ss{
    public string s;
    public double n;
	public Ss(string s,double n){
		this.s=s;
		this.n=n;
	}
	public void nn(int n){this.n=n;}
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