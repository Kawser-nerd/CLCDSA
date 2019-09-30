using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

namespace Your_Rank_is_Pure
{
    class Program
    {
        private const long MOD = 100003;
        private static long[,] C;
        private static long[,] ANS;

        private static void ComputeCombinations(long N)
        {
            C = new long[N+1,N+1];

            for (int i = 0; i <= N; ++i)
                C[0, i] = 0;

            for (int i = 0; i <= N; ++i)
                C[i, 0] = 1;            

            for (int i = 1; i <= N; ++i)
                for (int j = 1; j <= N; ++j)
                    if (j > i) C[i, j] = 0;
                    else C[i, j] = (C[i - 1, j - 1] + C[i - 1, j]) % MOD;
        }

        private static void ComputeAnswers(long N)
        {
            ANS = new long[N + 1, N + 1];

            for (long n = 2; n <= N; ++n )
            {
                ANS[n, 1] = 1;
            }

            for (long n = 2; n <= N; ++n)
                    for (long l = 2; l < n; ++l)
                    {
                        for (long k=1; k<l; ++k)
                        {
                            if (n - l < l - k) continue;
                            if (k - 1 > l - 2) continue;
                            ANS[n, l] = (ANS[n, l] + ANS[l, k] * C[n - l - 1,l - k - 1]) % MOD;
                        }

                    }
        }

        

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var reader = new StreamReader("c.txt");
            var writer = new StreamWriter("c_out.txt");

            ComputeCombinations(600);
            ComputeAnswers(550);

            var testNumber = long.Parse(reader.ReadLine());
            for (long test = 1; test <= testNumber; ++test)
            {
                long result = 0;
                long n = long.Parse(reader.ReadLine());
                for (int l = 1; l < n; ++l)
                    result = (result + ANS[n, l]) % MOD;
                writer.WriteLine("Case #{0}: {1}", test, result);

            }

            reader.Close();
            writer.Close();
        }
    }
}
