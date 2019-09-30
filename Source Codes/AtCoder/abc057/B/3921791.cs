using System;
using System.Collections.Generic;

namespace ABC057_B_Checkpoints
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int n = int.Parse(input[0]);
			int m = int.Parse(input[1]);
			List<int> aList = new List<int>(n);
			List<int> bList = new List<int>(n);
			for (int i = 0; i < n; i++)
			{
				input = Console.ReadLine().Split(' ');
				aList.Add(int.Parse(input[0]));
				bList.Add(int.Parse(input[1]));
			}
			List<int> cList = new List<int>(m);
			List<int> dList = new List<int>(m);
			for (int i = 0; i < m; i++)
			{
				input = Console.ReadLine().Split(' ');
				cList.Add(int.Parse(input[0]));
				dList.Add(int.Parse(input[1]));
			}

			int checkPointIndex;
			int minLength;
			for (int index = 0; index < n; index++)
			{
				checkPointIndex = 0;
				minLength = Math.Abs(aList[index] - cList[0]) + Math.Abs(bList[index] - dList[0]);
				for (int j = 1; j < m; j++)
				{
					int length = Math.Abs(aList[index] - cList[j]) + Math.Abs(bList[index] - dList[j]);
					if (minLength > length)
					{
						minLength = length;
						checkPointIndex = j;
					}
				}
				
				Console.WriteLine(checkPointIndex + 1); //???????0???????+1
			}
		}
	}
}