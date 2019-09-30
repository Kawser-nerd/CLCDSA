using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Contest
{
	class Program
	{
		static void Main(string[] args)
		{
			var NT = Console.ReadLine().Split().Select(int.Parse);
			int N = NT.First(), T = NT.Last();
			int[] t = Console.ReadLine().Split().Select(int.Parse).ToArray();
			int ans = 0;
			for (int i = 0; i < N - 1; i++)
			{
				ans += Math.Min(T, t[i + 1] - t[i]);
			}
			Console.WriteLine(ans + T);
#if DEBUG
			Console.ReadKey();
#endif
		}
	}
}