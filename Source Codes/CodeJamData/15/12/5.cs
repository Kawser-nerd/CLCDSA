using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P2
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
								var parts = s.Split(' ');
								var B = long.Parse(parts[0]);
								var N = long.Parse(parts[1]);
								s = reader.ReadLine();
								var M = s.Split(' ').Select(x => long.Parse(x)).ToArray();
								var h = N * M.Min();
								long l = 0;
								while (h > l)
								{
									long serves = 0;
									var m = l + (h - l) / 2;
									for (int i = 0; i < B; i++)
									{
										serves += m / M[i];
										serves++;
									}
									if (serves < N)
									{
										l = m + 1;
									}
									else
									{
										h = m;
									}
								}
								long coTimers;
								if (h == 0)
								{
									coTimers = N;
								}
								else
								{
									long currentServes = 0, prevserves = 0;
									for (int i = 0; i < B; i++)
									{
										currentServes += h / M[i];
										prevserves += (h - 1) / M[i];
										currentServes++;
										prevserves++;
									}
									coTimers = N - prevserves;
								}

								var first = -1;
								for (int i = 0; i < B; i++)
								{
									if (h % M[i] == 0)
									{
										coTimers--;
										if (coTimers == 0)
										{
											first = i;
											break;
										}
									}
								}
								if (first == -1)
								{
									throw new Exception();
								}
								writer.WriteLine(String.Format("Case #{0}: {1}", t, first + 1));
							}
						}
					}
				}
			}
		}
	}
}