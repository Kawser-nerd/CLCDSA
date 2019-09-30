using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.IO;
using System.Threading;

namespace ConsoleApplication1
{
    class Program
    {
        static string Solve(int[] perm)
        {
            double logSum = 0.0;
            int K = Math.Min(1000, perm.Length);
            for (int i = 0; i < perm.Length; i++)
            {
                // perm[i] -> i
                if (perm[i] + K >= perm.Length)
                    logSum += -Math.Log(_prob[perm[i]][i]);
            }
            if (logSum < K * Math.Log(perm.Length))
                return "BAD";
            else
                return "GOOD";
        }


        static Dictionary<int, double[]> _prob = new Dictionary<int, double[]>();

        static void FillProb(int N)
        {
            double n_inv = 1.0 / N;
            double n_inv_t = 1.0 - n_inv;
            double[] tmpprob = new double[N];
            for (int E = 0; E < N; E++)
            {
                double[] curprob = new double[N];
                curprob[E] = 1.0;
                for (int k = 0; k < N; k++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        tmpprob[j] = 0.0;
                        if (k == j)
                        {
                            for (int i = 0; i < N; i++)
                                tmpprob[j] += curprob[i] * n_inv;
                        }
                        else
                        {
                            tmpprob[j] += curprob[j] * n_inv_t + curprob[k] * n_inv;
                        }
                    }
                    for (int j = 0; j < N; j++)
                        curprob[j] = tmpprob[j];
                }
                _prob[E] = curprob;
            }
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            using (StreamReader sr = new StreamReader(args[0]))
            {
                int T = int.Parse(sr.ReadLine());
                for (int i = 0; i < T; i++)
                {
                    int N = int.Parse(sr.ReadLine());
                    if (i == 0)
                        FillProb(N);

                    int[] splitted = sr.ReadLine().Split(' ').Select(s => int.Parse(s, CultureInfo.InvariantCulture)).ToArray();

                    string res = Solve(splitted);
                    Console.WriteLine(string.Format("Case #{0}: {1}", i + 1, res));
                }
            }
        }
    }
}
