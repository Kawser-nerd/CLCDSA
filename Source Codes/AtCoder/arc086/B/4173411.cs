using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		long[] a=sc.La;
		long b=0,c=0;
		int q=0;
		string[] ans=new string[n*2];
		for(int i = 0;i<n;i++) {
			if(a[b]<a[i]){b=i;}
			if(a[c]>a[i]){c=i;}
		}
		if(Math.Abs(a[b])>Math.Abs(a[c])){
			for(int i = 1;i<n;i++) {
				while(a[i]<a[i-1]){
					a[i]+=a[b];
					ans[q]=(b+1)+" "+(i+1);
					q++;
					if(a[b]<a[i]){b=i;}
				}
			}
		}
		else{
			for(int i = n-2;i>=0;i--) {
				while(a[i]>a[i+1]){
					a[i]+=a[c];
					ans[q]=(c+1)+" "+(i+1);
					q++;
					if(a[c]>a[i]){c=i;}
				}
			}
		}
		Array.Resize(ref ans,q);
		Console.WriteLine("{0}",q);
		if(q>0){Console.WriteLine(String.Join("\n",ans));}
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