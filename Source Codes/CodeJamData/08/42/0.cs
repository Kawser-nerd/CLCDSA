using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace TriangleAreas
{
	class Program
	{
		static void Main(string[] args)
		{
//			StreamReader sr = new StreamReader(@"c:\temp\b.in");
			StreamReader sr = new StreamReader(@"c:\temp\B-small-attempt0.in");
			StreamWriter tw = new StreamWriter(@"c:\temp\b.out");
//			TextWriter tw = Console.Out;

			Primes p = new Primes(100000);

			int noCases = int.Parse(sr.ReadLine());
			for (int caseNo = 1; caseNo <= noCases; caseNo++)
			{
				Console.Error.WriteLine("Working on case " + caseNo);
				string[] split = sr.ReadLine().Split(' ');
				int xsize = int.Parse(split[0]), ysize = int.Parse(split[1]);
				int area = int.Parse(split[2]);

//				int[] factors = p.GetAllPrimeFactors(area);
//				var bases = new HashSet<int>();
//				bases.Add(1);
//				GenerateBases(factors, bases, 0, 1, Math.Max(xsize, ysize));

//				int[] bList = bases.ToArray();
//				Array.Sort(bList);

				int[] ans;
				ans = Solve(xsize, ysize, area);
				/*if (ans == null)
				{
					Solve(ysize, xsize, area, bList, ref ans);
					for (int i = 0; i < 3; i++)
					{
						int tmp = ans[i*2];
						ans[i*2] = ans[i*2 + 1];
						ans[i*2 + 1] = tmp;
					}
				}*/
				tw.Write("Case #" + caseNo + ":");
				if (ans == null)
					tw.WriteLine(" IMPOSSIBLE");
				else
				{
					for (int i = 0; i < 6; i++)
						tw.Write(" " + ans[i]);
					tw.WriteLine();
				}
			}
			tw.Close();
		}

		private static int[] Solve(int xsize, int ysize, int area)
		{
			for (int y0 = 0; y0 <= ysize; y0++)
			{
				for (int x1 = 0; x1 <= xsize; x1++)
				{
					if (x1==0 && y0 == 0)
						continue;
					if (x1 == 0)
					{
						int b = y0;
						if (area%b != 0)
							continue;
						int x2 = area/b;
						int y2 = 0;
						if (x2 >= 0 && x2 <= xsize)
							return new int[] {0, y0, x1, 0, x2, y2};
						continue;
					}

					for (int x2 = 0; x2 <= xsize; x2++)
					{
						int t = area + x1*y0 - x2*y0;
						if (t%x1 == 0)
						{
							int y2 = t/x1;
							if (y2 >= 0 && y2 <= ysize)
							{
								return new int[] {0, y0, x1, 0, x2, y2};
							}
						}
					}
				}
			}
			return null;
		}

		private static void GenerateBases(int[] factors, HashSet<int> bases, int current, int b, int max)
		{
			if (current == factors.Length)
				return;
			int x = b*factors[current];
			if (x <= max)
			{
				bases.Add(x);
				GenerateBases(factors, bases, current + 1, x, max);
			}
			GenerateBases(factors, bases, current + 1, b, max);
		}
	}


	public class Primes
	{
		public readonly List<int> PrimeList;

		private int maxPrime;
		private byte[] _sieve;

		public Primes(int largestSieve)
		{
			maxPrime = largestSieve + (largestSieve & 1);
			PrimeList = new List<int>();
			PrimeList.Add(2);
			_sieve = new byte[maxPrime / 16 + 2];
			_sieve[0] = 1;
			for (int i = 1; i < maxPrime / 2; i++)
				if ((_sieve[i >> 3] & (1 << (i & 7))) == 0)
				{
					PrimeList.Add(i * 2 + 1);
					for (int j = i + i + i + 1; j < maxPrime / 2; j += i + i + 1)
						_sieve[j >> 3] |= (byte)(1 << (j & 7));
				}
		}

		public bool IsPrime(int value)
		{
			if (value == 2)
				return true;
			if (value < 2 || (value % 2) == 0)
				return false;
			if (value <= maxPrime)
				return (_sieve[value >> 4] & (1 << ((value >> 1) & 7))) == 0;
			if (value > ((long)maxPrime) * maxPrime)
				throw new ArgumentException("Value too large.");
			foreach (int p in PrimeList)
			{
				if (((long)p) * p > value)
					return true;
				if (value % p == 0)
					return false;
			}
			return true;
		}

		public int[] GetAllPrimeFactors(int value)
		{
			if (value < 2)
				return new int[0];
			List<int> factors = new List<int>();
			for (int i = 0; i < PrimeList.Count && value > 1; i++)
			{
				int p = PrimeList[i];
				while (value % p == 0)
				{
					factors.Add(p);
					value /= p;
				}
			}
			if (value <= ((long)maxPrime) * maxPrime)
			{
				if (value > 1)
					factors.Add(value);
				return factors.ToArray();
			}
			throw new ArgumentException(value + " has too large prime factors.");
		}

		public int[] GetUniquePrimeFactors(int value)
		{
			int[] allPrimeFactors = GetAllPrimeFactors(value);
			List<int> unique = new List<int>();
			foreach (int p in allPrimeFactors)
				if (unique.Count == 0 || p != unique[unique.Count - 1])
					unique.Add(p);
			return unique.ToArray();
		}
	}
}
