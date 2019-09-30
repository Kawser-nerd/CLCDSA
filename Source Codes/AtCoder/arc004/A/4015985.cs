using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
	static void Main(string[] args)
	{
		// ?????
		int n = int.Parse(Console.ReadLine());
		var InputValueList = new List<InputValue>();
		double answer = 0;

		for (int i = 1; i <= n; i++)
		{
			// ?????????????
			var inputArray = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
			InputValueList.Add(new InputValue(inputArray[0], inputArray[1]));
		}

		for (int i = 0; i < n; i++)
		{
			foreach (var inputValue in InputValueList.Skip(i + 1))
			{
				var result = getResult(InputValueList[i], inputValue);
				if (result > answer)
					answer = result;
			}
		}

		Console.WriteLine(answer.ToString("F6"));
	}

	private static double getResult(InputValue first, InputValue second)
	{
		return Math.Sqrt(Math.Pow((first.x - second.x), 2) + Math.Pow((first.y - second.y), 2));
	}

	public class InputValue
	{
		public int x { get; }
		public int y { get; }

		public InputValue(int x, int y)
		{
			this.x = x;
			this.y = y;
		}
	}

}