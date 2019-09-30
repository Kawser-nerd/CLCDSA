using System;
using System.Linq;

namespace CSharp
{
	class Program
	{
		static void Main(string[] args)
		{
			// var N = 5;
			// var H = new int[] { 3, 1, 2, 3, 1 };
			// //             5
			// // 3 1 2 3 1
			// // 1 2 2 1

			var N = Console.ReadLine().Split().Select(int.Parse).ToArray()[0];
			var H = Console.ReadLine().Split().Select(int.Parse).ToArray();
			var res = 0;
			while (true)
			{
				if (H.Max() <= 0) break;

				var i = 0;
				res++;
				while (i < N)
				{
					if (H[i] == 0)
					{
						i++;
					}
					else
					{
						break;
					}
				}

				while (i < N && H[i] != 0)
				{
					H[i]--;
					i++;
				}
			}
			Console.WriteLine(res);
		}
	}
}