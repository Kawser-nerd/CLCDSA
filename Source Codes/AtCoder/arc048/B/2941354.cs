using System;
using System.Linq;

namespace arc048_b
{
	class Program
	{
		static int[] rating;


		static bool IsOK(int index, int key)
		{
			if (rating[index] > key) return true;
			else return false;
		}

		static int Binary_search(int key)
		{
			int ng = -1;
			int ok = rating.Count();

			while (ok - ng > 1)
			{
				int mid = ng + (ok - ng) / 2;

				if (IsOK(mid, key)) ok = mid;
				else ng = mid;
			}

			return ok;
		}
		static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			Tuple<int, int>[] input = new Tuple<int, int>[n];
			rating = new int[n];
			int[,] a = new int[100010, 3];
			for (int i = 0; i < n; i++)
			{
				int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
				x[0]--; x[1]--;
				input[i] = new Tuple<int, int>(x[0], x[1]);
				rating[i] = x[0];
				a[x[0], x[1]]++;
			}
			Array.Sort(rating);
			for (int i = 0; i < n; i++)
			{
				int win = 0, lose = 0, draw = 0;
				win += Binary_search(input[i].Item1 - 1);
				lose += n - Binary_search(input[i].Item1);

				win += a[input[i].Item1, (input[i].Item2 + 1) % 3];
				lose += a[input[i].Item1, (input[i].Item2 + 2) % 3];
				draw += a[input[i].Item1, (input[i].Item2 + 3) % 3];
				Console.WriteLine(win + " " + lose + " " + (draw - 1));
			}
		}
	}
}