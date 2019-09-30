using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJamSharp
{

    class B
    {
        struct Painter
        {
            public int Color;
            public int Start;
            public int End;
        }

        static List<Painter> p = new List<Painter>();

        const int MaxVal = 1000;
        static Dictionary<int, int> cache = new Dictionary<int, int>();
        static int BidsToCover(int start, int end)
        {
            if (start > end) return 0;
            int key = start * 102344 + end;

            int ret;
            if (cache.TryGetValue(key, out ret))
            {
                return ret;
            }
            ret = MaxVal;

            foreach (Painter p1 in p)
            {
                if (p1.End < start || p1.Start > end) continue;
                ret = Math.Min(ret, BidsToCover(start, p1.Start - 1) +
                     BidsToCover(p1.End + 1, end) + 1);
            }
            cache[key] = ret;
            return ret;
        }

        
        static void Main(string[] args)
        {
            using (StreamReader sr = File.OpenText(@"C:\Google\B.in"))
            using (StreamWriter sout = File.CreateText(@"C:\Google\B.out"))
            {
                string line = sr.ReadLine();
                int cases = int.Parse(line);
                for (int cas = 1; cas <= cases; cas++)
                {
                    line = sr.ReadLine();
                    int N = int.Parse(line);
                    Dictionary<string, int> colors = new Dictionary<string, int>();
                    Painter[] painters = new Painter[N];

                    for (int i = 0; i < N; i++)
                    {
                        line = sr.ReadLine();
                        string[] items = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                        string color = items[0];
                        if (!colors.TryGetValue(color, out painters[i].Color))
                        {
                            painters[i].Color = colors.Count;
                            colors[color] = painters[i].Color;
                        }
                        painters[i].Start = int.Parse(items[1]);
                        painters[i].End = int.Parse(items[2]);
                    }
                    int ret = MaxVal;
                    for(int c1=0;c1<colors.Count;c1++)
                        for(int c2=c1;c2<colors.Count;c2++)
                            for (int c3 = c2; c3 < colors.Count; c3++)
                            {
                                p.Clear();
                                foreach (Painter p1 in painters)
                                    if (p1.Color == c1 || p1.Color == c2 || p1.Color == c3)
                                    {
                                        p.Add(p1);
                                    }

                                cache.Clear();
                                ret = Math.Min(ret, BidsToCover(1, 10000));
                            }
                    if (ret >= MaxVal)
                    {
                        sout.WriteLine("Case #{0}: IMPOSSIBLE", cas);
                    }
                    else
                    {
                        sout.WriteLine("Case #{0}: {1}", cas, ret);
                    }
                }
            }
        }
    }
}
