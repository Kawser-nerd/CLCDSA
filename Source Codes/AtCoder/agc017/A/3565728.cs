using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
    string[] input = Console.ReadLine().Split(' ');//Split???????????????????
    long n = long.Parse(input[0]);
    long p = long.Parse(input[1]);
    long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long mod = 1000000007;
    long answer = 0;
    long oneCount = 0;//1(mod2)???

    for(int i = 0; i < n; i++)
    {
      nums[i] %= 2;
      if(nums[i] == 1) oneCount++;
    }

    for(long i = p; i <= oneCount; i+=2)//1(mod2)???
    {
      answer += Comb(oneCount, i, mod);
      //Console.WriteLine(answer+" "+i+" "+oneCount);
    }

    for (long i = 0; i < n-oneCount; i++) answer *= 2;

    Console.WriteLine(answer);
     
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