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
			var tribonacci = new List<double>();

			tribonacci.Add(0);
			tribonacci.Add(0);
			tribonacci.Add(1);
			for (int i = 3; i < number; i++)
			{
				tribonacci.Add((tribonacci[i - 3] + tribonacci[i - 2] + tribonacci[i - 1])%10007.0);
			}
			Console.WriteLine(tribonacci[number-1]);
		}
	}
}