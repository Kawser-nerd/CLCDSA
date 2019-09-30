using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		long[] a=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long ans=0,o=1;
		Array.Sort(a,ca);
		var hs=new Dictionary<long,int>();
		for(int i=0;i<n;i++){
			if(hs.ContainsKey(a[i])&&hs[a[i]]>0){
				ans++;
				hs[a[i]]--;
				continue;
			}
			for(int j=1;(o<<j)-a[i]<=a[i];j++){
				if((o<<j)>a[i]){
					if(hs.ContainsKey((o<<j)-a[i])){hs[(o<<j)-a[i]]++;}
					else{hs.Add((o<<j)-a[i],1);}
				}
			}
		}
		Console.WriteLine(ans);
	}
	static int ca(long a,long b){
		if(a<b){return 1;}
		else if(a>b){return -1;}
		else{return 0;}
	}
}