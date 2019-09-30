using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace RopeIntranet
{
    class Program
    {
        static void Main(string[] args)
        {
            long tests = long.Parse(Console.ReadLine());
            for (int test = 1; test <= tests; ++test)
            {
                var n = long.Parse(Console.ReadLine());
                var a = new long[n];
                var b = new long[n];
                for (int i = 0; i < n; ++i)
                {
                    var t = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
                    a[i] = t[0];
                    b[i] = t[1];
                }
                long total = 0;
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < i; ++j)
                    {
                        if (a[i] > a[j] ^ b[i] > b[j])
                            ++total;
                    }
                Console.WriteLine("Case #{0}: {1}", test, total);
            }
        }

    }
}
