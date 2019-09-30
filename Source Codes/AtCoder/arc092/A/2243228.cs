using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;

namespace For_Atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(ReadLine());
            var points = new List<NPoint>();
            for(int i = 0; i < 2 * n; i++)
            {
                string[] inf = ReadLine().Split(' ');
                points.Add(new NPoint(int.Parse(inf[0]), int.Parse(inf[1]), i / n));
            }
            int ans = 0;

            NPoint[] points2 = points.OrderByDescending(x => x.y).OrderBy(x => x.x).ToArray();
            NPoint blueone = new NPoint(0, 0, -1);
            NPoint[] bluepns = points2.Where(x => x.color == 1).ToArray();
            for(int i = 0; i < n; i++)
            {
                NPoint[] redpar = points2.Where(x => x.color == 0).Where(x => (x.x < bluepns[i].x) & (x.y < bluepns[i].y)).ToArray();
                if (redpar.Count() != 0)
                {
                    NPoint[] redpar2 = redpar.OrderByDescending(x => x.y).ToArray();
                    redpar2[0].color = -1;
                    ans++;
                }
            }

            WriteLine(ans);
        }
    }

    class NPoint
    {
        public int x;
        public int y;
        public int color;//0=red 1=blue
        public NPoint(int a,int b,int col)
        {
            x = a;
            y = b;
            color = col;
        }
    }
}