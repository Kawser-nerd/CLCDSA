using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		long n=sc.L,ans=1;
		int l=(int)Math.Sqrt(n);
		for(int i=2;i<=l;i++){
			if(n%i==0){
				ans+=i+n/i;
				if(i==n/i){ans-=i;}
			}
		}
		if(ans==1||ans<n){Console.WriteLine("Deficient");}
		else if(ans==n){Console.WriteLine("Perfect");}
		else{Console.WriteLine("Abundant");}
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