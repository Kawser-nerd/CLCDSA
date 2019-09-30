using System;
class Program{
	const int mod=1000000007;
	static void Main(){
		string s=Console.ReadLine();
		long a=0,b=0,c=0,q=1;
		long[] r=new long[s.Length];
		for(int i=0;i<s.Length;i++){
			if(s[i]=='?'){q=(q*3)%mod;}
		}
		for(int i=s.Length-1;i>=0;i--){
			if(s[i]=='A'){a=(a+b)%mod;}
			else if(s[i]=='B'){b=(b+c)%mod;}
			else if(s[i]=='C'){c=(c+q)%mod;}
			else{
				a=(a+b*333333336)%mod;
				b=(b+c*333333336)%mod;
				c=(c+q*333333336)%mod;

			}
		}
		Console.WriteLine("{0}",a);
	}
}