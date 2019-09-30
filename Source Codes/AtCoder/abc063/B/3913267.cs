using System;
using System.Collections.Generic;

namespace ABC063_B_Varied
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string s = Console.ReadLine();
			List<string> sArr = new List<string>(s.Length);
			bool sMatched = false;
			for (int i = 0; i < s.Length; i++)
			{
				sArr.Add(s.Substring(i, 1));
				//Console.Write(sArr[i]);
			}
			
			sArr.Sort();
			for (int index = 0; index < s.Length - 1; index++)
			{
				for (int j = index + 1; j < s.Length; j++)
				{
					if (sArr[index] == sArr[j])
						sMatched = true;
				}		
			}
			
			if(!sMatched) Console.WriteLine("yes");
			else Console.WriteLine("no");
		}
	}
}