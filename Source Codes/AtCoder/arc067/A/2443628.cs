using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC67_C
{
    class Program
    {
        static void Main(string[] args)
        {

            var n = long.Parse(Console.ReadLine());
            var a = new int[n + 1];
            long mod = 1000000007;
            for (int i = 2; i <= n; i++)
            {
                int x = i;
                for (int j = 2; j <= n; j++)
                {
                    int k = 0;
                    if (x % j == 0)
                    {
                        for (k = 0; x % j == 0; x /= j) k++;
                    }
                    a[j] += k;
                }
            }
            long ans = 1;
            for (int i = 2; i <= n; i++)
            {
                ans *= a[i] + 1;
                ans %= mod;
            }

            Console.WriteLine(ans);
        }
    }
}