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
		private const int MOD = 10007;// 1000000007;

		private struct Info
		{
			public int l;
			public int r;
			public int s;
		}
		static void Solve()
		{
			var o = ReadAndParseIntArr();
			var n = o[0];
			var m = o[1];
			var g = new List<int>[n];
			for(int i=0;i<n;++i)
			{
				g[i] = new List<int>();
			}
			for(int i=0;i<m;++i)
			{
				o = ReadAndParseIntArr();

				int idx0 = o[0] - 1;
				int idx1 = o[1] - 1;
				g[idx0].Add(idx1);
				g[idx1].Add(idx0);
			}


			var friendHash = new HashSet<int>();
			var friendFriendHash = new HashSet<int>();
			for(int i = 0;i<n;++i)
			{
				int ans = 0;
				var list = g[i];
				friendHash.Clear();
				friendFriendHash.Clear();
				foreach(int idx0 in list)
				{
					friendHash.Add(idx0);
				}
				foreach(int idx0 in list)
				{
					// ?????
					foreach(int idx1 in g[idx0])
					{
						if( idx1 == i) { continue; }
						if(friendHash.Contains(idx1)) { continue; }
						if(friendFriendHash.Contains(idx1)) { continue; }
						friendFriendHash.Add(idx1);
						ans++;
					}
				}
				Console.WriteLine(ans);
			}
			
		}
		#region ????????a
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