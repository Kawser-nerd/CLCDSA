using System;
using System.IO;

namespace CodeJam2015
{
    public class R1A_C
    {
        public static void Solve(TextReader input, TextWriter output)
        {
            int t = Convert.ToInt32(input.ReadLine());

            for (int z = 1; z <= t; z++)
            {
                int n = Int32.Parse(input.ReadLine());
                long[] x = new long[n];
                long[] y = new long[n];

                for (int i = 0; i < n; i++)
                {
                    string[] data = input.ReadLine().Split(' ');
                    x[i] = Int64.Parse(data[0]);
                    y[i] = Int64.Parse(data[1]);
                }
                
                output.WriteLine("Case #{0}:", z);

                for (int i = 0; i < n; i++)
                {
                    int m = (n > 2) ? n : 0;

                    for (int j = 0; j < n; j++)
                    {
                        if (i != j)
                        {
                            int l = 0;
                            int r = 0;

                            for (int k = 0; k < n; k++)
                            {
                                if ((k != i) && (k != j))
                                {
                                    long a = (x[i] - x[j]) * (y[i] - y[k]);
                                    long b = (x[i] - x[k]) * (y[i] - y[j]);

                                    if (a < b) l++;
                                    if (a > b) r++;
                                }
                            }

                            if (l < m) m = l;
                            if (r < m) m = r;
                        }
                    }

                    output.WriteLine(m);
                }
            }
        }
    }
}
