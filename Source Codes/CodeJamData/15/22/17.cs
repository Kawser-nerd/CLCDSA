using System;
using System.IO;
using System.Linq;

namespace Problem
{
    class BSmall
    {
        static void Main(string[] args)
        {
            using (var sr = new StreamReader(@"..\..\B-small-attempt1.in"))
            {
                using (var sw = new StreamWriter(@"..\..\B-small-attempt1.out"))
                {
                    var T = int.Parse(sr.ReadLine());
                    for (int t = 1; t <= T; t++)
                    {
                        var a = sr.ReadLine().Split().Select(int.Parse).ToArray();
                        var r = a[0];
                        var c = a[1];
                        var n = a[2];
                        
                        var minRes = int.MaxValue;

                        var x = new int[r, c];

                        for (int i = (1 << (r * c)) - 1; i >= 0; i--)
                        {
                            var res = 0;
                            int nn = 0;
                            for (int j = i, k = 0; k < r * c; j >>= 1, k++)
                            {
                                var b = (j & 1);
                                x[k / c, k % c] = b;
                                if(b == 1)
                                {
                                    nn++;
                                }

                            }
                            if (nn!=n)
                            {
                                continue;
                            }
                            for (int rr = 0; rr < r; rr++)
                            {
                                for (int cc = 0; cc < c; cc++)
                                {
                                    if (x[rr, cc] == 1)
                                    {
                                        if (rr > 0 && x[rr - 1, cc] == 1)
                                        {
                                            res++;
                                        }
                                        if (cc > 0 && x[rr, cc - 1] == 1)
                                        {
                                            res++;
                                        }
                                    }
                                }
                            }
                            if (res < minRes)
                            {
                                minRes = res;
                            }
                        }

                        sw.WriteLine("Case #{0}: {1}", t, minRes);
                    }
                }
            }
        }
    }
}

