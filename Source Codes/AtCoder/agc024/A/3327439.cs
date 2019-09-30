using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long a = long.Parse(input[0]);
		long b = long.Parse(input[1]);
    long c = long.Parse(input[2]);
		long k = long.Parse(input[3]);
		Console.WriteLine((k % 2 == 0) ? a-b : b-a);
	}
}