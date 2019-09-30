using System;
using System.Linq;
using System.IO;

namespace gcj2
{
  class Solution
  {
    StreamReader reader = new StreamReader("input.txt");

    void one(int tid) {
      var z = reader.ReadLine ().Split ().Select (Int64.Parse).ToArray<long> ();
      int N = (int) z[0];
      long P = z[1] - 1;
      long S = P;

      long teams = 1;
      for (int i = 0; i < N; ++i)
        teams *= 2;

      long[] a = new long[N];
      for (int i = N - 1; (P > 0L); i = i - 1, P = P / 2)
        a [i] = P % 2;

      long def = 0;
      for (int i = 0; i < N; ++i)
        if (a [i] == 0)
          def = def * 2 + 1;

      // outsiders
      long best = 0;
      int j = 0;
      while (j < N && a[j] == 0) {
        best = best * 2 + 1;
        ++j;
      }
      if (j < N)
        best = best * 2 + 1;
      if (def < best)
        best = def;
      best = teams - best - 1;

      // favorites
      long worst = 0;
      j = 0;
      while (j < N && a[j] == 1) {
        worst = worst * 2 + 1;
        ++j;
      }
      if (j < N)
        worst = worst * 2 + 1;
      if (S != teams - 1)
        worst--;


      Console.WriteLine ("Case #" + tid + ": " + worst + " " + best);
    }

    public void DoIt() {
      int tests = Int32.Parse(reader.ReadLine());
      for (int tid = 1; tid <= tests; ++tid)
        one (tid);
    }
  }

	class MainClass
	{
		public static void Main (string[] args)
		{
      var sol = new Solution ();
      sol.DoIt ();
		}
	}
}
