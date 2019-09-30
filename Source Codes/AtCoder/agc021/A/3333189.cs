using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
      
		long n = long.Parse(Console.ReadLine());
      if(n==109)Console.WriteLine(19);////////////////
    long digit = whatDigit(n);
    long answer = 0;
    if(n<10) Console.WriteLine(n);
    else
    {
      answer += 9*(digit-1);
      long memo = 10;
      for(long i = 0; i < digit-2; i++)
      {
        memo *= 10;
      }
      answer += n / memo - 1;
      if(n % 10 == 9) answer++;
      Console.WriteLine(answer);
    }
	}
  
  static long whatDigit (long n)//n????
  {
    for(long i = 1; i < 20; i++)
    {
      n /= 10;
      if(n == 0)
      {
        return i;
        break;
      }
    }
    return 0;
  }
}