using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProgrammingContest_CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            long x = long.Parse(Console.ReadLine());
            long ans = Solve(x);
            Console.WriteLine(ans);
        }

        private static long Solve(long x)
        {
            if (x == 1)
            {
                return 1;
            }

            x--;

            long ans = (x / (5 + 6)) * 2;
            long remainder = x % (5 + 6);

            if (remainder > 5)
            {
                ans += 2;
            }
            else
            {
                ans++;
            }

            return ans;
        }
    }
}