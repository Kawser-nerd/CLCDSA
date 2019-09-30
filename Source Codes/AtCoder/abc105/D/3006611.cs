using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] a=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] w=new int[s[0]+1];
		var hs=new Dictionary<int,int>();
		long ans=0;
		hs[0]=1;
		for(int i=1;i<=s[0];i++){
			w[i]=(w[i-1]+a[i-1])%s[1];
			if(hs.ContainsKey(w[i])){ans+=hs[w[i]];hs[w[i]]++;}
			else{hs[w[i]]=1;}
		}
		Console.WriteLine("{0}",ans);
	}
}