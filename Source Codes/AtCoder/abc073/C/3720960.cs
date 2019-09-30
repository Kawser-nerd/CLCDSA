using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC073_C_Write_and_Erase
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			List<int> aList = new List<int>();
			for (int i = 0; i < n; i++)
				aList.Add(int.Parse(Console.ReadLine()));
			
			aList.Sort();
			
			//???????????????
			int count = 1;
			int result = 0;
			for (int i = 0; i < n - 1; i++)
			{
				if (aList[i] == aList[i + 1])
				{
					count++;
				}
				else
				{
					if (count % 2 == 1) result++;
					count = 1;
				}
				
				if (i == n - 2 && count % 2 == 1) result++;
			}
			
			Console.WriteLine(result);

			//?????????
			/*int count = aList.Count;
			for (int i = 0; i < n;)
			{
				int countNumbers = aList.Count(x => x == aList[i]);
				if (countNumbers % 2 == 1)
					count -= countNumbers - 1;
				else
					count -= countNumbers;

				i += countNumbers;
			}

			Console.WriteLine(count);*/
		}
	}
}