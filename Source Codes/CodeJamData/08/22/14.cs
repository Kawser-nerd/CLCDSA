using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace NumberSets
{
	class Program
	{
		static void Main(string[] args)
		{
			string filename = "B-small-attempt0";
			//string filename = "A-large";

			TextReader reader = new StreamReader(filename + ".in");
			TextWriter writer = new StreamWriter(filename + ".out");

			int numCases = int.Parse(reader.ReadLine());

			for (int i = 0; i < numCases; i++)
			{
				string[] s = reader.ReadLine().Split(' ');
				int start = int.Parse(s[0]);
				int end = int.Parse(s[1]);
				int p = int.Parse(s[2]);

				List<List<int>> lists = new List<List<int>>();
				for(int n = start; n<=end;n++)
				{
					List<int> l = new List<int>();
					l.Add(n);
					lists.Add(l);
				}
				List<int> primes = GetPrimes(p, end);
				FindAnswer(lists, primes);
				writer.WriteLine("Case #" + (i + 1) + ": " + lists.Count);
			}

			reader.Close();
			writer.Close();
		}

		static void FindAnswer(List<List<int>> sets, List<int> primes)
		{
			if (primes.Count == 0)
			{
				return;
			}
			while(primes.Count > 0)
			{
				int p = primes[0];
				for (int i = 0; i < sets.Count; i++)
				{
					for (int j = 0; j < sets.Count; j++)
					{
						if (i != j)
						{
							for (int x = 0; x < sets[i].Count; x++)
							{
								for (int y = 0; y < sets[j].Count; y++)
								{
									if (SharePrime(sets[i][x], sets[j][y], p))
									{
										//Merge
										for (int a = 0; a < sets[j].Count; a++)
										{
											sets[i].Add(sets[j][a]);
										}
										sets.RemoveAt(j);
										FindAnswer(sets, primes);
										return;
									}
								}
							}
						}
					}
				}
				primes.RemoveAt(0);
			}
		}

		static bool SharePrime(int a, int b, int p)
		{
			return (a % p == 0 && b % p == 0);
		}

		static List<int> GetPrimes(int largerThan, int smallerThan)
		{
			List<int> results = new List<int>();
			for (int i = largerThan; i <= smallerThan; i++)
			{
				//Console.WriteLine(i+": "+IsPrime(i));
				if (IsPrime(i))
					results.Add(i);
			}
			return results;
		}

		static bool IsPrime(int n)
		{
			for (int i = 2; i <= Math.Sqrt(n); i++)
			{
				if (n % i == 0)
					return false;
			}
			return true;
		}
	}
}
