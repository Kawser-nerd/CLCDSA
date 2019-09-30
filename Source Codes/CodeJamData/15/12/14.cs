using System;
using System.IO;

namespace CodeJam2015
{
    public class R1A_B
    {
        public static void Solve(TextReader input, TextWriter output)
        {
            int t = Convert.ToInt32(input.ReadLine());

            for (int z = 1; z <= t; z++)
            {
                string[] data = input.ReadLine().Split(' ');
                int b = Int32.Parse(data[0]);
                long n = Int32.Parse(data[1]);
                int[] m = new int[b];

                data = input.ReadLine().Split(' ');

                for (int i = 0; i < b; i++)
                {
                    m[i] = Int32.Parse(data[i]);
                }

                long l = 0;
                long r = n * 100000;

                while (l < r)
                {
                    long k = (l + r + 1) / 2;
                    long c = 0;

                    for (int i = 0; i < b; i++)
                    {
                        if (k > 0) c += (k - 1) / m[i] + 1;
                    }

                    if (c >= n)
                    {
                        r = k - 1;
                    }
                    else
                    {
                        l = k;
                    }
                }

                if (r > 0)
                {
                    for (int i = 0; i < b; i++)
                    {
                        n -= (r - 1) / m[i] + 1;
                    }
                }

                int e = 0;

                for (int i = 0; i < b; i++)
                {
                    if (r % m[i] == 0)
                        n--;

                    if (n == 0)
                    {
                        e = i + 1;
                        break;
                    }
                }

                output.WriteLine("Case #{0}: {1}", z, e);
            }
        }
    }
}
