using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;

namespace _16QA
{
	class Program
	{
		private static bool DEBUG = false;
		static void debug()
		{
		}

		static int gi(int[] a)
		{
			return Array.IndexOf(a, a.Max());
		}

		static string solveCase(int num)
		{
			int n = read<int>();
			var pis = readMany<int>();

			List<string> ress = new List<string>();

			while (pis.Sum() > 0)
			{
				string res = "";
				int m = pis.Max();
				int first = gi(pis);
				res += (char)('A' + first);
				pis[first]--;

                if (pis.Sum() != 2)
				{
					int second = gi(pis);
					res += (char)('A' + second);
					pis[second]--;
				}
				ress.Add(res);
			}
			return string.Join(" ", ress.ToArray());
		}

		static void Main(string[] args)
		{
			if (DEBUG)
			{
				debug();
			}
			else
			{
				Initialize();
				SolveAll(solveCase);
			}
			Console.ReadKey();
		}

		private static StreamReader inf;
		private static StreamWriter outf;

		private delegate void o(string format, params object[] args);
		private static o Output;

		private static T read<T>()
		{
			return (T)Convert.ChangeType(inf.ReadLine(), typeof(T));
		}

		private static string read()
		{
			return inf.ReadLine();
		}

		private static T[] readMany<T>()
		{
			return readMany<T>(' ');
		}

		private static _[] readMany<_>(params char[] ___)
		{
			return read().Split(___).Select(__ => (_)Convert.ChangeType(__, typeof(_))).ToArray();
		}

		private static string[] readMany()
		{
			return readMany<string>();
		}

		private static T[][] readField<T>(int height, Func<char, T> map)
		{
			T[][] res = new T[height][];
			for (int _ = 0; _ < height; _++)
			{
				res[_] = read().Select(c => map(c)).ToArray();
			}
			return res;
		}

		private static char[][] readField(int height)
		{
			return readField(height, c => c);
		}

		private static T[][] readField<T>(int height, Dictionary<char, T> dic)
		{
			return readField(height, c => dic[c]);
		}


		static Func<T1, TResult> DP<T1, TResult>(Func<T1, TResult> f)
		{
			var cache = new Dictionary<Tuple<T1>, TResult>();
			return (t1) =>
			{
				var key = Tuple.Create(t1);
				if (!cache.ContainsKey(key))
					cache.Add(key, f(t1));
				return cache[key];
			};
		}

		static Func<T1, T2, TResult> DP<T1, T2, TResult>(Func<T1, T2, TResult> f)
		{
			var cache = new Dictionary<Tuple<T1, T2>, TResult>();
			return (t1, t2) =>
			{
				var key = Tuple.Create(t1, t2);
				if (!cache.ContainsKey(key))
					cache.Add(key, f(t1, t2));
				return cache[key];
			};
		}

		static Func<T1, T2, T3, TResult> DP<T1, T2, T3, TResult>(Func<T1, T2, T3, TResult> f)
		{
			var cache = new Dictionary<Tuple<T1, T2, T3>, TResult>();
			return (t1, t2, t3) =>
			{
				var key = Tuple.Create(t1, t2, t3);
				if (!cache.ContainsKey(key))
					cache.Add(key, f(t1, t2, t3));
				return cache[key];
			};
		}


		public static void Initialize()
		{
			Console.ForegroundColor = ConsoleColor.Yellow;
			Console.Write("File name: ");
			string name = Console.ReadLine();
			inf = new StreamReader("D:\\Users\\marku\\Downloads\\" + name + ".in");
			outf = new StreamWriter("D:\\Users\\marku\\Downloads\\" + name + ".out");
			Console.ForegroundColor = ConsoleColor.White;
			Output = highlightedPrint;
			Output += outf.WriteLine;
		}

		private static void highlightedPrint(string format, params object[] args)
		{
			ConsoleColor prev = Console.ForegroundColor;
			Console.ForegroundColor = ConsoleColor.Green;
			Console.WriteLine(format, args);
			Console.ForegroundColor = prev;
		}

		public static void SolveAll(Func<int, string> calc)
		{
			int cases = int.Parse(inf.ReadLine());
			for (int _ = 1; _ <= cases; _++)
			{
				Output("Case #{0}: {1}", _, calc(_));
			}
			inf.Close();
			outf.Close();
			Console.ForegroundColor = ConsoleColor.Cyan;
			Console.WriteLine("Eureka!");
		}
	}
}
