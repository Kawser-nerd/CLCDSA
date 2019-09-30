using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
	class Program
	{
		static void Main(string[] args)
		{
			var input = Console.ReadLine().Split(' ');
			var canWatch = int.Parse(input[1]);

			var teachers = new List<int>();
			input = Console.ReadLine().Split(' ');
			foreach (var rate in input)
			{
				teachers.Add(int.Parse(rate));
			}

			teachers.Sort((a,b) => b-a);
			var buff = teachers.Take(canWatch).ToList();
			buff.Sort();

			var result = 0.0;
			foreach (var rate in buff)
			{
				result = (result + rate) / 2.0;
			}

			Console.WriteLine(result);
			Console.ReadKey();
		}
	}
}