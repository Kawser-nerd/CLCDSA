using System;

namespace ABC076D
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] t = new int[N + 1];
            int[] v = new int[N + 1];

            string[] bufs = Console.ReadLine().Split(' ');
            for (int i = 0; i < N; i++)
            {
                t[i] = int.Parse(bufs[i]);
            }
            t[N] = 999;

            bufs = Console.ReadLine().Split(' ');
            for (int i = 0; i < N; i++)
            {
                v[i] = int.Parse(bufs[i]);
            }
            v[N] = 0;
            // END Initialize //

            // Recurrsive Speed Limit
            for (int i = N - 1; i >= 0; i--)
            {
                if (v[i] > v[i + 1] + t[i])
                {
                    v[i] = v[i + 1] + t[i];
                }
            }


            double curv = 0.0;
            int curt = 0;
            double dist = 0.0;

            for (int i = 0; i < N; i++)
            {
                double upTime = Math.Min(v[i] - curv, t[i]);
                double downTime = Math.Max((curv + upTime) - v[i + 1], 0.0);
                double flatTime = t[i] - upTime - downTime;

                if (flatTime < 0)
                {
                    flatTime = 0;
                    double cross = ((v[i + 1] + t[i]) - curv) / 2.0;
                    upTime = cross;
                    downTime = t[i] - cross;
                }

                if (upTime > 0)
                {
                    dist += upTime * ( 2 * curv + upTime ) / 2.0;
                    curv += upTime;
                }
                dist += flatTime * v[i];
                if (downTime > 0) {
                    dist += downTime * (curv + v[i + 1] ) / 2.0;
                    curv = v[i + 1];
                }

                curt += t[i];
            }


            Console.WriteLine(dist.ToString("F4"));
        }
    }
}