using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC76_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine().Split();
            int n = int.Parse(s[0]);
            int m = int.Parse(s[1]);
            long c = 1;
            long d = 1;
            long mod = 1000000007;
            for (int i = 1; i < n + 1; i++)
            {
                c = c * i % mod;
            }
            for (int i = 1; i < m + 1; i++)
            {
                d = d * i % mod;
            }
            if (Math.Abs(m-n) > 1)
            {
                Console.WriteLine(0);
                return;
            }
            if (n == m)
            {

                Console.WriteLine(2 * c * d % mod);
            }
            else
            {

                Console.WriteLine(c * d % mod);
            }
        }
    }
}