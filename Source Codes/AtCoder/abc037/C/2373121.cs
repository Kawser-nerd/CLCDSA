using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        public static void Main()
        {
            new Program().Solve();
        }

        void Solve()
        {
            var tmp = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            int n = tmp[0];
            int k = tmp[1];
            var a = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();

            int count = n - k + 1;
            long ans = 0;
            var s = new long[n];
            s[0] = a[0];
            for (int i = 1; i < n; i++)
            {
                s[i] = s[i - 1] + a[i];
            }            ans += s[k - 1];
            for (int i = 1; i < count; i++)
            {
                ans += (s[k - 1 + i] - s[i - 1]);
            }
            Console.WriteLine(ans);
        }
    }
}