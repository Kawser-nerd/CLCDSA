using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
	string[] input = Console.ReadLine().Split(' ');//Split???????????????????
	long n = long.Parse(input[0]);
	long x = long.Parse(input[1]);
  long answer = 0;
  long a = 0;
  long b = 0;

  answer += n;
  a = Math.Min(x,n-x);
  b = Math.Max(x,n-x);

    while(true)
    {
      //Console.WriteLine(a + " " + b + " " + answer);
      answer += 2 * a * (b/a);
      if(b % a == 0) 
      {
        answer -= a;
        break;
      }else
      {
      b = b % a;
      long temp = a;
      a = b;
      b = temp;
      }
    }
  
	Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}