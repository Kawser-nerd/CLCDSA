using System;
class Program{
	const int mod=1000000007;
	static long[] fo;
	static void Main(){
		int[] a=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] b=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] c=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int xy=b[0]*b[1],dl=c[0]+c[1];
		fo=new long[xy+1];
		fo[0]=1;
		for(int i=1;i<=xy;i++){fo[i]=(fo[i-1]*i)%mod;}
		long ans=(fc(xy,dl)*fc(dl,c[1]))%mod;
		
		ans=ans-((fc(xy-b[0],dl)*fc(dl,c[1])*2)%mod);
		ans=ans-((fc(xy-b[1],dl)*fc(dl,c[1])*2)%mod);
		ans=ans+((fc(xy-b[0]-b[1]+1,dl)*fc(dl,c[1])*4)%mod);
		ans=ans+((fc(xy-b[0]*2,dl)*fc(dl,c[1]))%mod);
		ans=ans+((fc(xy-b[1]*2,dl)*fc(dl,c[1]))%mod);
		ans=ans-((fc(xy-b[0]*2-b[1]+2,dl)*fc(dl,c[1])*2)%mod);
		ans=ans-((fc(xy-b[1]*2-b[0]+2,dl)*fc(dl,c[1])*2)%mod);
		ans=(ans+((fc(xy-b[0]*2-b[1]*2+4,dl)*fc(dl,c[1]))%mod)+mod)%mod;
		ans=(ans*(a[0]-b[0]+1)*(a[1]-b[1]+1))%mod;
		if(xy==1){ans=a[0]*a[1];}
		Console.WriteLine("{0}",ans);
	}
	static long fc(long a,long b){
		if(a>=b&&a>-1&&b>-1){return (fo[a]*mi((fo[b]*fo[a-b])%mod))%mod;}
		else{return 0;}
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