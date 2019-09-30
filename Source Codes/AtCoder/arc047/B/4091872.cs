using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		long a=long.MinValue,b=long.MinValue,c=long.MaxValue,d=long.MaxValue;
		long[][] h=new long[n][];
		if(n>1){
			for(int i=0;i<n;i++){
				h[i]=sc.La;
				a=Math.Max(a,-h[i][0]+h[i][1]);
				b=Math.Max(b,h[i][0]+h[i][1]);
				c=Math.Min(c,-h[i][0]+h[i][1]);
				d=Math.Min(d,h[i][0]+h[i][1]);
			}
		}
		if(n==1){Console.WriteLine("0 0");}
		else if(a-c==b-d||a==c||b==d){
			long g=Math.Max(a-c,b-d)/2;
			long e=a-g,f=b-g;
			Console.WriteLine("{0} {1}",(f-e)/2,f-(f-e)/2);
		}
		else if(a-c>b-d){
			long g=(a-c)/2;
			long e=0;
			long[] p=new long[]{b+g,b-g,d+g,d-g};
			for(long i=0;i<4;i++){
				e=(p[i]-(a-g))/2;
				long q=Math.Abs(h[0][0]-e)+Math.Abs(h[0][1]-(e+(a-g)));
				bool o=true;
				for(int j=1;j<n;j++){
					if(Math.Abs(h[j][0]-e)+Math.Abs(h[j][1]-(e+(a-g)))!=q){o=false;}
				}
				if(o){break;}
			}
			Console.WriteLine("{0} {1}",e,e+(a-g));
		}
		else if(a-c<b-d){
			long g=(b-d)/2;
			long e=0;
			long[] p=new long[]{a+g,a-g,c+g,c-g};
			for(long i=0;i<4;i++){
				e=(p[i]+(b-g))/2;
				long q=Math.Abs(h[0][0]-((b-g)-e))+Math.Abs(h[0][1]-e);
				bool o=true;
				for(int j=1;j<n;j++){
					if(Math.Abs(h[j][0]-((b-g)-e))+Math.Abs(h[j][1]-e)!=q){o=false;break;}
				}
				if(o){break;}
			}
			Console.WriteLine("{0} {1}",(b-g)-e,e);
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
}