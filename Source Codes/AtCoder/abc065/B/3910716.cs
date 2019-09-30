using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC065_B_Trained
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			List<int> aList = new List<int>(n);
			for(int i = 0; i < n; i++)
				aList.Add(int.Parse(Console.ReadLine()));

			int index = 1;
			int count = 0;
			//???????????????
			while (count <= n)
			{
				if (index == 2) break;
				
				index = aList[index - 1];
				count++;
			}
			
			if(index == 2) Console.WriteLine(count);
			else Console.WriteLine(-1);
			
			/*???????????
			List<int> pushedButtonIndex = new List<int>();
			while (index != 2)
			{
				if (pushedButtonIndex.Any(value => value == index))
				{
					Console.WriteLine(-1);
					return;
				}
				
				pushedButtonIndex.Add(index);
				index = aList[index - 1];
				count++;
			}
			
			Console.WriteLine(count);*/
		}
	}
}