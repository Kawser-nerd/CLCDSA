using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace _1
{
    class Solver
    {
        public long Solve(long[] a, long[] b)
        {
            Array.Sort(a);
            Array.Sort(b);
            long res = 0;
            for (int i = 0; i < a.Length; i++)
                res += (a[i] * b[a.Length - i - 1]);
            return res;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int nCases = int.Parse(Console.ReadLine());
            for (int i = 1; i <= nCases; i++)
            {
                long[] a, b;
                int n;

                n = int.Parse(Console.ReadLine());
                a = new long[n];
                b = new long[n];

                a = Console.ReadLine().Split().Select(s => long.Parse(s)).ToArray();
                b = Console.ReadLine().Split().Select(s => long.Parse(s)).ToArray();

                Solver solver = new Solver();
                
                string solv_res = solver.Solve(a,b).ToString();

                Console.WriteLine("Case #" + i.ToString() + ": " +
                                    solv_res
                                  );
            }
        }
    }
}
