using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long a = long.Parse(input[0]);
		long b = long.Parse(input[1]);
    long c = long.Parse(input[2]);
    long d = Math.Abs(a-b);
    long e = Math.Abs(b-c);
    long answer = 0;
    if(a%2==1 || b%2==1 || c%2==1) Console.WriteLine(0);
    else if(d == 0 && e == 0) Console.WriteLine(-1);
    else
    {
      while(d % 2 == 0 && e % 2 == 0)
      {
        answer++;
        d /= 2;
        e /= 2;
      }
      Console.WriteLine(answer);
    }

	}
}