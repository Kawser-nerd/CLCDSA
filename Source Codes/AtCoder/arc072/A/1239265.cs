using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            long[] a = new long[n];
            string[] lines = Console.ReadLine().Split(' ');
            for (int i = 0; i < n; i++)
            {
                a[i] = long.Parse(lines[i]);
            }

            long ans1 = 0;
            long ans2 = 0;
            int sign = 1;
            long sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += a[i];
                if (sign > 0)
                {
                    if (sum >= 0)
                    {
                        ans1 += 1 + sum;
                        sum = -1;
                    }
                }
                else
                {
                    if (sum <= 0)
                    {
                        ans1 += 1  -sum;
                        sum = 1;
                    }
                }
                sign *= -1;
            }

            sign = -1;
            sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += a[i];
                if (sign > 0)
                {
                    if (sum >= 0)
                    {
                        ans2 += 1 + sum;
                        sum = -1;
                    }
                }
                else
                {
                    if (sum <= 0)
                    {
                        ans2 += 1 - sum;
                        sum = 1;
                    }
                }
                sign *= -1;
            }

            Console.WriteLine(Math.Min(ans1, ans2));
        }
    }
}