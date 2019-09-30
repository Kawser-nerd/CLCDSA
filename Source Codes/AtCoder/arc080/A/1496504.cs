using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        private static bool Solve(int N, int[] A)
        {
            int cnt1 = 0, cnt2 = 0, cnt4 = 0;
            foreach (int a in A)
            {
                if      (a % 4 == 0) { ++cnt4; }
                else if (a % 2 == 0) { ++cnt2; }
                else                 { ++cnt1; }
            }
            if (cnt2 > 0)
            {
                return cnt4 >= (cnt1 + cnt4 + 1) / 2;
            }
            else
            {
                return cnt4 >= (cnt1 + cnt4) / 2;
            }
        }
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            Console.WriteLine(Solve(N, a) ? "Yes" : "No");
        }
    }
}