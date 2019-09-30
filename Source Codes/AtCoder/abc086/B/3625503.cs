using System;

namespace Application
{
	class Solution
	{
		static void Main(string[] args)
		{
			var inputWords = Console.ReadLine().Split(' ');
			var joinedNumber = int.Parse(string.Join("", inputWords));

			var sqrt =  Math.Sqrt(joinedNumber);

			var result = sqrt - Math.Floor(sqrt) == 0d ? "Yes" : "No";

			Console.WriteLine(result);
		}
	}
}