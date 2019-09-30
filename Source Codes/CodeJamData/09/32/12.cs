using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                int N = int.Parse(Console.ReadLine());
                double[,] vars = new double[N,6];
                for (int j = 0; j < N; ++j)
                {
                    Double[] vv = Console.ReadLine().Split(' ').Select((x) => (double.Parse(x))).ToArray();
                    for (int k = 0; k < 6; ++k)
                        vars[j, k] = vv[k];
                };
                double[] com = new double[6];
                for (int j = 0; j < N; ++j)
                {
                    for (int k = 0; k < 6; ++k)
                        com[k] += vars[j, k];
                };
                for (int k = 0; k < 6; ++k)
                    com[k] /= N;
                double mintime;
                if ((com[3] * com[3] + com[4] * com[4] + com[5] * com[5]) > 1e-5)
                    mintime = -(com[0] * com[3] + com[1] * com[4] + com[2] * com[5]) / (com[3] * com[3] + com[4] * com[4] + com[5] * com[5]);
                else
                    mintime = 0;
                if (mintime < 0)
                    mintime = 0.0;
                double minresult = 0.0;
                for (int kk = 0; kk < 3; ++kk)
                    minresult += (com[kk+0]+com[kk+3]*mintime)*(com[kk+0]+com[kk+3]*mintime);
                minresult = Math.Sqrt(minresult);
                Console.WriteLine("Case #{0}: {1} {2}", i + 1, minresult.ToString("F8").Replace(',', '.'), mintime.ToString("F8").Replace(',', '.'));
            };
        }
    }
}
