using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Numerics;

namespace C
{
    class Tribe
    {
        public int d;
        public int n;
        public int w, e;
        public int s;
        public int delta_d;
        public int delta_p;
        public int delta_s;

        public int cur_s;
        public int cur_w;
        public int cur_e;

    }

    class Program
    {
        static int Solve(Tribe[] tribes)
        {
            SortedDictionary<int, List<Tribe>> doa = new SortedDictionary<int,List<Tribe>>();
            int N = tribes.Length;

            foreach(Tribe tribe in tribes)
            {
                for (int i = 0; i < tribe.n; i++)
                {
                    int day = tribe.d + i * tribe.delta_d;
                    if (!doa.ContainsKey(day))
                        doa[day] = new List<Tribe>();
                    doa[day].Add(tribe);
                }
            }

            int[] wall = new int[1000];
            int[] between = new int[1000];

            foreach(Tribe tribe in tribes)
            {
                tribe.w += 500;
                tribe.e += 500;

                tribe.cur_s = tribe.s;
                tribe.cur_w = tribe.w;
                tribe.cur_e = tribe.e;
            }

            int count = 0;
            foreach (var day in doa.Keys)
            {
                foreach (var tribe in doa[day])
                {
                    for (int i = tribe.cur_w; i <= tribe.cur_e; i++)
                    {
                        if (wall[i] < tribe.cur_s)
                        {
                            count++;
                            break;
                        }

                        if (i != tribe.cur_e && between[i] < tribe.cur_s)
                        {
                            count++;
                            break;
                        }
                    }
                }

                foreach (var tribe in doa[day])
                {
                    for (int i = tribe.cur_w; i <= tribe.cur_e; i++)
                    {
                        wall[i] = Math.Max(wall[i], tribe.cur_s);

                        if(i != tribe.cur_e)
                            between[i] = Math.Max(between[i], tribe.cur_s);
                    }
                }

                foreach (var tribe in doa[day])
                {
                    tribe.cur_s += tribe.delta_s;
                    tribe.cur_w += tribe.delta_p;
                    tribe.cur_e += tribe.delta_p;
                }
            }

            return count;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                int N = int.Parse(Console.ReadLine());
                Tribe[] tribes = new Tribe[N];

                for (int i = 0; i < N; i++)
                {
                    string[] line = Console.ReadLine().Split();
                    tribes[i] = new Tribe();
                    tribes[i].d = int.Parse(line[0]);
                    tribes[i].n = int.Parse(line[1]);
                    tribes[i].w = int.Parse(line[2]);
                    tribes[i].e = int.Parse(line[3]);
                    tribes[i].s = int.Parse(line[4]);
                    tribes[i].delta_d = int.Parse(line[5]);
                    tribes[i].delta_p = int.Parse(line[6]);
                    tribes[i].delta_s = int.Parse(line[7]);
                }

                Console.WriteLine("Case #{0}: {1}", t, Solve(tribes));
            }
        }
    }
}
