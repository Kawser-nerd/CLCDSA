using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.IO;

namespace ProblemA
{
    class Program
    {
        static Int64 GCD(Int64 a, Int64 b)
        {
            while (a>0 && b>0)
            {
                if (a > b)
                {
                    a = a%b;
                }
                else
                {
                    b = b%a;
                }
            }
            return a + b;
        }

        static void Main(string[] args)
        {
            using (var sr = new StreamReader(@"..\..\A-large.in"))
            {
                using (var sw = new StreamWriter(@"..\..\A-large.out"))
                {
                    var T = int.Parse(sr.ReadLine());
                    for (int t = 1; t <= T; t++)
                    {
                        var a = sr.ReadLine().Split('/').Select(Int64.Parse).ToArray();
                        var p = a[0];
                        var q = a[1];

                        var g = GCD(p, q);
                        p /= g;
                        q /= g;

                        Int64 x = 1;
                        for (; x < q; x *= 2)
                        {
                            
                        }

                        if (x != q)
                        {
                            sw.WriteLine("Case #{0}: impossible", t);
                            continue;
                        }

                        var bigP = new BigInteger(p);
                        int i = 1;
                        for (x = 2; q > bigP * x; x *= 2, i++)// 1/x>p/q
                        {

                        }

                        sw.WriteLine("Case #{0}: {1}", t, i);
                    }
                }
            }
        }
    }
}

