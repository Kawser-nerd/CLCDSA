using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
	long n = long.Parse(Console.ReadLine());//long.Parse???????????
  long k = long.Parse(Console.ReadLine());
  long p = 1000000007;

	Console.WriteLine(Comb(n-1+k, k, p));//WriteLine?Write?????????????
  //Console.WriteLine(Comb(5, 3, p));
  //Console.WriteLine(DivideModFactorial(3, 17));
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
      //Console.WriteLine(answer + "a");
      answer *= DivideModReverse(i, p);
      //Console.WriteLine(answer + "b");
      answer %= p;
      //Console.WriteLine(answer + "c");
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