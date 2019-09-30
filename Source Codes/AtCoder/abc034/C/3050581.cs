using System;
class Program{
	const int mod=1000000007;
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);

		long a=s[0]+s[1]-2,b=s[1]-1,c=a-b;
		long aa=1,bb=1,cc=1,n=1;
		for(int i=1;i<=a;i++){
			n=(n*i)%mod;
			if(i==a){aa=n;}
			if(i==b){bb=n;}
			if(i==c){cc=n;}
		}
		Console.WriteLine("{0}",(aa*mi((bb*cc)))%mod);
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