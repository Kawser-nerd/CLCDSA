using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace cShaprTest
{
    class Program
    {
        static void Main(string[] args)
        {
            int input = int.Parse(Console.ReadLine());

            Console.WriteLine(Solve(input, 0));
        }

        private static long Solve(int input, double n)
        {
            if (n > input) {
                return 0;
            }

            long ans = n.ToString().Contains("3")
                        && n.ToString().Contains("5")
                        && n.ToString().Contains("7") ? 1 : 0;
            ans += Solve(input, n * 10 + 3);
            ans += Solve(input, n * 10 + 5);
            ans += Solve(input, n * 10 + 7);

            return ans; 

        }
    }
}