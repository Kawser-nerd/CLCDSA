using System;
using System.IO;
using System.Linq;

namespace D
{
	internal class Program
	{
		private static bool[] isPrime;
		private static bool[] isLike2017;
		private static int[] like2017Num; // primeNum[i] ? 1--i ???????????????
		private const int Max = 100000;

		public static void Main(string[] args)
		{
			var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };

			initIsPrime();
			initIsLike2017();
			initLike2017Num();

			var q = int.Parse(Console.ReadLine());
			for (var i = 0; i < q; i++)
			{
				var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
				var lq = line[0];
				var rq = line[1];


				sw.WriteLine(like2017Num[rq] - like2017Num[lq - 1]);
			}

			sw.Flush();
		}

		static void initIsPrime()
		{
			isPrime = new bool[Max + 1];
			for (var i = 0; i <= Max; i++) { isPrime[i] = true; }

			isPrime[0] = isPrime[1] = false;
			for (var i = 2; i <= Max; i++)
			{
				if (isPrime[i])
				{
					for (var j = 2 * i; j <= Max; j += i) { isPrime[j] = false; }
				}
			}
		}

		static void initIsLike2017()
		{
			isLike2017 = new bool[Max + 1];
			for (var i = 0; i * 2 < Max; i++)
			{
				if (!isPrime[i]) { continue; }

				if (isPrime[2 * i - 1]) { isLike2017[2 * i - 1] = true; }
			}
		}

		static void initLike2017Num()
		{
			like2017Num = new int[Max + 1];
			like2017Num[0] = 0;
			for (var i = 1; i < Max; i++) { like2017Num[i] = like2017Num[i - 1] + (isLike2017[i] ? 1 : 0); }
		}
	}
}