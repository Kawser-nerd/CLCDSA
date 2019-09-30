using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(args[0]);
            int N = int.Parse(sr.ReadLine());
            for (int t = 1; t <= N; t++)
            {
                string[] split = sr.ReadLine().Split();
                int n = int.Parse(split[0]);
                int A = int.Parse(split[1]);
                int B = int.Parse(split[2]);
                int C = int.Parse(split[3]);
                int D = int.Parse(split[4]);
                long x0 = int.Parse(split[5]);
                long y0 = int.Parse(split[6]);
                int M = int.Parse(split[7]);
                long[,] trees = new long[3, 3];

                long total = 0;
                checked
                {
                    for (int i = 0; i < n; i++)
                    {
                        trees[x0 % 3, y0 % 3]++;
                        x0 = (x0 * A + B) % M;
                        y0 = (y0 * C + D) % M;
                    }
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            for (int k = 0; k < 3; k++)
                            {
                                for (int l = 0; l < 3; l++)
                                {
                                    if (i == k && j == l)
                                    {
                                        long x = trees[i, j];
                                        total += x * (x - 1) * (x - 2);
                                    }
                                    else
                                    {
                                        total += trees[i, j] * trees[k, l] * trees[(9 - i - k) % 3, (9 - l - j) % 3];
                                    }
                                }
                            }
                        }
                    }
                    total /= 6;
                }
                Console.WriteLine("Case #{0}: {1}", t, total);
            }
        }
    }
}
