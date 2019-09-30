using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
	public static void Main(string[] args)
	{
		var N = int.Parse(Console.ReadLine());
		var answer = new int[N];

		// ??????
		for (int i = 0; i < N; i++)
		{
			answer[i] = 100000;
		}

		// ?????????????
		var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
		// ??????
		answer[0] = 0;
		answer[1] = Math.Abs(input[1] - input[0]);

		for (int i = 2; i < N; i++)
		{
			var beforeOne = answer[i - 1] + Math.Abs(input[i] - input[i - 1]);
			var beforeTwo = answer[i - 2] + Math.Abs(input[i] - input[i - 2]);

			// ????????
			answer[i] = beforeOne < beforeTwo
				? beforeOne
				: beforeTwo;
		}

		// ????
		Console.WriteLine(answer[N - 1]);
	}

}