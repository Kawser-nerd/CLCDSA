using System;
using System.IO;
using System.Linq;

namespace Problem
{
    class A
    {
        static void Main(string[] args)
        {
            using (var sr = new StreamReader(@"..\..\A-small-attempt0.in"))
            {
                using (var sw = new StreamWriter(@"..\..\A-small-attempt0.out"))
                {
                    var T = int.Parse(sr.ReadLine());
                    for (int t = 1; t <= T; t++)
                    {
                        var n = int.Parse(sr.ReadLine());
                        var a = new int[10000000];
                        for (int i = 1; i <= n; i++)
                        {
                            a[i] = int.MaxValue;
                        }
                        a[1] = 1;
                        for (int i = 1; i < n; i++)
                        {
                            a[i + 1] = Math.Min(a[i + 1], a[i] + 1);
                            var r = Reverse(i);
                            a[r] = Math.Min(r, a[i] + 1);
                        }

                        sw.WriteLine("Case #{0}: {1}", t, a[n]);
                    }
                }
            }
        }

        static int Reverse(int x)
        {
            return int.Parse(new string(x.ToString().Reverse().ToArray()));
        }
    }
}

