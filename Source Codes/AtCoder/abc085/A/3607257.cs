using System;

namespace Application
{
	class Solution
	{
		static void Main(string[] args)
		{
			var inputChars = Console.ReadLine().ToCharArray();
			inputChars[3] = '8';

			Console.WriteLine(new string(inputChars));
		}
	}
}