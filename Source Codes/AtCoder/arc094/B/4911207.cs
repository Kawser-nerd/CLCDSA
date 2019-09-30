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
		StringBuilder sb=new StringBuilder();
		for(int i = 0;i<n;i++) {
			double[] q=sc.Da;
			double m=q[0]*q[1];
			long d=(long)Math.Sqrt(m);
			if(d*d==m){d--;}
			if(q[0]==q[1]){sb.Append((q[0]*2-2)+"\n");}
			else if(Math.Abs(q[0]-q[1])==1){sb.Append((Math.Min(q[0],q[1])*2-2)+"\n");}
			else if(d*(d+1)>=m){sb.Append((2*d-2)+"\n");}
			else{sb.Append((2*d-1)+"\n");}
		}
		Console.Write(sb);
	}
}

public class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public int[] Ia2{get{return Array.ConvertAll(("0 "+Console.ReadLine()+" 0").Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}