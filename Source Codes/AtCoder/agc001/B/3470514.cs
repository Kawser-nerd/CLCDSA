using System;
class Program{
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long ans=(s[0]-gcd(s[0],s[1]))*3;
		Console.WriteLine(ans);
	}
	static long gcd(long a,long b){
		long c=Math.Max(a,b)%Math.Min(a,b);
		b=Math.Min(a,b);
		while(c!=0){
			a=b%c;
			b=c;
			c=a;
		}
		return b;
	}
}