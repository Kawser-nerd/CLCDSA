using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long n = long.Parse(input[0]);
		long a = long.Parse(input[1]);
    long b = long.Parse(input[2]);

    if(n == 1)
    {
      if(a == b) Console.WriteLine(1);
      else Console.WriteLine(0);
    }
    else
    {
      if(a>b) Console.WriteLine(0);
      else Console.WriteLine((b-a)*(n-2)+1);
    }

	}
}