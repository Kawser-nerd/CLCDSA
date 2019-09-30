using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemA
{
    class File
    {
        public int S;
        public bool U;
    }

    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            int T = Convert.ToInt32(Console.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                var NX = Console.ReadLine().Split(' ');
                var N = Convert.ToInt32(NX[0]);
                var X = Convert.ToInt32(NX[1]);
                var F = Console.ReadLine().Split(' ').Select(token => new File { S = Convert.ToInt32(token), U = false }).OrderByDescending(f => f.S).ToArray();
                int count = 0;
                for (int n = 0; n < N; ++n)
                    if (!F[n].U)
                    {
                        ++count;
                        F[n].U = true;
                        var f2 = F.FirstOrDefault(f => !f.U && f.S <= X - F[n].S);
                        if (f2 != null)
                            f2.U = true;
                    }
                Console.WriteLine("Case #{0}: {1}", t, count);
            }
        }
    }
}
