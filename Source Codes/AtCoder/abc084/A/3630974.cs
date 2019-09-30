using System;

namespace Application
{
	class Solution
	{
		static void Main(string[] args)
		{
			var inputWord = Console.ReadLine();
			var hour = int.Parse(inputWord);

			var day = new DateTime(2018, 12, 30, hour, 0, 0);
			var newYearDay = new DateTime(2019, 1, 1);

			var result = newYearDay.Subtract(day).TotalHours;

			Console.WriteLine(result);
		}
	}
}