using System;

namespace ABC090_B_Palindromic_Numbers
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int a = int.Parse(input[0]);
			int b = int.Parse(input[1]);

			int count = 0;
			for (int i = a; i <= b; i++)
			{
				string firstword = i.ToString().Substring(0, 1);
				string secondWord = i.ToString().Substring(1, 1);
				string beforeLastWord = i.ToString().Substring(3, 1);
				string lastWord = i.ToString().Substring(4, 1);

				if (firstword == lastWord && secondWord == beforeLastWord)
				{
					count++;
				}
			}
			
			Console.WriteLine(count);
		}
	}
}