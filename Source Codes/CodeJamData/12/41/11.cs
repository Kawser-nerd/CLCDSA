using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    public static class Round2
    {
        static string input = null;
        static string output = null;
        static string[] vals = null;

        public static void ProblemA()
        {
            input = Console.ReadLine();

            int T = Convert.ToInt32(input);

            for (int t = 1; t <= T; ++t)
            {
                input = Console.ReadLine();
                int N = Convert.ToInt32(input);
                long[] D = new long[N];
                long[] L = new long[N];
                long[] B = new long[N];
                for (int i = 0; i < N; ++i)
                {
                    input = Console.ReadLine();
                    vals = input.Split(' ');
                    D[i] = Convert.ToInt64(vals[0]);
                    L[i] = Convert.ToInt64(vals[1]);
                    B[i] = 0;
                }
                input = Console.ReadLine();
                long X = Convert.ToInt64(input);

                bool result = false;
                if (D[0] <= L[0])
                {
                    B[0] = 2 * D[0];
                    if (B[0] >= X) result = true;
                }
                for (int i = 0; i < N && !result; ++i)
                {
                    for (int j = i + 1; j < N && D[j] <= B[i]; ++j)
                    {
                        B[j] = Math.Max(B[j], Math.Min(D[j] + L[j], D[j] + D[j] - D[i]));
                        if (B[j] >= X)
                        {
                            result = true;
                            break;
                        }
                    }
                }

                output = String.Format("Case #{0}: {1}", t, result? "YES" : "NO");
                Console.WriteLine(output);
            }
        }

    }
}
