using System;

namespace ABC053_B_A_to_Z_String
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string s = Console.ReadLine();

			int startIndex = s.Length;
			int endIndex = s.Length;
			for (int i = 0; i < s.Length; i++)
			{
				//?????????????NG???????????????????????OK
				if (s.Substring(i, 1) == "A" && startIndex == s.Length)
					startIndex = i;

				if (s.Substring(i, 1) == "Z")
					endIndex = i + 1; //i?????Z?????????????1?????
			}

			int resultStrLength = endIndex - startIndex;
			Console.WriteLine(resultStrLength);
		}
	}
}