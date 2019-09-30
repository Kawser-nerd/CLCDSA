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

        public static void ProblemB()
        {
            input = Console.ReadLine();

            int T = Convert.ToInt32(input);

            for (int t = 1; t <= T; ++t)
            {
                input = Console.ReadLine();
                vals = input.Split(' ');
                int N = Convert.ToInt32(vals[0]);
                double W = Convert.ToInt32(vals[1]);
                double L = Convert.ToInt32(vals[2]);

                double[] R = new double[N];
                input = Console.ReadLine();
                vals = input.Split(' ');

                for (int i = 0; i < N; ++i)
                {
                    R[i] = Convert.ToInt32(vals[i]);
                }

                double[] X = new double[N];
                double[] Y = new double[N];

                int STEP = 200;

                bool[,] B = new bool[STEP + 1, STEP + 1];
                for (int i = 0; i <= STEP; ++i)
                    for (int j = 0; j <= STEP; ++j)
                        B[i, j] = false;

                double x = 0, y = 0;

                bool success = false;
                for (int k = 0; k < N; ++k)
                {
                    success = false;
                    for (int i = 0; i <= STEP && !success; ++i)
                    {
                        for (int j = 0; j <= STEP && !success; ++j)
                        {
                            x = W * i / STEP;
                            y = L * j / STEP;
                            bool valid = true;
                            for (int p = 0; p < k; ++p)
                            {
                                if ((X[p] - x) * (X[p] - x) + (Y[p] - y) * (Y[p] - y) < (R[k] + R[p]) * (R[k] + R[p]) - 1e-8)
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (valid)
                            {
                                X[k] = x;
                                Y[k] = y;
                                success = true;
                            }
                        }
                    }
                    if (!success) break;
                }

                output = String.Format("Case #{0}:", t);
                Console.Write(output);

                if (!success)
                {
                    Console.Write("FUCK!!");
                }
                else
                {
                    for (int i = 0; i < N; ++i)
                    {
                        Console.Write(String.Format(" {0} {1}",X[i], Y[i]));
                    }
                }
                Console.WriteLine();
            }
        }

    }
}
