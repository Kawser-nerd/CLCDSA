using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		string s=sc.S;
		long ans=0;
		for(int i = 0;i<s.Length;i++) {
			if(s[i]!='9'){
				ans+=s[i]-'0'-1;
				if(i==0&&s.Substring(i+1,s.Length-1)==new string('9',s.Length-i-1)){ans+=(s.Length-i-1)*9+1;}
				else{ans+=Math.Max((s.Length-i-1)*9,i!=0?(s.Length-i)*9-(s[i]-'0'):0);}
				break;
			}
			else{ans+=9;}
		}
		Console.WriteLine("{0}",ans);
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