using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;
using System.Numerics;

namespace B
{
    class Program
    {
        static int Solve(int A, int B, int K)
        {
            int count = 0;
            for (int a = 0; a < A; a++)
                for (int b = 0; b < B; b++)
                    if ((a & b) < K)
                        count++;

            return count;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                int A = int.Parse(line[0]);
                int B = int.Parse(line[1]);
                int K = int.Parse(line[2]);

                Console.WriteLine("Case #{0}: {1}", t, Solve(A, B, K));
            }
        }
    }
}
