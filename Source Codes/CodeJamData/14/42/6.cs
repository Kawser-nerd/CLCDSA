using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemB
{
    class Descending : IComparer<int>
    {
        public static Descending Instance = new Descending();
        public int Compare(int x, int y) { return Comparer<int>.Default.Compare(y, x); }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            int T = Convert.ToInt32(Console.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                var N = Convert.ToInt32(Console.ReadLine());
                var A = Console.ReadLine().Split(' ').Select(token => Convert.ToInt32(token)).ToList();
                var sorted = A.OrderBy(a => a).ToList();
                var remap = new Dictionary<int, int>();
                for (int n = 0; n < N; ++n)
                    remap[sorted[n]] = n;
                for (int n = 0; n < N; ++n)
                    A[n] = remap[A[n]];
                int sum = 0;
                for (int n = 0; n < N - 1; ++n)
                {
                    var off = A.IndexOf(n);
                    sum += Math.Min(off, A.Count - off - 1);
                    A.RemoveAt(off);
                }
                Console.WriteLine("Case #{0}: {1}", t, sum);
            }
        }
    }
}
