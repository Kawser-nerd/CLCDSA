using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
	public static void Main(String[] args)
	{
		var N = int.Parse(Console.ReadLine());
		if (N >= 1000)
			Console.WriteLine("ABD");
		else
			Console.WriteLine("ABC");
	}

}