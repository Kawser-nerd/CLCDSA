using System;
using System.Linq;

namespace abc034_d
{
	class Program
	{
		static Tuple<double,double>[] water;
		static int[] x;
		static bool IsOK(double per)
		{
			double[] salt = new double[x[0]];
			for (int i = 0; i < x[0]; i++)
			{
				salt[i] = (water[i].Item2-per) * water[i].Item1 / 100;
			}
			Array.Sort(salt); Array.Reverse(salt);
			double sum = 0;
			for(int i = 0; i < x[1]; i++)
			{
				sum += salt[i];
			}
			return sum >= 0;
		}
		static void Main(string[] args)
		{
			x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			water = new Tuple<double, double>[x[0]];
			for(int i = 0; i < x[0]; i++)
			{
				double[] a = Console.ReadLine().Split().Select(double.Parse).ToArray();
				water[i] = new Tuple<double, double>(a[0], a[1]);
			}
			double ok = 0;
			double ng = 100;
			while (ok - ng < -0.0000000001)
			{
				double mid = ng + (ok - ng) / 2;

				if (IsOK(mid)) ok = mid;
				else ng = mid;
			}
			Console.WriteLine(ok);
		}
	}
}