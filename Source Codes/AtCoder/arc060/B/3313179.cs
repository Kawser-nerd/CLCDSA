using System;
class Program{
	static void Main(){
		long n=long.Parse(Console.ReadLine());
		long s=long.Parse(Console.ReadLine());
		long ans=n-s+1;
		if(n==s){ans=n+1;}
		else if(s>n/2+(n%2)){ans=-1;}
		else{
			int r=(int)Math.Sqrt(n);
			for(int i=2;i<=r;i++){
				if(fu(i,n)==s){ans=i;break;}
				else if((n-s)%i==0&&fu((n-s)/i+1,n)==s){ans=(n-s)/i+1;}
			}
		}
		Console.WriteLine("{0}",ans);
	}
	static long fu(long b,long n){return n<b?n:fu(b,n/b)+n%b;}
}