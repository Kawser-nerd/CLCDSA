using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
namespace Practice
{
	class Program
	{
		static void Main(string[] args)
		{
			Solve();
		}
		private const int MOD = 1000000007;
		private class Info
		{
			public int id;
			public int score;
			public int rank;
			public Info(int id, int score)
			{
				this.id = id;
				this.score = score;
			}
		}
		static void Solve()
		{
			var a = ReadAndParseInt();
			var b = ReadAndParseInt();
			var c = ReadAndParseInt();
			var list = new List<Info>();
			list.Add(new Info(0, a));
			list.Add(new Info(1, b));
			list.Add(new Info(2, c));
			list.Sort((x, y) => y.score.CompareTo(x.score));
			for(int i=0;i<list.Count;++i)
			{
				list[i].rank = i+1;
			}

			list.Sort((x, y) => x.id.CompareTo(y.id));
			foreach(var info in list)
			{
				Console.WriteLine(info.rank);
			}
		}
		#region ????????
		private static bool isPrime(long x)
		{
			if(x == 2) { return true; }
			if(x < 2 || x % 2 == 0) { return false; }
			long i = 3;
			while(i * i <= x)
			{
				if(x % i == 0) { return false; }
				i = i + 2;
			}
			return true;
		}
		private static long lcm(long x, long y)
		{
			return x / gcd(x, y) * y;
		}
		private static long gcd(long x, long y)
		{
			return y > 0 ? gcd(y, x % y) : x;
		}
		private static long pow(long x, long n)
		{
			if(n == 0) { return 1; }
			long res = pow(x * x % MOD, n / 2);
			if(n % 2 == 1)
			{
				res = res * x % MOD;
			}
			return res;
		}
		private static int ReadAndParseInt()
		{
			return int.Parse(Console.ReadLine());
		}
		private static int[] ReadAndParseIntArr()
		{
			return Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
		}
		private static long ReadAndParseLong()
		{
			return long.Parse(Console.ReadLine());
		}
		private static long[] ReadAndParseLongArr()
		{
			return Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse);
		}

		/// <summary>
		/// ???????????????????
		/// </summary>
		/// <typeparam name="T">???????</typeparam>
		/// <param name="arr">??????????????????</param>
		/// <param name="start">??????? [inclusive]</param>
		/// <param name="end">??????? [exclusive]</param>
		/// <param name="value">?????</param>
		/// <param name="comparer">????(????????)</param>
		/// <returns>????????????????</returns>
		public static int LowerBound<T>(IReadOnlyList<T> arr, int start, int end, T value, IComparer<T> comparer)
		{
			int low = start;
			int high = end;
			int mid;
			while(low < high)
			{
				mid = ((high - low) >> 1) + low;
				if(comparer.Compare(arr[mid], value) < 0)
					low = mid + 1;
				else
					high = mid;
			}
			return low;
		}

		//????????????
		public static int LowerBound<T>(IReadOnlyList<T> arr, T value) where T : IComparable
		{
			return LowerBound(arr, 0, arr.Count, value, Comparer<T>.Default);
		}

		/// <summary>
		/// ?????????????????????
		/// </summary>
		/// <typeparam name="T">???????</typeparam>
		/// <param name="arr">??????????????????</param>
		/// <param name="start">??????? [inclusive]</param>
		/// <param name="end">??????? [exclusive]</param>
		/// <param name="value">?????</param>
		/// <param name="comparer">????(????????)</param>
		/// <returns>??????????????????</returns>
		public static int UpperBound<T>(IReadOnlyList<T> arr, int start, int end, T value, IComparer<T> comparer)
		{
			int low = start;
			int high = end;
			int mid;
			while(low < high)
			{
				mid = ((high - low) >> 1) + low;
				if(comparer.Compare(arr[mid], value) <= 0)
					low = mid + 1;
				else
					high = mid;
			}
			return low;
		}

		//????????????
		public static int UpperBound<T>(IReadOnlyList<T> arr, T value)
		{
			return UpperBound(arr, 0, arr.Count, value, Comparer<T>.Default);
		}
		#endregion
	}
}