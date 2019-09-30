using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace NumberSets
{
	class Program
	{
		static void Main(string[] args)
		{
			StreamReader sr = new StreamReader(@"c:\temp\b-small-attempt0.in");
			StreamWriter sw = new StreamWriter(@"c:\temp\b.out");
//			TextWriter sw = Console.Out;


			Primes primes = new Primes(10000000);

			int N = int.Parse(sr.ReadLine());
			for (int caseNo = 1; caseNo <= N; caseNo++)
			{
				string s = sr.ReadLine();
				string[] split = s.Split(' ');
				long A = long.Parse(split[0]);
				long B = long.Parse(split[1]);
				long P = long.Parse(split[2]);

				bool[] done = new bool[B - A + 1];

				List<long>[] factors = new List<long>[B - A + 1];
				int noSets = 0;
				for (long i = A; i <= B; i++)
				{
					factors[i-A] = new List<long>();
					long[] ff = primes.GetUniquePrimeFactors(i);
					foreach (var f in ff)
						if (f >= P)
							factors[i-A].Add(f);
					if (factors[i-A].Count == 0)
					{
						done[i - A] = true;
						noSets++;
					}
				}

				for (long i = A; i <= B; i++)
				{
					if (done[i-A])
						continue;

					noSets++;
					done[i - A] = true;
					bool rerun = true;
					HashSet<long> setFactors = new HashSet<long>(factors[i - A]);
					while (rerun)
					{
						rerun = false;
						for (long j = i + 1; j <= B; j++)
						{
							if (!done[j - A])
							{
								bool include = false;
								foreach (var f in factors[j-A])
								{
									if (setFactors.Contains(f))
										include = true;
								}
								if (include)
								{
									done[j - A] = true;
									foreach (var f in factors[j-A]) 
										if (setFactors.Add(f))
											rerun = true;
								}
							}
						}
					}
				}
				sw.WriteLine("Case #" + caseNo + ": " + noSets);
			}
			sw.Close();
		}
	}


	public class Primes
	{
		public readonly List<long> PrimeList;

		private long maxPrime;
		private byte[] _sieve;

		public Primes(int largestSieve)
		{
			maxPrime = largestSieve + (largestSieve & 1);
			PrimeList = new List<long>();
			PrimeList.Add(2);
			_sieve = new byte[maxPrime / 16 + 2];
			_sieve[0] = 1;
			for (long i = 1; i < maxPrime / 2; i++)
				if ((_sieve[i >> 3] & (1 << ((int)i & 7))) == 0)
				{
					PrimeList.Add(i * 2 + 1);
					for (long j = i + i + i + 1; j < maxPrime / 2; j += i + i + 1)
						_sieve[j >> 3] |= (byte)(1 << ((int)j & 7));
				}
		}

		public bool IsPrime(long value)
		{
			if (value == 2)
				return true;
			if (value < 2 || (value % 2) == 0)
				return false;
			if (value <= maxPrime)
				return (_sieve[value >> 4] & (1 << (((int)value >> 1) & 7))) == 0;
			if (value > maxPrime * maxPrime)
				throw new ArgumentException("Value too large.");
			foreach (long p in PrimeList)
			{
				if (p * p > value)
					return true;
				if (value % p == 0)
					return false;
			}
			return true;
		}

		public long[] GetAllPrimeFactors(long value)
		{
			if (value < 2)
				return new long[0];
			List<long> factors = new List<long>();
			for (int i = 0; i < PrimeList.Count && value > 1; i++)
			{
				long p = PrimeList[i];
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

		public long[] GetUniquePrimeFactors(long value)
		{
			long[] allPrimeFactors = GetAllPrimeFactors(value);
			List<long> unique = new List<long>();
			foreach (long p in allPrimeFactors)
				if (unique.Count == 0 || p != unique[unique.Count - 1])
					unique.Add(p);
			return unique.ToArray();
		}
	}
}
