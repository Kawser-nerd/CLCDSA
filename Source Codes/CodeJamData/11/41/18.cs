using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;
using System.IO;

namespace A
{
    class walkway
    {
        public int B, E, w;
    }

    class Program
    {
        static void Solve(int casenum)
        {
            Console.Write("Case #{0}: ", casenum);

            string[] line = Console.ReadLine().Split();
            int X = int.Parse(line[0]);
            int S = int.Parse(line[1]);
            int R = int.Parse(line[2]);
            int t = int.Parse(line[3]);
            int N = int.Parse(line[4]);

            walkway[] ww = new walkway[N];
            for (int i = 0; i < N; i++)
            {
                line = Console.ReadLine().Split();
                ww[i] = new walkway();
                ww[i].B = int.Parse(line[0]);
                ww[i].E = int.Parse(line[1]);
                ww[i].w = int.Parse(line[2]);
            }

            Array.Sort(ww, (a, b) => a.B.CompareTo(b.B));

            walkway[] ww2 = new walkway[2*N + 1];
            ww2[0] = new walkway();
            ww2[0].B = 0;
            ww2[0].E = ww[0].B;
            ww2[0].w = 0;

            int p = 0;
            for (int i = 0; i < N; i++)
            {
                p++;
                ww2[p] = new walkway();
                ww2[p].B = ww[i].B;
                ww2[p].E = ww[i].E;
                ww2[p].w = ww[i].w;

                p++;
                ww2[p] = new walkway();
                ww2[p].B = ww[i].E;
                ww2[p].E = i == N - 1 ? X : ww[i + 1].B;
                ww2[p].w = 0;
            }


            Array.Sort(ww2, (a, b) => a.w.CompareTo(b.w));

            double runtime = 0.0;
            double walktime = 0.0;
            p = 0;
            while(p < ww2.Length /*&& runtime < t*/)
            {
                double dist = ww2[p].E - ww2[p].B;
                double speed = ww2[p].w + R;
                double time = dist / speed;

                if (runtime + time <= t)
                {
                    runtime += time;
                    p++;
                }
                else
                {
                    double rt = t - runtime;
                    double rd = rt * speed;
                    double wd = dist - rd;
                    double ws = ww2[p].w + S;
                    double wt = wd / ws;

                    runtime += rt;
                    walktime += wt;
                    p++;
                }
            }

            Console.WriteLine("{0:0.000000000}", runtime + walktime);
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
#if DEBUG
            Console.SetIn(new StreamReader("input.txt"));
#endif

            int T = int.Parse(Console.ReadLine());
            for (int t = 0; t < T; t++)
            {
                Solve(t + 1);
#if !DEBUG
                Console.Error.WriteLine("Solved: {0}", t + 1);
#endif
            }
        }
    }
}
