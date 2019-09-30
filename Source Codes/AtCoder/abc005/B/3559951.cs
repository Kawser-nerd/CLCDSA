using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
	class Program
	{
		static void Main(string[] args)
		{
			var number = int.Parse(Console.ReadLine());
			var times = new List<int>();

			for (int i = 0; i < number; i++)
			{
				times.Add(int.Parse(Console.ReadLine()));
			}

			times.Sort((a, b) => b - a);
			Console.WriteLine(times.Min());
		}
	}
}