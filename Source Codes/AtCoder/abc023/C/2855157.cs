using System;
class Program{
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long n=long.Parse(Console.ReadLine());
		long[] g=new long[s[0]+1];
		long[] r=new long[s[1]+1];
		long[][] k=new long[n][];
		long ans=0;
		long[] gh=new long[s[2]+1];

		for(long i=0;i<n;i++){
			k[i]=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
			g[k[i][0]]++;
			r[k[i][1]]++;
		}
		for(long i=1;i<=s[0];i++){if(g[i]<=s[2]){gh[g[i]]++;}}
		for(long i=1;i<=s[1];i++){if(r[i]<=s[2]){ans+=gh[s[2]-r[i]];}}
		for(long i=0;i<n;i++){
			if(g[k[i][0]]+r[k[i][1]]==s[2]){ans--;}
			else if(g[k[i][0]]+r[k[i][1]]==s[2]+1){ans++;}
		}
		Console.WriteLine(ans);
	}
}