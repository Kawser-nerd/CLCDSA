using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace atcoder
{
	class Program
	{
		static int In => int.Parse(Console.ReadLine());
		static int[] Ins => Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
		static void Out(bool b) => Console.WriteLine(b ? "Yes" : "No");

		static void Main(string[] args)
		{
			var n = In;
			var t = Ins;
			var v = Ins;
			int sum = 0;
			var li = new List<Func<double, double>>();
			li.Add(f(0, 0, 0));
			for (int i = 0; i < n; i++)
			{
				li.Add(f(sum, sum + t[i], v[i]));
				sum += t[i];
			}
			li.Add(f(sum, sum, 0));

			double ans = 0;
			for (double d = 0; d <= sum; d += 0.5)
			{
				ans += li.Select(f => f(d)).Min();
			}
			Console.WriteLine(ans / 2);
			//Console.ReadLine();
		}

		static Func<double, double> f(int a, int b, int m)
		{
			return x =>
			{
				if (x < a) return m + a - x;
				else if (b < x) return x + m - b;
				else return m;
			};
		}
	}
}