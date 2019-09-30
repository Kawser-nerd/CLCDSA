using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections.Concurrent;
using System.Threading.Tasks;

namespace LoadTesting
{
    class Program
    {
        static long c;
        static ConcurrentDictionary<long, long> memo = new ConcurrentDictionary<long, long>();

        static long f(long l, long p)
        {
            if (l * c >= p) return 0;
            long ans;
            if (memo.TryGetValue((l<<32) + p, out ans))
                return ans;
            var ll = l;
            var pp = p;
//            Console.WriteLine("{0} {1}", l, p);
            while (true) {
                long midx = (l + p) / 2;
                long mid1 = 0;
                var t1 = Task.Factory.StartNew(() => { mid1 = f(ll, midx); });
                long mid2 = 0; 
                var t2 = Task.Factory.StartNew(() => { mid2 = f(midx, pp); });
                Task.WaitAll(t1, t2);
                if (mid1 == mid2 || midx == l) {
                    var anss = 1 + (mid1 < mid2 ? mid2 : mid1);
                    memo[(ll<<32) + pp] = anss;
                    return anss;
                }
                if (mid1 < mid2)
                    l = midx;
                else
                    p = midx;
            }
        }

        static void Main(string[] args)
        {
            long tests = long.Parse(Console.ReadLine());
            for (int test = 1; test <= tests; ++test)
            {
                memo.Clear();
                var t = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
                var l = t[0];
                var p = t[1];
                c = t[2];
                var ans = f(l, p);
                Console.WriteLine("Case #{0}: {1}", test, ans);
            }

        }
    }
}
