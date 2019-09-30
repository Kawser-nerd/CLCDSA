using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
	static void Main(string[] args)
	{
		// ?????(????)
		int n = int.Parse(Console.ReadLine());
		var inputList = new List<int>();

		for (int i = 1; i <= n; i++)
		{
			inputList.Add(int.Parse(Console.ReadLine()));
		}

		var answer = inputList.Distinct().Count();
		Console.WriteLine(answer);
	}

}