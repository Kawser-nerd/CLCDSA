using System;
using System.Globalization;
using System.IO;
using System.Linq;

namespace Problem
{
    class CSmall
    {
        static void Main(string[] args)
        {
            using (var sr = new StreamReader(@"..\..\C-small-1-attempt0.in"))
            {
                using (var sw = new StreamWriter(@"..\..\C-small-1-attempt0.out"))
                {
                    var T = int.Parse(sr.ReadLine());
                    for (int t = 1; t <= T; t++)
                    {
                        var tmp = sr.ReadLine().Split().Select(int.Parse).ToArray();
                        var n = tmp[0];
                        var k = tmp[1];
                        var u = double.Parse(sr.ReadLine(), CultureInfo.InvariantCulture);
                        var p = sr.ReadLine().Split().Select(x => double.Parse(x, CultureInfo.InvariantCulture)).ToArray().OrderBy(x=>x).Concat(Enumerable.Repeat(1.0, 1)).ToArray();
                        int i = 0;
                        double pp = p[0];
                        for (; i < n; i++)
                        {
                            var dp = (p[i + 1] - p[i])*(i+1);
                            if (dp < u)
                            {
                                u -= dp;
                                pp = p[i + 1];
                            }
                            else
                            {
                                pp += u/(i + 1);
                                break;
                            }
                        }
                        var r = 1.0;
                        int j = 0;
                        for (; j <= i; j++)
                        {
                            r *= pp;
                        }
                        for (; j < n; j++)
                        {
                            r *= p[j];
                        }

                        sw.WriteLine("Case #{0}: {1}", t, r.ToString(CultureInfo.InvariantCulture));
                    }
                }
            }
        }
    }
}