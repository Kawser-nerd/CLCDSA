using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016_2_A
{
    class Program
    {
        static string best(int r, int p, int s)
        {
            if (r + p + s == 2)
            {
                return r == 0 ? "PS" : p == 0 ? "RS" : "PR";
            }
            string r1 = "", r2 = "";
            if (r == p)
            {
                r1 = best(r / 2, p / 2 + 1, s / 2);
                r2 = best(r / 2 + 1, p / 2, s / 2);
            }
            else if (r == s)
            {
                r1 = best(r / 2, p / 2, s / 2 + 1);
                r2 = best(r / 2 + 1, p / 2, s / 2);
            }
            else
            {
                r1 = best(r / 2, p / 2 + 1, s / 2);
                r2 = best(r / 2, p / 2, s / 2 + 1);
            }
            return r1.CompareTo(r2) < 0 ? r1 + r2 : r2 + r1;
        }

        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
                var N = line[0];
                var R = line[1];
                var P = line[2];
                var S = line[3];
                var possible = (Math.Abs(P - R) <= 1 && Math.Abs(P - S) <= 1 && Math.Abs(S - R) <= 1);
                Console.WriteLine("Case #{0}: {1}", testN, possible ? best(R, P, S) : "IMPOSSIBLE");
            }
        }
    }
}
