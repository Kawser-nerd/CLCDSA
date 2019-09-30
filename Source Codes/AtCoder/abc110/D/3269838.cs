using System;
using System.Collections.Generic;
class Program{
	const int mod=1000000007;
	static long[] s,k;
	static Dictionary<long,long> sb=new Dictionary<long,long>();
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		int a=(int)Math.Sqrt(s[1]);
		long si=s[1],ans=1,m=si;
		for(int i=2;i<=a;i++){
			while(si%i==0){
				si/=i;
				if(!sb.ContainsKey(i)){sb.Add(i,1);}
				else{sb[i]++;}
				m=i;
			}
		}
		if(si==1){}
		else if(!sb.ContainsKey(si)){sb.Add(si,1);}
		else{sb[si]++;}
		k=new long[200000];
		k[0]=1;
		for(int i=1;i<200000;i++){k[i]=(k[i-1]*i)%mod;}
		foreach(KeyValuePair<long,long> e in sb){
			long an=e.Value+s[0]-1;
			long ak=e.Value;
			ans=((k[an]*mi(k[ak]*k[an-ak])%mod)*ans)%mod;
		}
		Console.WriteLine("{0}",(ans+mod)%mod);
	}
	static long mi(long a){
		long b=mod,u=1,v=0;
		while(b>0){
			long t=a/b;
			a-=t*b;a^=b;b^=a;a^=b;
			u-=t*v;u^=v;v^=u;u^=v;
		}
		u%=mod;
		if(u<0){u+=mod;}
		return u%mod;
	}
}