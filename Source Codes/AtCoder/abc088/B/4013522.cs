using System;
using System.Linq;

class Program
{
	static void Main(string[] args)
	{
		// ?????
		int n = int.Parse(Console.ReadLine());
		// ?????????????
		var input = Console.ReadLine().Split(' ').Select(int.Parse).OrderBy(x => -x).ToArray();

		var aSum = 0;
		var bSum = 0;

		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
				aSum += input[i];
			else
				bSum += input[i];
		}
		Console.WriteLine(aSum - bSum);
	}

}