using System;

namespace ABC049_A_UOIAUAI
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] motherLanguage = new[] {"a", "i", "u", "e", "o"};
			string s = Console.ReadLine();

			for (int i = 0; i < 5; i++) {
				if (motherLanguage[i] == s)
				{
					Console.WriteLine("vowel");
					return;
				}
			}
			
			Console.WriteLine("consonant");
		}
	}
}