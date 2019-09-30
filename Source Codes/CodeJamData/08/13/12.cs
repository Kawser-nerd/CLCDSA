using System;
using System.IO;

using System.Text;

namespace Numbers
{
	class Program
	{
		static double b = 3 - Math.Sqrt(5);

		static void Main(string[] args)
		{
			/*
			for (int i = 0; i < 10; i++)
			{
				int s = CalcS(i);
				double sx = s - Math.Pow(3 - Math.Sqrt(5), i);

				Console.WriteLine("i = " + i + ": " + sx);
			}

			Console.ReadLine();
			*/

			StreamReader r = new StreamReader("C-small-attempt1.in");
			StreamWriter w = new StreamWriter("Output.txt");

			int nCases = Int32.Parse(r.ReadLine());

			for (int i = 0; i < nCases; i++)
			{
				int n = Int32.Parse(r.ReadLine());

				w.WriteLine("Case #" + (i+1) + ": " + LastThreeDigits(n));
			}

			r.Close();
			w.Close();
		}

		static double Power(double v, int n)
		{
			double r = 1;
			for (int i = 0; i < n; i++)
			{
				r = r * v;
			}

			return r;
		}

		static int CalcS(int n)
		{
			int s0 = 2;
			int s1 = 6;

			if (n == 0)
				return s0;
			if (n == 1)
				return s1;

			for (int k = 0; k < n - 1; k++)
			{
				int v = 6 * s1 - 4 * s0;
				int i = v % 1000;
				if (i < 10)
					i += 1000;
				
				s0 = s1;
				s1 = i;
			}

			return s1;
		}

		static string LastThreeDigits(int n)
		{
			int s = CalcS(n);

			double sx = s - Math.Pow(b, n);

			int l = ((int)Math.Floor(sx)) % 1000;

			return l.ToString("000");
		}

		struct S
		{
			public int I;
			public double D;

			public S(int i, double d)
			{
				I = i;
				D = d;
			}
		}
	}
}
