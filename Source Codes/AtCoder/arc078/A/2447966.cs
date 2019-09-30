using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC78_C
{
    class Program
    {
        static void Main(string[] args)
        {

            var n = int.Parse(Console.ReadLine());

            var a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var sum = new long[n];
            sum[0] = a[0];
            for (int i = 1; i < n; i++)
            {
                sum[i] = sum[i - 1] + a[i];
            }

            long ans = long.MaxValue;
            for (int i = 0; i < n - 1; i++)
            {
                long x = sum[i];
                long y = sum[n - 1] - sum[i];
                ans = Math.Min(ans, Math.Abs(x-y));
            }

            Console.WriteLine(ans);
        }
    }
}