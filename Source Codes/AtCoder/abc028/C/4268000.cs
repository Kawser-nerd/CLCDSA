using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleAppNumSelect
{
	class Program
	{
		static void Main(string[] args)
		{
			string pattern = Console.ReadLine();
			var items = pattern.Split(' ').Select(p => int.Parse(p)).ToArray();
			//???
			HashSet<int> sumVals = new HashSet<int>();
			for (int i = 0; i < items.Length-2; i++)
			{
				for (int j = i+1; j < items.Length-1; j++)
				{
					for (int k = j+1; k < items.Length; k++)
					{
						int sumVal = items[i] + items[j] + items[k];
						sumVals.Add(sumVal);
					}
				}
			}
			//????
			var sortVals = sumVals.OrderBy(s => s).ToList();
			string output = sortVals[sortVals.Count - 3].ToString();
			Console.WriteLine(output);
		}
	}
}