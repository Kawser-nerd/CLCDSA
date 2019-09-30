using System;
using System.Collections.Generic;


namespace ProblemC
{
	class Program
	{
		static void Main()
		{
			int testsCount = StringToNumbers(Console.ReadLine(), 1)[0];
			for (int testIndex = 0; testIndex < testsCount; testIndex++)
			{
				int[] dimensions = StringToNumbers(Console.ReadLine(), 2);
				int height = dimensions[0];
				int width = dimensions[1];

				int[,] board = new int[width, height];

				for (int line = 0; line < dimensions[0]; line++)
				{
					int pos = 0;
					string encodedRow = Console.ReadLine();
					for (int i = 0; i < encodedRow.Length; i++)
					{
						int hex = HexToInt(encodedRow[i]);
						for (int k = 3; k >= 0; k--, pos++)
							board[pos, line] = GetBit(hex, k);
					}
				}

				//for (int y = 0; y < height; y++)
				//{
				//    for( int x = 0; x < width; x++ )
				//    {
				//        Console.Write("{0}", board[x, y]);
				//    }
				//    Console.WriteLine();
				//}

				Dictionary<int, int> results = new Dictionary<int, int>();

				while (true)
				{
					int x, y, size;
					if (!FindBoard(board, width, height, out x, out y, out size))
						break;
					ExcludeBoard(board, x, y, size);

					int count;
					if (results.TryGetValue(size, out count))
						count++;
					else
						count = 1;
					results[size] = count;
				}

				Console.WriteLine("Case #{0}: {1}", testIndex + 1, results.Count);

				List<int> sizes = new List<int>(results.Keys);
				sizes.Sort();

				for (int i = sizes.Count - 1; i >= 0; i--)
					Console.WriteLine("{0} {1}", sizes[i], results[sizes[i]]);
			}
		}



		static bool FindBoard(int[,] board, int width, int height, out int boardX, out int boardY, out int boardSize)
		{
			boardX = boardY = boardSize = 0;

			for (int y = 0; y < height; y++)
				for (int x = 0; x < width; x++)
				{
					int maxSize = Min(width - x, height - y);
					for (int size = 1; size <= maxSize; size++)
					{
						if (ValidBoard(board, x, y, size))
						{
							if (size > boardSize)
							{
								boardX = x;
								boardY = y;
								boardSize = size;
							}
						}
					}
				}

			return boardSize > 0;
		}


		static bool ValidBoard(int[,] board, int x, int y, int size)
		{
			int firstCell = board[x, y];

			for (int w = x; w < x + size; w++)
				for (int h = y; h < y + size; h++)
				{
					if (board[w, h] == 2)
						return false;
					int d = (w - x + h - y) % 2;
					int cell = board[w, h];
					bool validCell = (d == 0 && cell == firstCell) ||
						(d == 1 && cell != firstCell);
					if (!validCell)
						return false;
				}
			return true;
		}


		static void ExcludeBoard(int[,] board, int x, int y, int size)
		{
			for (int w = x; w < x + size; w++)
				for (int h = y; h < y + size; h++)
				{
					board[w, h] = 2;
				}
		}


		static int Min(int a, int b)
		{
			if (a < b)
				return a;
			return b;
		}

		static int HexToInt(char c)
		{
			if (c >= '0' && c <= '9')
				return c - '0';
			else if (c >= 'A' && c <= 'F')
				return c - 'A' + 10;
			return -1;
		}


		static int GetBit(int n, int index)
		{
			return (n >> index) & 1;
		}


		static int[] StringToNumbers(string s, int count)
		{
			int[] result = new int[count];
			string[] parts = s.Split(' ');
			for (int i = 0; i < count; i++)
				result[i] = Convert.ToInt32(parts[i]);
			return result;
		}
	}
}
