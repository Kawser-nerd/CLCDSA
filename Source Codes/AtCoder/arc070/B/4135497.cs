using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		int[] a=sc.Ia;
		Array.Sort(a);
		int lb=-1,ub=s[0],mid=0;
		while(ub-lb>1){
			mid=(ub+lb)/2;
			bool q=false;
			if(a[mid]>=s[1]){q=true;}
			else{
				bool[] dp=new bool[s[1]+1];
				dp[0]=true;
				for(int j=0;j<s[0];j++){
					if(j!=mid){
						for(int k=s[1];k>=a[j];k--){
							if(dp[k-a[j]]){dp[k]=true;}
						}
					}
				}
				for(int j=s[1]-a[mid];j<s[1];j++){
					if(dp[j]){q=true;break;}
				}
			}
			if(q){ub=mid;}
			else{lb=mid;}
		}
		Console.WriteLine("{0}",ub);
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