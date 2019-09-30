using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1b
{
	class ProgramA
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
			Dictionary<char, string> d = new Dictionary<char, string>();

			d['Z'] = "ZERO";
			d['X'] = "SIX";
			d['S'] = "SEVEN";
         d['W'] = "TWO";
			d['V'] = "FIVE";
			d['G'] = "EIGHT";
			d['I'] = "NINE";
			d['N'] = "ONE";
			d['T'] = "THREE";
			d['F'] = "FOUR";

			char[] ordered = new char[] { 'Z', 'X', 'S', 'W', 'V', 'G', 'I', 'N', 'T', 'F' };
			int[] digits = new int[] { 0, 6, 7, 2, 5, 8, 9, 1, 3, 4 };

			int T = ReadIntLine();

			

			for (int t = 1; t <= T; t++)
			{
				string s = Console.ReadLine().Trim();

				List<int> digitsResult = new List<int>();

				Dictionary<char, int> freq = new Dictionary<char, int>();
				foreach(char c in s)
				{
					if (!freq.ContainsKey(c))
						freq.Add(c, 0);
					freq[c]++;
				}

				string result = "";

				for (int i = 0; i < 10; i++)
				{
					char c = ordered[i];
					int digit = digits[i];

					while(freq.ContainsKey(c) && freq[c] > 0)
					{
						digitsResult.Add(digit);
						foreach(char ch in d[c])
						{
							freq[ch]--;
						}
					}
				}

				foreach(int dd in digitsResult.OrderBy(x => x))
				{
					result += dd;
				}

				Console.WriteLine("Case #" + t + ": " + result);
			}
		}
	}
}
