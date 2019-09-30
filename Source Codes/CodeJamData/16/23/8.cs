using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1b
{
	class ProgramC
	{
		static int ReadIntLine()
		{
			string line = Console.ReadLine();
			return int.Parse(line);
		}


		static int[] ReadIntsLine()
		{
			string line = Console.ReadLine();
			return line.Trim().Split(' ').Select(x => int.Parse(x)).ToArray();
		}

		static void Main()
		{

			int T = ReadIntLine();

			for (int t = 1; t <= T; t++)
			{
				int result = 0;

				int N = ReadIntLine();

				int lookupI = 0;
				var lookup = new Dictionary<string, int>();
				int[] first = new int[N];
				int[] second = new int[N];

				for(int n = 0; n < N; n++)
				{
					string[] line = Console.ReadLine().Split(' ');
					foreach(string s in line)
					{
						if(!lookup.ContainsKey(s))
						{
							lookup[s] = lookupI;
							lookupI++; 
						}
					}
					first[n] = lookup[line[0]];
					second[n] = lookup[line[1]];
				}

				int[] counterFirst = new int[lookup.Count];
				foreach (int i in first)
					counterFirst[i]++;
				int[] counterSecond = new int[lookup.Count];
            foreach (int i in second)
					counterSecond[i]++;



				int set = 0;
				int maxSet = (1 << N);

				int[] usedFirst = new int[lookup.Count];
				int[] usedSecond = new int[lookup.Count];
				for (int s = 0; s < maxSet; s++)
				{
					Array.Clear(usedFirst, 0, usedFirst.Length);
					Array.Clear(usedSecond, 0, usedSecond.Length);
					for (int i = 0; i < N; i++)
					{
						if((s & (1 << i)) != 0)
						{
							usedFirst[first[i]]++;
							usedSecond[second[i]]++;
						}
					}

					bool ok = true;
					int c = 0;
					for(int i = 0; i < usedFirst.Length; i++)
					{
						c += usedFirst[i];
						if(usedFirst[i] > 0 && usedFirst[i] >= counterFirst[i])
						{
							ok = false;
							break;
						}
						if (usedSecond[i] > 0 && usedSecond[i] >= counterSecond[i])
						{
							ok = false;
							break;
						}
					}

					if(ok)
					{
						result = Math.Max(result, c);
					}
				}

				Console.WriteLine("Case #" + t + ": " + result);
			}
		}
	}
}
