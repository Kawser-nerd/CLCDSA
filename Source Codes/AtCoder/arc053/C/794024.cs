using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace c
{
    class Program
    {
        static void Main(string[] args)
        {
            long n = long.Parse(Console.ReadLine());
            List<long> upa = new List<long>();
            List<long> upb = new List<long>();
            List<long> downa = new List<long>();
            List<long> downb = new List<long>();

            for (long i = 0; i < n; i++)
            {
                long[] ab = Console.ReadLine().Split().Select(long.Parse).ToArray();
                long a = ab[0];
                long b = ab[1];
                if (a < b)
                {
                    downa.Add(a);
                    downb.Add(b);
                }
                else
                {
                    upa.Add(a);
                    upb.Add(b);
                }
            }
            var down = downa.Zip(downb, (x, y) => new { x, y }).ToArray();
            Array.Sort(down, (a, b) => {
                if (a.x != b.x) return a.x.CompareTo(b.x);
                return -a.y.CompareTo(b.y);
            });
            var up = upa.Zip(upb, (x, y) => new { x, y }).ToArray();
            Array.Sort(up, (a, b) => {
                if (a.y != b.y) return -a.y.CompareTo(b.y);
                return a.x.CompareTo(b.x);
            });
            long t = 0;
            long ans = 0;
            foreach (var p in down)
            {
                t += p.x;
                ans = Math.Max(ans, t);
                t -= p.y;
            }
            foreach (var p in up)
            {
                t += p.x;
                ans = Math.Max(ans, t);
                t -= p.y;
            }
            Console.WriteLine(ans);
        }
    }
}