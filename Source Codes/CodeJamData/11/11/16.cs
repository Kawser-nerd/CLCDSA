using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1a
{
    class A
    {
        static void Main(string[] args)
        {
            int cases = int.Parse(Console.ReadLine());
            for (int i = 1; i <= cases; i++)
            {
                Console.Write(string.Format("Case #{0}: ", i));
                new A().Solve();
            }
        }

        private long Gcd(long a, long b)
        {
            if (b == 0)
                return a;
            else
                return Gcd(b, a % b);
        }

        private void Solve()
        {
            var v = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => long.Parse(s)).ToList();

            var n = v[0];
            var pd = v[1];
            var pg = v[2];

            bool ok;
            long minplayed = 100 / Gcd(pd, 100);
            if (minplayed <= n)
            {
                if (pg == 100 && pd < 100)
                    ok = false;
                else if (pg == 0 && pd > 0)
                    ok = false;
                else
                    ok = true;
            }
            else
                ok = false;

            Console.WriteLine(ok ? "Possible" : "Broken");
        }
    }
}
