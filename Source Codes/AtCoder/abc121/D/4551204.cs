using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		long A = long.Parse(str[0]);
		long B = long.Parse(str[1]);
		long ans = 0;
		for(var i=1;i<=40;i++){
			long C = (long)Math.Pow(2,i);
			long a = A%(C*2);
			long b = B%(C*2);
			if(a<C && b>=C){
				ans += (b-C+1)%2*C;
			} else if(a>=C && b<C){
				ans += (C*2-a)%2*C;
			} else if(a>=C && b>=C){
				ans += (Math.Abs(b-a)+1)%2*C;
			}
		}
		long a1 = A%4;
		long b1 = B%4+4;
		long c1 = 0;
		for(var i=a1;i<=b1;i++){
			if(i%2==1){
				c1 = (c1+1)%2;
			}
		}
		ans += c1;
		Console.WriteLine(ans);
	}
}