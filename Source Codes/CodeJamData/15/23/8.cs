using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

namespace Problem
{
    class CSmall1
    {
        static void Main(string[] args)
        {
            using (var sr = new StreamReader(@"..\..\C-small-1-attempt6.in"))
            {
                using (var sw = new StreamWriter(@"..\..\C-small-1-attempt6.out"))
                {
                    var T = int.Parse(sr.ReadLine());
                    for (int t = 1; t <= T; t++)
                    {
                        int r = 0;
                        var n = int.Parse(sr.ReadLine());
                        var hg = new HikerGroup[n];
                        for (int i = 0; i < n; i++)
                        {
                            var a = sr.ReadLine().Split().Select(int.Parse).ToArray();
                            hg[i] = new HikerGroup(a[0], a[1], a[2]);
                        }
                        var h = hg.SelectMany(g => g.Hikers()).ToArray();

                        if (h.Length <= 1)
                        {
                            r = 0;
                        }
                        else
                        {
                            Hiker slow, fast;
                            if (h[0].RouteTime > h[1].RouteTime)
                            {
                                slow = h[0];
                                fast = h[1];
                            }
                            else
                            {
                                slow = h[1];
                                fast = h[0];
                            }

                            //double timeFastGetsSlow = f / (360 / fast.RouteTime - 360 / slow.RouteTime);
                            //double timeSlowGetsMyFinish = (360 - slow.Angle) / (360 / slow.RouteTime);

                            if ((360 - (fast.Angle - slow.Angle)) * new BigInteger(slow.RouteTime) * fast.RouteTime * 360 <= (360 - slow.Angle) * new BigInteger(slow.RouteTime) * (360 * slow.RouteTime - 360 * fast.RouteTime))
                            {
                                r = 1;
                            }
                            else
                            {
                                r = 0;
                            }
                        }

                        sw.WriteLine("Case #{0}: {1}", t, r);
                    }
                }
            }
        }
    }

    public class HikerGroup
    {
        public int Angle;
        public int Number;
        public int RouteTime;

        public HikerGroup(int d, int h, int m)
        {
            Angle = d;
            Number = h;
            RouteTime = m;
        }

        public IEnumerable<Hiker> Hikers()
        {
            for (int i = 0; i < Number; i++)
            {
                yield return new Hiker
                                {
                                    Angle = Angle,
                                    RouteTime = RouteTime + i
                                };
            }
        }
    }

    public class Hiker
    {
        public Int64 Angle;
        public Int64 RouteTime;
    }
}

