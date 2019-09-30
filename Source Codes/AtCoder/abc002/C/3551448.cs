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
			//????3??????
			var input = Console.ReadLine().Split(' ');
			var number = new List<int>();
			foreach (var item in input)
			{
				number.Add(int.Parse(item));
			}
			var crdin = new List<int[]>();
			for (int i = 0; i < 3; i++)
			{
				var buff = number.Skip(i * 2).Take(2);
				crdin.Add(buff.ToArray());
			}

			//(0, 0), (a, b), (c, d)?????
			var minus = crdin[0];
			for (int i = 0; i < crdin.Count; i++)
			{
				var buff = new int[] { crdin[0][0] - minus[0], crdin[0][1] - minus[1] };
				crdin.RemoveAt(0);
				crdin.Add(buff);
			}

			//?????
			double result = Math.Abs(crdin[1][0] * crdin[2][1] - crdin[1][1] * crdin[2][0]) / 2.0;
			Console.WriteLine(result);
		}
	}
}