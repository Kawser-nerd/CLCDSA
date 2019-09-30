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
    long answer = long.MaxValue;
		if(a%2 == 0 || b%2 == 0 || c%2 == 0) Console.WriteLine(0);
		else
    {
      answer = Math.Min(a*b,a*c);
      answer = Math.Min(b*c,answer);
      Console.WriteLine(answer);
    }
	}
}