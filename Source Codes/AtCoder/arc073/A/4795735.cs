using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] nt = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
            long n = nt[0];
            long t = nt[1];

            long[] ti = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
            long ans = 0;

            for(long i = 1; i <= n; i++)
            {
                if(i == n)
                {
                    ans += t;
                }
                else
                {
                    ans += Math.Min(ti[i] - ti[i - 1], t);
                }

            }
            Console.WriteLine(ans);
        }
    }
}