using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P3
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
								var X = new long[N];
								var Y = new long[N];
								for (int i = 0; i < N; i++)
								{
									s = reader.ReadLine();
									var parts = s.Split(' ');
									X[i] = int.Parse(parts[0]);
									Y[i] = int.Parse(parts[1]);
								}
								var mins = new int[N];
								if (N != 1)
								{
									for (int i = 0; i < N; i++)
									{
										mins[i] = int.MaxValue;
									}
								}
								for (int i = 0; i < N; i++)
								{
									for (int j = i + 1; j < N; j++)
									{
										long A = Y[j] - Y[i], B = X[i] - X[j], C;
										C = -(A * X[i] + B * Y[i]);
										if (A * X[i] + B * Y[i] + C != 0 || A * X[j] + B * Y[j] + C != 0)
										{
											throw new Exception();
										}
										var pos = 0;
										var neg = 0;
										for (var k = 0; k < N; k++)
										{
											var v = A * X[k] + B * Y[k] + C;
											if (v > 0)
											{
												pos++;
											}
											if (v < 0)
											{
												neg++;
											}
										}
										var min = Math.Min(pos, neg);
										if (min < mins[i])
										{
											mins[i] = min;
										}
										if (min < mins[j])
										{
											mins[j] = min;
										}
									}
								}
								writer.WriteLine(String.Format("Case #{0}:", t));
								for (int i = 0; i < N; i++)
								{
									writer.WriteLine(mins[i]);
								}
							}
						}
					}
				}
			}
		}
	}
}