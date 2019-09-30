using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
static long n = 210000;
static long[] factorials = new long[n+1];//i!(mod p)?????
static long[] factorialRs = new long[n+1];//i!^-1(mod p), p???

	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long h = long.Parse(input[0]);
		long w = long.Parse(input[1]);
    long a = long.Parse(input[2]);
		long b = long.Parse(input[3]);
		long p = 1000000007;
    long answerm = 0;
    long answer = 0;

    factorials[0] = 1;
		factorialRs[n] = DivideModFactorial(n,p);
		for(long i = 1; i <= n; i++)
		{
		factorials[i] = (factorials[i-1]*i)%p;//i!(mod p)
		factorialRs[n-i] = (factorialRs[n+1-i]*(n+1-i))%p;//???????
		}

    for(int i = 0; i < h-a; i++)//??????
    {
      answer = factorials[b-1+i];
      answer %= p;
      answer *= factorialRs[b-1];
      answer %= p;
      answer *= factorialRs[i];
      answer %= p;

      answer *= factorials[w-b-1 + h-i-1];
      answer %= p;
      answer *= factorialRs[w-b-1];
      answer %= p;
      answer *= factorialRs[h-i-1];
      answer %= p;

      //Console.WriteLine(answer);
      answerm += answer;
      answerm %= p;
    }

		Console.WriteLine(answerm);
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
    answer *= factorials[a];
    answer %= p;
    answer *= factorialRs[a-b];//??a-b????????????
    answer %= p;
    answer *= factorialRs[b];
    answer %= p;
    return answer;
  }

  
}