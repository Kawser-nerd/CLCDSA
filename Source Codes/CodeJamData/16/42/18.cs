using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Beresta
{

	class ContestIO : StreamWriter
	{
		public ContestIO(Stream streamIn, Stream streamOut) : base(streamOut, Encoding.ASCII, 8192) { Reader = new StreamReader(streamIn, Encoding.ASCII, false, 8192); }
		public ContestIO(string inputFilePath, string outputFilePath) : this(File.OpenRead(inputFilePath), File.OpenWrite(outputFilePath)) { }
		public ContestIO(string inputText) : this(new MemoryStream(Encoding.ASCII.GetBytes(inputText)), Console.OpenStandardOutput(8192)) { }
		public ContestIO() : this(Console.OpenStandardInput(8192), Console.OpenStandardOutput(8192)) { }
		//d.ToString("N12", CultureInfo.InvariantCulture).Replace(",", "")
		public StreamReader Reader;
		
		bool IsDigit(int c) { return c >= '0' && c <= '9'; }
		public long Read()
		{
			int c1 = 0, c;
			while (!IsDigit(c = Reader.Read())) { c1 = c; }
			long r = c - '0';
			while (IsDigit(c = Reader.Read()))
				r = r * 10 + c - '0';
			return c1 == '-' ? -r : r;
		}
		public long[] ReadArray(int size) { return Enumerable.Range(0, size).Select(v => Read()).ToArray(); }
	}

	class Comparer1 : IComparer<decimal>
	{
		public int Compare(decimal x, decimal y)
		{
			return Convert(x).CompareTo(Convert(y));
		}

		decimal Convert(decimal value)
		{
			var res = value - 0.5m;
			if (res < 0)
				res = -res;
			return res;
		}
	}
	class Comparer2 : IComparer<decimal>
	{
		public int Compare(decimal x, decimal y)
		{
			return -x.CompareTo(y);
		}
	}

	class Program
	{

		static void Main(string[] args)
		{
			using (var io = new ContestIO(@"D:\Contests\input\GCJ2016_R2_B\B-small-attempt2.in", @"D:\Contests\input\GCJ2016_R2_B\B-small-attempt2.out"))
			{
				var t = io.Read();
				for (var i = 0; i < t; i++)
				{
					var n = io.Read();
					var k = io.Read();
					var arr = new decimal[n];
					for (var j = 0; j < n; j++)
					{
						var pi1 = io.Read();
						var pi2 = io.Read();
						
						decimal pi = pi2;
						pi /= 100;
						pi += pi1;
						arr[j] = pi;
					}

					var res1 = Solve(n, k, arr.ToArray(), false);
					var res2 = Solve(n, k, arr.ToArray(), true);
					var res3 = SolveBF(n, k, arr.ToArray());

					var delta = Math.Abs(res3 - res2);
					//if (delta > Eps)
					//    throw new Exception();

					io.WriteLine(string.Format("Case #{0}: {1}", (i + 1), res3.ToString("N12", CultureInfo.InvariantCulture).Replace(",", "")));
				}
			}

			//Console.ReadLine();
		}

		static decimal SolveBF(long n, long k, decimal[] arr)
		{
			return SolveBFPick(n, k, k, 0, arr, new bool[n]);
		}
		static decimal SolveBFPick(long n, long k, long count, long pos, decimal[] arr, bool[] picked)
		{
			if (count == 0)
			{
				var subArr = new decimal[k];
				var index = 0;
				for (var i = 0; i < n; i++)
				{
					if (picked[i])
						subArr[index++] = arr[i];
				}

				return SolveBFCalcProb(k, subArr);
			}
			else
			{
				var best = 0m;
				for (var i = pos; i < n; i++)
				{
					picked[i] = true;
					var cur = SolveBFPick(n, k, count - 1, i + 1, arr, picked);
					if (cur > best)
						best = cur;
					picked[i] = false;
				}
				return best;
			}
		}
		static decimal SolveBFCalcProb(long k, decimal[] arr)
		{
			return Place(k, 0, k / 2, new bool[k], arr, true);
		}

		static decimal Solve(long n, long k, decimal[] arr, bool testAll)
		{
			var count0 = arr.Count(v => v == 0.0m);
			var count1 = arr.Count(v => v == 1.0m);
			var both = Math.Min(count0, count1);

			count0 = both;
			count1 = both;
			both *= 2;

			if (both >= k)
				return 1;

			if (both > 0)
			{
				decimal[] arr2 = new decimal[n - both];
				var index = 0;
				for (var i = 0; i < n; i++)
				{
					var val = arr[i];
					if (val == 0m)
					{
						if (count0 > 0)
						{
							count0--;
							continue;
						}
					}
					else if (val == 1m)
					{
						if (count1 > 0)
						{
							count1--;
							continue;
						}
					}

					arr2[index++] = val;
				}

				return Solve(n - both, k - both, arr2, testAll);
			}
			else
			{
				Array.Sort(arr, new Comparer1());
				arr = arr.Take((int)k).ToArray();
				Array.Sort(arr, new Comparer2());
				return Place(k, 0, k / 2, new bool[k], arr, testAll);
			}
		}

		const decimal Eps = 0.000000000000000001m;

		static decimal Place(long k, long pos, long count, bool[] type, decimal[] arr, bool testAll)
		{
			if (count == 0)
				return GetProb(type, arr);
			else
			{
				var prob = 0m;

				for (var i = pos; i < k; i++)
				{
					type[i] = true;

					var probI = Place(k, i + 1, count - 1, type, arr, testAll);
					if (!testAll && probI < Eps)
						break;
					prob += probI;

					type[i] = false;
				}

				return prob;
			}
		}

		static decimal GetProb(bool[] type, decimal[] arr)
		{
			var prob = 1m;
			for (var i = 0; i < arr.Length; i++)
			{
				if (type[i])
					prob *= arr[i];
				else
					prob *= (1m - arr[i]);
			}
			return prob;
		}

	}

}
