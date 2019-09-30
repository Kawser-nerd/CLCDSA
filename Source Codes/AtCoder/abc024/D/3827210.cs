using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		long a = long.Parse(Console.ReadLine());
		long b = long.Parse(Console.ReadLine());
		long c = long.Parse(Console.ReadLine());
		long mod = 1000000007;

		long x = (a*c-b*c)%mod;
		if(x < 0) x += mod;
		long xx = DivideModReverse(b*c-a*c-a*b,mod);
		if(xx < 0) xx += mod;
		x *= xx;
		x %= mod;
		if(x < 0) x += mod;

		long y = (a*b-b*c)%mod;
		if(y < 0) y += mod;
		y *= xx;
		y %= mod;
		if(y < 0) y += mod;
		
		Console.WriteLine(x+" "+y);
	}

	static long DivideMod(long x, long a, long p)//????x^a(mod p)
  {
    long num = 2;
    long answer = 1;
    long check = a;
    long memo = x%p;
    
    while(check > 0)
    {
      if(check % num == num / 2)
      {
        check -= num / 2;
        answer *= memo;
        answer %= p;
      }
    memo *= memo;
    memo %= p;
    num *= 2;
    }
    return answer;
  }

  static long DivideModReverse(long x, long p)//????x^-1(mod p), p???
  {
    long answer = DivideMod(x, p-2, p);
    return answer;
  }
	
}