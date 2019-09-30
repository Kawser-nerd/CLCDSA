using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
static long mod = 1000000007;

	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long r = long.Parse(input[0]);
		long c = long.Parse(input[1]);
    string[] inputa = Console.ReadLine().Split(' ');//Split???????????????????
    long x = long.Parse(inputa[0]);
    long y = long.Parse(inputa[1]);
    string[] inputb = Console.ReadLine().Split(' ');//Split???????????????????
    long d = long.Parse(inputb[0]);
    long l = long.Parse(inputb[1]);

    long area = ((r-x+1) * (c-y+1)) % mod;

    long pattern = PatternCount(x,y,d,l);
    //Console.WriteLine(pattern);
    pattern %= mod;
    pattern -= 2*PatternCount(x-1,y,d,l) + 2*PatternCount(x,y-1,d,l);
    pattern %= mod;
    //Console.WriteLine(pattern);
    pattern += PatternCount(x-2,y,d,l) + PatternCount(x,y-2,d,l) + 4*PatternCount(x-1,y-1,d,l);
    pattern %= mod;
    //Console.WriteLine(pattern);
    pattern -= 2*PatternCount(x-1,y-2,d,l) + 2*PatternCount(x-2,y-1,d,l);
    pattern %= mod;
    //Console.WriteLine(pattern);
    pattern += PatternCount(x-2,y-2,d,l);
    pattern %= mod;
    //Console.WriteLine(pattern);

    long answer = (area * pattern) % mod;
    if(answer < 0) answer += mod;

		Console.WriteLine(answer);
	}

  static long PatternCount(long x,long y,long d,long l)//x*y?d+l?????????
  {
    if(x <= 0 || y <= 0 || x*y < d+l) return 0;
    long answer = Comb(x*y, d, mod) * Comb(x*y-d, l, mod);
    return (answer % mod);
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

  static long DivideModFactorial(long x, long p)//????x!^-1(mod p), p???
  {
    long answer = 1;
    for(long i = x; i >= 2; i--)
    {
      answer *= DivideModReverse(i, p);
      answer %= p;
    }
    return answer;
  }

  static long Comb(long a, long b, long p)//?????????C(a,b)?mod p
  {
    long answer = 1;
    for(long i = a; i > a-b; i--)
    {
      answer *= i;
      answer %= p;
    }
    answer *= DivideModFactorial(b, p);
    answer %= p;
    return answer;
  }
  
}