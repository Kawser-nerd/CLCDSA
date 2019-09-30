using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1b
{
	class ProgramB
	{
		static int ReadIntLine()
		{
			string line = Console.ReadLine();
			return int.Parse(line);
		}

		static int?[] coders, jammers;
		static long result, resultCoders, resultJammers;


		static void r(int i, long c, long j)
		{
			if (i == coders.Length)
			{
				var diff = Math.Abs(c - j);
				if (diff < result || (diff == result && c < resultCoders) || (diff == result && c == resultCoders && j < resultJammers))
				{
					result = diff;
					resultCoders = c;
					resultJammers = j;
				}
			}
			else
			{
				c *= 10;
				j *= 10;
				if(coders[i].HasValue && jammers[i].HasValue)
				{
					r(i + 1, c + coders[i].Value, j + jammers[i].Value);
				}
				else if(coders[i] == jammers[i])
				{
					if(c < j)
					{
						r(i + 1, c + 9, j);
					}
					else if (c > j) { 
						r(i + 1, c, j + 9);
					}
					else { 
						r(i + 1, c, j);
						r(i + 1, c + 1, j);
						r(i + 1, c, j + 1);
					}
				}
				else if(!coders[i].HasValue)
				{
					if (c < j)
					{
						r(i + 1, c + 9, j + jammers[i].Value);
					}
					else if (c > j)
					{
						r(i + 1, c, j + jammers[i].Value);
					}
					else
					{
						r(i + 1, c + jammers[i].Value, j + jammers[i].Value);
						if(jammers[i].Value < 9)
							r(i + 1, c + jammers[i].Value + 1, j + jammers[i].Value);
						if (jammers[i].Value > 0)
							r(i + 1, c + jammers[i].Value - 1, j + jammers[i].Value);
					}
				}
				else if(!jammers[i].HasValue)
				{
					if (c < j)
					{
						r(i + 1, c + coders[i].Value, j);
					}
					else if (c > j)
					{
						r(i + 1, c + coders[i].Value, j + 9);
					}
					else
					{
						r(i + 1, c + coders[i].Value, j + coders[i].Value);
						if (coders[i].Value < 9)
							r(i + 1, c + coders[i].Value, j + coders[i].Value + 1);
						if (coders[i].Value > 0)
							r(i + 1, c + coders[i].Value, j + coders[i].Value - 1);
					}
				}
			}
		}

		static string pad(long n)
		{
			string r = n.ToString();
			while(r.Length < coders.Length)
			{
				r = "0" + r;
			}
			return r;
		}

		static void Main()
		{

			int T = ReadIntLine();

			for (int t = 1; t <= T; t++)
			{
				string[] line = Console.ReadLine().Split(' ');
				coders = line[0].Trim().Select(x => x == '?' ? (int?)null : (int?)int.Parse(x.ToString())).ToArray();
				jammers = line[1].Trim().Select(x => x == '?' ? (int?)null : (int?)int.Parse(x.ToString())).ToArray();

				result = long.MaxValue;
				resultCoders = long.MaxValue;
				resultJammers = long.MaxValue;

				r(0, 0, 0);

				Console.WriteLine("Case #" + t + ": " + pad(resultCoders) + " " + pad(resultJammers));
			}
		}
	}
}
