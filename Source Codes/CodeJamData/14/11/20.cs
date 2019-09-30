using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApplication2
{
	class Program
	{
		static void Main(string[] args)
		{
			System.Globalization.CultureInfo customCulture = (System.Globalization.CultureInfo)System.Threading.Thread.CurrentThread.CurrentCulture.Clone();
			customCulture.NumberFormat.NumberDecimalSeparator = ".";
			System.Threading.Thread.CurrentThread.CurrentCulture = customCulture;

			using (StreamReader reader = new StreamReader(@"j:\codejam\ConsoleApplication3\input.txt"))
			{
				using (StreamWriter writer = new StreamWriter(@"j:\codejam\ConsoleApplication3\output.txt"))
				{
					Int32 T = Int32.Parse(reader.ReadLine());
					for (Int32 test = 1; test <= T; ++test)
					{
						String[] main = reader.ReadLine().Split(' ');
						Int32 N = Int32.Parse(main[0]);
						Int32 L = Int32.Parse(main[1]);
						String[] outlets = reader.ReadLine().Split(' ');
						String[] devices = reader.ReadLine().Split(' ');
						Char[][] temp = new Char[N - 1][];
						String[] temp2 = new String[N - 1];
						Int32 bestSolution = L + 1;

						Array.Sort(devices);

						for (Int32 i = 0; i < N; ++i)
						{
							Int32 currentSolution = 0;
							Boolean isEqual = true;

							for (Int32 j = 0, l = 0; j < N ; ++j)
								if (i != j)
									temp[l++] = outlets[j].ToCharArray();

							for (Int32 j = 0; j < L; ++j)
							{
								if (devices[0][j] != outlets[i][j])
								{
									for (Int32 l = 0; l < N - 1; ++l)
										temp[l][j] = temp[l][j] == '1' ? '0' : '1';
									++currentSolution;
								}
							}

							for (Int32 j = 0; j < N - 1; ++j)
								temp2[j] = new String(temp[j]);

							Array.Sort(temp2);

							for (Int32 j = 0; j < N - 1; ++j)
								if (temp2[j].CompareTo(devices[j + 1]) != 0)
								{
									isEqual = false;
									break;
								}

							if (isEqual && bestSolution > currentSolution)
							{
								bestSolution = currentSolution;
							}
						}

						if (bestSolution == L + 1)
							writer.WriteLine("Case #" + test + ": NOT POSSIBLE");
						else
							writer.WriteLine("Case #" + test + ": " + bestSolution);
					}
				}
			}
		}
	}
}
