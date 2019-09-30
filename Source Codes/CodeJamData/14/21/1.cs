using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
	class Program
	{
		static void Main(string[] args)
		{
			using (StreamReader reader = new StreamReader(@"j:\codejam\ConsoleApplication5\input.txt"))
			{
				using (StreamWriter writer = new StreamWriter(@"j:\codejam\ConsoleApplication5\output.txt"))
				{
					Int32 T = Int32.Parse(reader.ReadLine());
					for (Int32 test = 1; test <= T; ++test)
					{
						Int32 n = Int32.Parse(reader.ReadLine());
						String[] str = new String[n];
						Int32[] pos = new Int32[n];
						Int32[] counts = new Int32[n];
						Int32 ended = 0;
						Boolean correct = true;
						Int32 answer = 0;
						for (Int32 i = 0; i < n; ++i)
						{
							str[i] = reader.ReadLine();
							pos[i] = 0;
							counts[i] = 0;
						}

						while (ended < n)
						{
							char current = str[0][pos[0]];
							int sum = 0;
							for (Int32 i = 0; i < n; ++i)
							{
								counts[i] = 0;
								while (pos[i] < str[i].Length && str[i][pos[i]] == current)
								{
									++counts[i];
									++pos[i];
								}
								if (counts[i] == 0)
								{
									correct = false;
									break;
								}
								if (pos[i] == str[i].Length)
									++ended;
								sum += counts[i];
							}

							if (!correct || (ended != 0 && ended != n))
							{
								correct = false;
								break;
							}

							Int32 average = sum / n;
							Int32 start = Math.Max(average - 2, 1);

							Int32 min = Int32.MaxValue;
							for (Int32 i = start; i <= average + 2; ++i)
							{
								Int32 temp = 0;
								for (Int32 j = 0; j < n; ++j)
									temp += i < counts[j] ? counts[j] - i : i - counts[j];

								if (min > temp)
									min = temp;
							}

							answer += min;
						}


						if (!correct)
							writer.WriteLine("Case #" + test + ": Fegla Won");
						else
							writer.WriteLine("Case #" + test + ": " + answer);
					}
				}
			}
		}
	}
}
