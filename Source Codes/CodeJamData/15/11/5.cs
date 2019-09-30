using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P1
{
	class Program
	{
		static void Main(string[] args)
		{
			using (var input = new FileStream("in.in", FileMode.Open, FileAccess.Read))
			{
				using (var reader = new StreamReader(input))
				{
					using (var output = new FileStream("out.out", FileMode.Create, FileAccess.Write))
					{
						using (var writer = new StreamWriter(output))
						{
							var s = reader.ReadLine();
							var T = int.Parse(s);
							for (var t = 1; t <= T; t++)
							{
								s = reader.ReadLine();
								var N = int.Parse(s);
								s = reader.ReadLine();
								var v = s.Split(' ').Select(x => int.Parse(x)).ToArray();
								var first = 0;
								var biggest = 0;
								var prev = 0;
								for (int i = 0; i < N; i++)
								{
									if (v[i] < prev)
									{
										first += prev - v[i];
										if (prev - v[i] > biggest)
										{
											biggest = prev - v[i];
										}
									}
									prev = v[i];
								}
								var second = 0;
								prev = 0;
								for (int i = 0; i < N; i++)
								{
									if (prev > biggest)
									{
										second += biggest;
									}
									else
									{
										second += prev;
									}
									prev = v[i];
								}
								writer.WriteLine(String.Format("Case #{0}: {1} {2}", t, first, second));
							}
						}
					}
				}
			}
		}
	}
}