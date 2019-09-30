using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace code_jam_2k17_q
{
    public class C
    {
        static Int64[] read_ints(int num)
        {
            return Console.ReadLine()
                .Split(' ')
                .Take(num)
                .Select(s => Convert.ToInt64(s))
                .ToArray();
        }

        static Int64 binary_round_up(Int64 n)
        {
            int i;

            for (i = 62; i >= 0; --i)
            {
                if (((n - 1) & (1L << i)) > 0)
                    return 1L << (i + 1);
            }

            return 1;
        }

        static Int64[] solve(Int64 N, Int64 K)
        {
            Int64[] maxmin;

            maxmin = new Int64[2];

            /* Base case */
            if (K == 1)
            {
                maxmin[0] = N / 2;
                maxmin[1] = (N - 1) / 2;
                return maxmin;
            }

            /* If all open have no free neighbors */
            if ((K << 1) > binary_round_up(N))
            {
                maxmin[0] = 0;
                maxmin[1] = 0;
                return maxmin;
            }

            --K;
            /* If first divides set evenly, equiv to half remaining going to one side */
            if ((N & 1) > 0)
            {
                return solve(N / 2, (K + 1) / 2);
            }
            /* If first divides set unevenly */
            else
            {
                /* If odd number remaining, last will go to larger side */
                if ((K & 1) > 0)
                {
                    return solve(N / 2, (K + 1) / 2);
                }
                /* If even number remaining, last will go to smaller side */
                else
                {
                    return solve((N - 1) / 2, K / 2);
                }
            }
        }

        public static void c()
        {
            Int64 T, K, N, t;
            Int64[] line;
            Int64[] sln;

            T = read_ints(1)[0];
            for (t = 1; t < T + 1; ++t)
            {
                line = read_ints(2);
                N = line[0];
                K = line[1];
                sln = solve(N, K);
                Console.WriteLine("Case #" + t + ": " + sln[0] + " " + sln[1]);
            }
        }
    }
}
