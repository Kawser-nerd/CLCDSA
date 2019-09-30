using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

namespace World_Cup_2010
{
    class Program
    {
        private static long[,,] dp;
        private static long[] left;
        private static long[,] price;

        private static long Memo(long round, long match, int done)
        {
            if (dp[round, match,done] != -1) return dp[round, match,done];
            long result;


            if (round == 1)
            {
                long a = (match - 1)*2;
                long b = a + 1;
                if (left[a] <= done && left[b] <= done) result = 0;
                else if (left[a] > done + 1 || left[b] > done + 1) result = int.MaxValue;
                else result = price[round, match];
            } else
            {
                var a = match*2 - 1;
                var b = a + 1;
                result = Math.Min(Memo(round - 1, a, done) + Memo(round - 1, b, done),
                                  Memo(round - 1, a, done + 1) + Memo(round - 1, b, done + 1) + price[round, match]);
            }

            dp[round, match, done] = result;
            return result;

        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var reader = new StreamReader("b.txt");
            var writer = new StreamWriter("b_out.txt");
            dp = new long[16,2000,16];
            price = new long[16,2000];
            left = new long[2000];

            var testNumber = long.Parse(reader.ReadLine());
            for (long test = 1; test <= testNumber; ++test)
            {
                var p = long.Parse(reader.ReadLine());

                for (int i = 0; i < 16; ++i)
                    for (int j = 0; j < 2000; ++j)
                        for (int l = 0; l < 16; ++l)
                        dp[i, j, l] = -1;

                long count = 1;
                for (int i = 0; i < p; ++i)
                    count *= 2;

                string[] input = reader.ReadLine().Split(' ');
                for (int i = 0; i < count; ++i)
                    left[i] = p - long.Parse(input[i]);

                for (int i=1; i<=p; ++i)
                {
                    count /= 2;
                    input = reader.ReadLine().Split(' ');
                    for (int j=1; j<=count; ++j)
                        price[i, j] = long.Parse(input[j-1]);
                }

                long result = Memo(p,1,0);               
                writer.WriteLine("Case #{0}: {1}", test, result);

            }

            reader.Close();
            writer.Close();
        }
    }
}
