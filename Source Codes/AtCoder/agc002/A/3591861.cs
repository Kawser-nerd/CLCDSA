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
    if(0 < a) Console.WriteLine("Positive");
    else
    {
      if(0 <= b) Console.WriteLine("Zero");
      else
      {
        long c = b-a;
        if(c % 2 == 0) Console.WriteLine("Negative");
        else Console.WriteLine("Positive");
      }
    }

	}
}