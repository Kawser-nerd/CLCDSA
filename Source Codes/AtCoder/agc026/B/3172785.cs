using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		long T = long.Parse(Console.ReadLine());
		for(var i=0;i<T;i++){
			string[] str = Console.ReadLine().Split();
			long A = long.Parse(str[0]);
			long B = long.Parse(str[1]);
			long C = long.Parse(str[2]);
			long D = long.Parse(str[3]);
			string ans = "Yes";
			if(A < B || D < B){
				ans = "No";
			} else if(B <= C){
				ans = "Yes";
			} else if(B - Gcd(D,B) + A % Gcd(D,B) > C){
				ans = "No";
			}
			Console.WriteLine(ans);
		}
	}

	public static long Gcd(long a, long b) {
		if (a < b)
			return Gcd(b, a);
		while (b != 0) {
			var r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
}