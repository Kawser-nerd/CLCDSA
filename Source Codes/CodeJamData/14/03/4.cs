using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
	class Program
	{
		static void Main(string[] args)
		{
			int T = int.Parse(Console.ReadLine());
			for (int t = 1; t <= T; t++)
			{
				string[] parts = Console.ReadLine().Split();
				int R = int.Parse(parts[0]);
				int C = int.Parse(parts[1]);
				int M = int.Parse(parts[2]);

				//Console.WriteLine("Case #{0}: {1}x{2} - Full: {3}, Empty: {4}", t, R, C, M, R * C - M);
				Console.WriteLine("Case #{0}:", t);
				int E = C * R - M;
				if (R * C - M == 1)
				{
					for (int r = 0; r < R; r++)
					{
						if (r == 0)
							Console.Write('c');
						else
							Console.Write('*');

						for (int i = 1; i < C; i++)
							Console.Write('*');
						Console.WriteLine();
					}
				}
				else if ((R == 1) || (C == 1))
				{
					PrintSolution1(R, C, M);
				}
				else if ((E == 2) || (E == 3) || (E == 5) || (E == 7))
					Console.WriteLine("Impossible");
				else if ((R == 2) || (C == 2))
				{
					if ((R == 2) && (C == 2))
					{
						if (M == 1)
						{
							Console.WriteLine("c*");
							Console.WriteLine("**");
						}
						else if (M == 0)
						{
							Console.WriteLine("c.");
							Console.WriteLine("..");
						}
						else
							Console.WriteLine("Impossible");
					}
					else if ((M % 2 != 0) || (M == R * C - 2))
						Console.WriteLine("Impossible");
					else
						PrintSolution2(R, C, M);
				}
				else
					CheckAndPrintSolution(R, C, M);
			}
		}

		private static void CheckAndPrintSolution(int R, int C, int M)
		{
			int E = R * C - M;
			for (int r = Math.Max(2, E / C); r <= R; r++)
			{
				int c = E / r;
				if (c > C)
					continue;

				int x = E - r * c;
				//if ((c > 1) && ((x > 1) || (x == 0) || ((x == 1) && (r == 2))))
				//if ((c > 1) && ((x > 1) || (x == 0) || ((x == 1) && (r == 2) && (c == C - 1))) && ((c < C) || (x == 0)))
				if ((c > 1) && ((x > 1) || (x == 0)) && ((c < C) || (x == 0)))
				{
					for (int j = 0; j < r; j++)
					{
						if (j == 0)
							Console.Write('c');
						else
							Console.Write('.');
						for (int i = 1; i < c; i++)
							Console.Write('.');
						if (c < C)
						{
							if (j < x)
								Console.Write('.');
							else
								Console.Write('*');
						}
						for (int i = c + 1; i < C; i++)
							Console.Write('*');
						Console.WriteLine();
					}
					for (int j = r; j < R; j++)
					{
						for (int i = 0; i < C; i++)
							Console.Write('*');
						Console.WriteLine();
					}					
					return;
				}
				else if ((c > 2) && (x == 1) && (c != C) && (r > 2))
				{
					for (int j = 1; j <= r; j++)
					{
						if (j == 1)
							Console.Write('c');
						else
							Console.Write('.');

						for (int i = 1; i < c - 1; i++)
							Console.Write('.');

						if (j < r)
							Console.Write('.');
						else
							Console.Write('*');

						if (j <= 2)
							Console.Write('.');
						else
							Console.Write('*');

						for (int i = c + 2; i <= C; i++)
							Console.Write('*');
						Console.WriteLine();
					}
					for (int j = r + 1; j <= R; j++)
					{
						for (int i = 0; i < C; i++)
							Console.Write('*');
						Console.WriteLine();
					}					

					return;
				}
			}
			Console.WriteLine("Impossible");
		}

		private static void PrintSolution1(int R, int C, int M)
		{
			if (R == 1)
			{
				Console.Write('c');
				for (int i = 1; i < C - M; i++)
					Console.Write('.');
				for (int i = 0; i < M; i++)
					Console.Write('*');
				Console.WriteLine();
			}
			else if (C == 1)
			{
				Console.WriteLine('c');
				for (int i = 1; i < R - M; i++)
					Console.WriteLine('.');
				for (int i = 0; i < M; i++)
					Console.WriteLine('*');
			}
		}

		private static void PrintSolution2(int R, int C, int M)
		{
			if (R == 2)
			{
				Console.Write('c');
				for (int i = 1; i < C - M / 2; i++)
					Console.Write('.');
				for (int i = 0; i < M / 2; i++)
					Console.Write('*');
				Console.WriteLine();
				for (int i = 0; i < C - M / 2; i++)
					Console.Write('.');
				for (int i = 0; i < M / 2; i++)
					Console.Write('*');
				Console.WriteLine();
			}
			else if (C == 2)
			{
				Console.WriteLine("c.");
				for (int i = 1; i < R - M / 2; i++)
					Console.WriteLine("..");
				for (int i = 0; i < M / 2; i++)
					Console.WriteLine("**");
			}
		}
	}
}
