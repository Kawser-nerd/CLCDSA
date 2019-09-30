using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace abc_038_C
{
    class Program
    {
        static void Main(string[] args)
        {
            long n = long.Parse(Console.ReadLine());
            long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();
            if (n == 1) { Console.WriteLine("1"); return; }
            long ans = 0;
            long stillOK = 0;
            for (long i = 1; i < n; i++)
            {
                if (a[i - 1] < a[i]) { stillOK++; }
                else { ans += stillOK * (stillOK + 1) / 2; stillOK = 0; }
                if (i == n - 1)
                {
                    ans += stillOK * (stillOK + 1) / 2; stillOK = 0;
                }
            }
            Console.WriteLine(ans + n);
            Console.ReadLine();
        }
    }
}