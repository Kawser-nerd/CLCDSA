using System;
using System.Linq;

namespace gcj1B
{
	class MainClass
	{
		static void one(int tid) {
			var z = Console.ReadLine().Split().Select(Int32.Parse).ToArray<int>();
			long A = z[0];
			int N = z[1];
			var others = Console.ReadLine().Split().Select(Int32.Parse).OrderBy(x => x).ToArray<int>();

			int best = N;
			int cur = 0;
			for (int i = 0; i < N; ++i) {
				if (A > others[i]) {
					A += others[i];
					continue;
				}
				best = Math.Min(best, cur + N - i);
				if (A == 1) {
					cur += N - i;
					break;
				}
				while (A <= others[i]) {
					A += A - 1;
					cur++;
				}
				A += others[i];
			}
			best = Math.Min(best, cur);
			Console.WriteLine("Case #" + tid + ": " + best);
		}

		public static void Main (string[] args)
		{
			int tests = Int32.Parse(Console.ReadLine());
			for (int tid = 1; tid <= tests; ++tid)
				one (tid);
		}
	}
}
