using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		long[] a=sc.La;
		long[] c=sc.La;
		if(s[0]<s[1]){
			long[,] g=new long[s[0],s[0]];
			long[,] b=new long[s[0],1];
			for(int i = 0;i<s[0];i++) {
				g[0,i]=c[i];
				if(i!=s[0]-1){g[i+1,i]=-1;}
				b[i,0]=a[s[0]-1-i];
			}
			long[,] ans=Mp(b,g,s[1]-s[0]);
			Console.WriteLine("{0}",ans[0,0]);
		}
		else{
			Console.WriteLine("{0}",a[s[1]-1]);
		}
	}
	static long[,] Mp(long[,] r,long[,] x,long e){
		while(e>0){
			if((e&1)>0){r=Mm(x,r);}
			x=Mm(x,x);
			e>>=1;
		}
		return r;
	}
	static long[,] Mm(long[,] a,long[,] b){
		long[,] q=new long[a.GetLength(0),b.GetLength(1)];
		for(int i=0;i<b.GetLength(1);i++){
			for(int j=0;j<a.GetLength(0);j++){
				for(int k=0;k<a.GetLength(1);k++){q[j,i]=(q[j,i]^(a[j,k]&b[k,i]));}
			}
		}
		return q;
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