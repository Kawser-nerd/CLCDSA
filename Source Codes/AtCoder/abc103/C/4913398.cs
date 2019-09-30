using System;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            MainStream();
        }
        static void MainStream()
        {
            int n = int.Parse(Console.ReadLine());
            string[] a_list_tmp = Console.ReadLine().Split(' ');
            long[] a_list = a_list_tmp.Select(s => long.Parse(s)).ToArray();
            long sum = 0;

            for(int i=0; i<n; i++)
            {
                sum += a_list[i] - 1;
            }

            Console.WriteLine(sum);
        }

        static ulong Gcd(ulong a, ulong b)//?????
        {
            return (a < b) ? Gcd(b, a) : (b > 0) ? Gcd(b, a % b) : a;
        }

        static ulong Lcm(ulong a, ulong b)//?????
        {
            return a / Gcd(a, b) * b;
        }
    }
}