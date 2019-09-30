using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine());
            var m = new Int64[n][];
            for (int i = 0; i < n; i++)
            {
                var s = Console.ReadLine().Split();
                m[i] = new Int64[]{ Int64.Parse(s[0]), Int64.Parse(s[1])};
            }

            Console.WriteLine(Solver.Solve(n, m));
        }
    }

    public class Solver
    {
        public static Int64 Solve(int n, Int64[][] m)
        {
            var magics_dec = m.Where(v => v[0] < v[1]).OrderBy(v => v[0]);
            var magics_inc = m.Where(v => v[0] >= v[1]).OrderByDescending(v => v[1]);

            Int64 ret = 0, cur = 0;
            foreach (var magic in magics_dec.Concat(magics_inc))
            {
                ret = Math.Max(ret, cur + magic[0]);
                cur += magic[0] - magic[1];
            }
            return ret;
        }        
    }
}