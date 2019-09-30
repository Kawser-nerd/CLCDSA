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
		private static Dictionary<int, int> primeDic = new Dictionary<int, int>();
		private static int[] primeTable = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
		private static List<int> listExpTotals = new List<int>();// ?????????????
		static void Solve()
		{
			var n = ReadAndParseInt();
			Factorization(n);
			
			foreach(var kv in primeDic)
			{
				listExpTotals.Add(kv.Value + 1);
			}

			long ans = 0;
			// 75
			foreach(var exp in listExpTotals)
			{
				if( exp >= 75) { ans++; }
			}

			// 3 * 25
			ans += CalcPair(3, 25);
			ans += CalcPair(5, 15);
			ans += CalcTriple(3, 5, 5);
			Console.WriteLine(ans);
		}

		private static long CalcTriple(int a, int b, int c)
		{
			long ans = 0;
			for(int i=0;i<listExpTotals.Count;++i)
			{
				for(int j=0;j<listExpTotals.Count;++j)
				{
					if( i == j) { continue; }
					for(int k=0;k<listExpTotals.Count;++k)
					{
						if( i== k) { continue; }
						if( j == k) { continue; }
						if( listExpTotals[i] >= a && listExpTotals[j] >= b && listExpTotals[k] >= c)
						{
							ans++;
						}
					}
				}
			}
			return ans / 2;
		}

		private static long CalcPair(int a, int b)
		{
			long ans = 0;
			for(int i=0;i<listExpTotals.Count;++i)
			{
				for(int j=0;j<listExpTotals.Count;++j)
				{
					if( i == j) { continue; }
					if(listExpTotals[i] >= a && listExpTotals[j] >= b)
					{
						ans++;
					}
				}
			}
			return ans;
		}

		private static void Factorization(int n)
		{

			for(int i=2;i<=n;++i)
			{
				int tmp = i;
				// ???
				foreach(int j in primeTable)
				{
					while(tmp >= 2 && tmp % j == 0)
					{
						tmp /= j;
						if(!primeDic.ContainsKey(j))
						{
							primeDic.Add(j, 0);
						}
						primeDic[j]++;
					}
					
				}
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