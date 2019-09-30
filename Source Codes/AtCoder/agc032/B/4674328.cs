using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I,k=0;
		StringBuilder sb=new StringBuilder();
		if(n%2==0){
			for(int i = 1;i<=n/2;i++) {
				for(int j = i+1;j<=n-i;j++) {
					sb.Append(i+" "+j+"\n");
					sb.Append(n-i+1+" "+j+"\n");
					k+=2;
				}
			}
		}
		else{
			for(int j = 1;j<n;j++) {
				sb.Append(n+" "+j+"\n");
				k++;
			}
			for(int i = 1;i<=n/2;i++) {
				for(int j = i+1;j<n-i;j++) {
					sb.Append(i+" "+j+"\n");
					sb.Append(n-i+" "+j+"\n");
					k+=2;
				}
			}
		}

		Console.WriteLine("{0}",k);
		Console.Write(sb);
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