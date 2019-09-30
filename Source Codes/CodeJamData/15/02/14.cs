using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
	class Program
	{

		static void Main(string[] args)
		{
			var input = @"1
1
27";
			input = File.ReadAllText("input.txt");

			var outputStr = Solve(Parse(input));

			Console.WriteLine(outputStr);
			File.WriteAllText(GetFileName(), outputStr);

			//Console.ReadLine();
		}

		static List<long[]> Parse(string input)
		{
			var parts = input.Split(new char[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);
			var testCasesStr = long.Parse(parts[0]);
			List<long[]> testCases = new List<long[]>();
			for (var i = 0; i < testCasesStr; i++)
			{
				var testCaseStr = parts[(i + 1) * 2];
				testCases.Add(testCaseStr.Split(' ').Select(c => long.Parse(c)).ToArray());
			}
			return testCases;
		}

		static string Solve(List<long[]> testCases)
		{
			Init();

			List<string> output = new List<string>();
			for (var i = 0; i < testCases.Count; i++)
			{
				output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(testCases[i])));
			}
			return string.Join(Environment.NewLine, output);
		}

		static Dictionary<long, long> squares;
		static void Init()
		{
			squares = new Dictionary<long, long>();
			for (var i = 3; i <= 40; i++)
				squares.Add(i * i, i);
		}

		static long Solve(long[] arr)
		{
			long max = arr.Max();
			long[] sums = new long[max + 1];
			foreach (long v in arr)
				sums[v]++;

			return Solve(sums, 0, max);
		}
		static long Solve(long[] sums, long ticks, long pos)
		{
			long best = long.MaxValue;
			for (var i = pos; i >= 1; i--)
			{
				if (sums[i] != 0)
				{
					best = Math.Min(best, i + ticks);

					if (squares.ContainsKey(i))
					{
						var newSums = CloneArray(sums);
						var r = squares[i];
						newSums[r] += sums[i] * r;
						var newTicks = ticks + sums[i] * (r - 1);
						newSums[i] = 0;

						best = Math.Min(best, Solve(newSums, newTicks, i - 1));
					}

					var p1 = i / 2;
					var p2 = p1 + i % 2;
					sums[p1] += sums[i];
					sums[p2] += sums[i];
					ticks += sums[i];
					sums[i] = 0;
				}
			}

			return best;
		}
		//static long Solve2(long[] arr)
		//{
		//    long max = arr.Max();
		//    long[] sums = new long[max + 1];
		//    foreach (long v in arr)
		//        sums[v]++;

		//    var t1 = Solve2Internal(sums, 0, false);
		//    var t2 = Solve2Internal(sums, 0, true);
		//    return Math.Min(t1, t2);
		//}
		//static long Solve2Internal(long[] sums, long tick, bool special)
		//{
		//    sums = sums.Select(s => s).ToArray();

		//    if (tick > (sums.Length * 10))
		//    {

		//    }

		//    if (!special)
		//    {
		//        tick++;

		//        for (var i = 0; i < sums.Length - 1; i++)
		//        {
		//            sums[i] = sums[i + 1];
		//        }
		//        sums[0] = 0;
		//        sums[sums.Length - 1] = 0;
		//        if (!sums.Any(s => s > 0))
		//        {
		//            return tick;
		//        }
		//    }
		//    else
		//    {
		//        int pos = -1;
		//        for (var i = sums.Length - 1; i >= 2; i--)
		//        {
		//            if (sums[i] != 0)
		//            {
		//                pos = i;
		//                break;
		//            }
		//        }
		//        if (pos == -1)
		//        {
		//            return long.MaxValue;
		//        }

		//        tick++;
				
		//        var p1 = pos / 2;
		//        var p2 = p1 + pos % 2;
		//        sums[p1]++;
		//        sums[p2]++;
		//        sums[pos]--;

		//        if (!sums.Any(s => s > 0))
		//        {
		//            return tick;
		//        }
		//    }
		//    var t1 = Solve2Internal(sums, tick, false);
		//    var t2 = Solve2Internal(sums, tick, true);
		//    return Math.Min(t1, t2);
		//}

		static T[] CloneArray<T>(T[] arr)
		{
			T[] result = new T[arr.Length];
			Array.Copy(arr, result, arr.Length);
			return result;
		}
		static string GetFileName()
		{
			return DateTime.Now.Ticks.ToString() + ".txt";
		}
	}
}
