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

		static long lpow(long a, long b)
		{
			long r = 1;
			for (long x = 0; x < b; x++)
			{
				r *= a;
			}
			return r;
		}

		static string solveCase(int num)
		{
			var bm = readMany<long>();

			long b = bm[0];
			long m = bm[1];

			if (m > lpow(2, b - 2))
			{
				return "IMPOSSIBLE";
			}

			string res = "POSSIBLE";

			//long needed = 2;
			//int bits = 1;

			//while (needed < m)
			//{
			//	needed *= 2;
			//	bits++;
			//}

			bool[][] field = new bool[b][];
			for (int i = 0; i < b; i++)
			{
				field[i] = new bool[b];
			}

			//int skip = ((int)b - 2) - bits;

			//res += Environment.NewLine;
			//for (int i = 0; i < b; i++)
			//{
			//	field[0][i] = i == skip;
			//}

			if (lpow(2, b - 2) == m)
			{
				field[0][b - 1] = true;
				m--;
			}
			else
			{
				field[0][b - 1] = false;
			}

			for (int i = 0; i < b; i++)
			{

				//for (int j = 0; j <= i; j++)
				//{
				//	field[i][j] = false;
				//}

				for (int j = i + 1; j < b - 1; j++)
				{
					field[i][j] = true;
				}
				
				if (i > 0) field[i][b - 1] |= (m & (lpow(2, (i - 1)))) != 0;
			}

			foreach (bool[] x in field)
			{
				res += Environment.NewLine + string.Join("", x.Select(r => r ? "1" : "0"));
			}

			return res;
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