using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
static string[] input = Console.ReadLine().Split(' ');
static long n = long.Parse(input[0]);
static long a = long.Parse(input[1]);
static long b = long.Parse(input[2]);
static long k = long.Parse(input[3]);
static long p = 998244353;
static long answer = 0;
static long memoB = 0;
static long[] factorials = new long[n+1];
static long[] factorialRs = new long[n+1];//i!^-1(mod p), p???

	static void Main()
	{
  factorials[0] = 1;
  factorialRs[n] = DivideModFactorial(n,p);
   for(long i = 1; i <= n; i++)
   {
     factorials[i] = (factorials[i-1]*i)%p;
     factorialRs[n-i] = (factorialRs[n+1-i]*(n+1-i))%p;//???????
   }
   
   for(long i = 0; i <= n; i++)
   {
      if((k-a*i)%b != 0 || (k-a*i)/b > n || (k-a*i)/b < 0) continue;//a????b????????
      else
      {
        memoB = (k-a*i)/b;
        long memo = Comb(n, i, p);
        memo %= p;
        memo *= Comb(n, memoB, p);
        memo %= p;
        answer += memo;
        answer %= p;
      }
   }

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
    answer *= factorials[a];
    answer %= p;
    answer *= factorialRs[a-b];
    answer %= p;
    answer *= factorialRs[b];
    answer %= p;
    return answer;
  }
  
}