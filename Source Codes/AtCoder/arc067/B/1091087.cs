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
            var e = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long n = e[0], a = e[1], b = e[2];
            var X = Console.ReadLine().Split().Select(long.Parse).ToArray();

            long ans = 0;
            for (int i = 0; i < X.Length - 1; i++)
            {
                long diff = X[i + 1] - X[i];
                if (diff * a <= b)
                {
                    ans += diff * a;
                }
                else
                {
                    ans += b;
                }
            }

            Console.WriteLine(ans);
        }
    }
}