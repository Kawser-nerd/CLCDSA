using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam16._1C._2
{
	class Program
	{
		static void Main(string[] args)
		{
			using (var input = new StreamReader("in"))
			using (var output = new StreamWriter("out"))
			{
				var cases = int.Parse(input.ReadLine());
				for (var i = 0; i < cases; i++)
				{
					var l = input.ReadLine().Split(' ').Take(2).Select(long.Parse).ToArray();
					long b = l[0], m = l[1];
					var max = (long) Math.Pow(2, l[0] - 2);
					if (m > max)
					{
						output.WriteLine($"Case #{i + 1}: IMPOSSIBLE");
					}
					else
					{
						output.WriteLine($"Case #{i + 1}: POSSIBLE");
						output.Write(0);
						var current = max/2;
						for (var j = 0; j < b - 1; j++)
						{
							if (m >= current)
							{
								m -= current;
								output.Write(1);
							}
							else
							{
								output.Write(0);
							}
							current = current/2;
							if (current < 1)
							{
								current = 1;
							}
						}
						output.WriteLine();
						for (var j = 0; j < b - 1; j++)
						{
							for (var k = 0; k < j + 2; k++)
							{
								output.Write(0);
							}
							for (var k = 0; k < b - j - 2; k++)
							{
								output.Write(1);
							}
							output.WriteLine();
						}
					}
				}
			}
		}
	}
}
