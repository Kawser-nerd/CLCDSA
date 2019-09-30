using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemC
{
	class Program
	{
		static void Main(string[] args)
		{
			string inputFileName = args.Length > 0 ? args[0] : "A-large-practice.in";
			string outputFileName = inputFileName.Replace(".in", ".out");
			using (var reader = new StreamReader(inputFileName))
			using (var writer = new StreamWriter(outputFileName))
			{
				int t = int.Parse(reader.ReadLine());
				for (int i = 1; i <= t; i++)
				{
					var line = reader.ReadLine().Split(' ').Select(int.Parse).ToList();
					var r = line[0];
					var c = line[1];
					var m = line[2];

					char[,] board;
					var res = Solve(r, c, m, out board);

					writer.WriteLine("Case #{0}:", i);
					if (!res) writer.WriteLine("Impossible");
					else
					{
						for (int j = 0; j < r; j++)
						{
							for (int k = 0; k < c; k++)
							{
								writer.Write(board[j, k]);
							}
							writer.WriteLine();
						}
					}
				}
			}
		}

		private static bool Solve(int r, int c, int m, out char[,] board)
		{
			if (m == r * c)
			{
				board = default(char[,]);
				return false;
			}
			if (m == 0)
			{
				board = CreateBoard(r, c, '.');
				board[0, 0] = 'c';
				return true;
			}
			if (m == r * c - 1)
			{
				board = CreateBoard(r, c, '*');
				board[0, 0] = 'c';
				return true;
			}

			if (r == 1 || c == 1) return SolveRowOrColumnIsOne(r, c, m, out board);
			if (r == 2 || c == 2) return SolveRowOrColumnIsTwo(r, c, m, out board);
			return SolveRowAndColumnGreaterOrEqualThanThree(r, c, m, out board);
		}

		private static char[,] CreateBoard(int r, int c, char ch)
		{
			var board = new char[r, c];

			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					board[i, j] = ch;
				}
			}

			return board;
		}

		private static bool SolveRowAndColumnGreaterOrEqualThanThree(int r, int c, int m, out char[,] board)
		{
			Debug.Assert(r >= 3 && c >= 3);
			Debug.Assert(m > 0 && m < r * c - 1);

			if (m == r * c - 2 || m == r * c - 3 || m == r * c - 5 || m == r * c - 7)
			{
				board = default(char[,]);
				return false;
			}

			board = CreateBoard(r, c, '.');
			board[r - 1, c - 1] = 'c';
			int mines = 0;
			for (int i = 0; i < r - 2; i++)
			{
				for (int j = 0; j < c - 2; j++)
				{
					board[i, j] = '*';
					mines++;
					if (mines == m) return true;
				}
			}
			var diff = 0;
			if ((m - (r - 2) * (c - 2)) % 2 == 1)
			{
				board[r - 3, c - 3] = '.';
				mines--;
				diff = 1;
			}
			for (int i = 0; i < r - 2 - diff; i++)
			{
				board[i, c - 2] = '*';
				board[i, c - 1] = '*';
				mines += 2;
				if (mines == m) return true;
			}
			for (int i = 0; i < c - 2 - diff; i++)
			{
				board[r - 2, i] = '*';
				board[r - 1, i] = '*';
				mines += 2;
				if (mines == m) return true;
			}

			Debug.Assert(false);
			throw new Exception("This can't be reached.");
		}

		private static bool SolveRowOrColumnIsTwo(int r, int c, int m, out char[,] board)
		{
			Debug.Assert(r == 2 || c == 2);
			Debug.Assert(m > 0 && m < r * c - 1);

			if (m % 2 != 0 || m == r * c - 2)
			{
				board = default(char[,]);
				return false;
			}

			board = CreateBoard(r, c, '.');
			board[0, 0] = 'c';
			for (int i = 1; i <= m / 2; i++)
			{
				if (r == 2)
				{
					board[0, c - i] = '*';
					board[1, c - i] = '*';
				}
				else
				{
					board[r - i, 0] = '*';
					board[r - i, 1] = '*';
				}
			}

			return true;
		}

		private static bool SolveRowOrColumnIsOne(int r, int c, int m, out char[,] board)
		{
			Debug.Assert(r == 1 || c == 1);
			Debug.Assert(m > 0 && m < r * c - 1);

			board = CreateBoard(r, c, '.');
			board[0, 0] = 'c';
			for (int i = 1; i <= m; i++)
			{
				if (r == 1) board[0, c - i] = '*';
				else board[r - i, 0] = '*';
			}

			return true;
		}

	}
}
