using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class AirportWalkways : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string[] s = Console.ReadLine().Split(' ');
                int X = int.Parse(s[0]);
                int S = int.Parse(s[1]);
                int R = int.Parse(s[2]);
                int t = int.Parse(s[3]);
                int N = int.Parse(s[4]);

                WalkWay[] w = new WalkWay[N];
                for (int i = 0; i < N; i++)
                {
                    s = Console.ReadLine().Split(' ');
                    w[i] = new WalkWay();
                    w[i].b = int.Parse(s[0]);
                    w[i].e = int.Parse(s[1]);
                    w[i].s = int.Parse(s[2]);
                }
                double ret = MinTime(X, S, R, t, N, w);

                Console.WriteLine("Case #{0}: {1:0.00000000000}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private double MinTime(int X, int S, int R, int Rtime, int N, WalkWay[] w)
        {
            Array.Sort(w);
            int pos = 0;
            List<Stretch> stretches = new List<Stretch>();
            for (int i = 0; i < N; i++)
            {
                if (w[i].b > pos)
                {
                    Stretch walk = new Stretch();
                    walk.dis = w[i].b - pos;
                    walk.speed = 0;
                    stretches.Add(walk);
                    pos = w[i].b;
                }
                if (w[i].e <= X)
                {
                    Stretch ww = new Stretch();
                    ww.dis = w[i].e - w[i].b;
                    ww.speed = w[i].s;
                    stretches.Add(ww);
                    pos = w[i].e;
                }
            }
            Stretch lastwalk = new Stretch();
            lastwalk.dis = X - pos;
            lastwalk.speed = 0;
            stretches.Add(lastwalk);
            pos = X;

            stretches.Sort();

            double time = 0;
            double rbal = Rtime;
            foreach (Stretch stretch in stretches)
            {
                double wtime = (double)stretch.dis / (S + stretch.speed);
                double rtime = (double)stretch.dis / (R + stretch.speed);
                if (rtime <= rbal)
                {
                    time += rtime;
                    rbal -= rtime;
                }
                else if (rbal <= 0)
                {
                    time += wtime;
                }
                else
                {
                    double rEnd = rbal * (R + stretch.speed);
                    double wBal = (stretch.dis - rEnd) / (S + stretch.speed);
                    time += wBal + rbal;
                    rbal = 0;
                }
            }
            return time;
        }

        private class WalkWay : IComparable
        {
            public int b;
            public int e;
            public int s;

            public int CompareTo(object obj)
            {
                WalkWay other = obj as WalkWay;
                return this.b.CompareTo(other.b);
            }
        }

        private class Stretch : IComparable
        {
            public int dis;
            public int speed;

            public int CompareTo(object obj)
            {
                Stretch other = obj as Stretch;
                return this.speed.CompareTo(other.speed);
            }
        }
    }
}
