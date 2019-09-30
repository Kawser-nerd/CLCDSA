using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC003B
{
    class Program
    {
        static void Main(string[] args)
        {
            Solver sol = new Solver();
            sol.Solve();
#if DEBUG
            Console.ReadLine();
#endif
        }
    }
    class Solver
    {
        int N;
        string[] s;

        public void Solve()
        {
            var q = s.OrderBy(x => new string(x.Reverse().ToArray()));
            foreach(string st in q)
            {
                Console.WriteLine(st);
            }
        }

        public Solver()
        {
            N = ri();
            s = new string[N];
            for (int i = 0; i < N; i++)
            {
                s[i] = rs();
            }
        }

        static String rs() { return Console.ReadLine(); }
        static int ri() { return int.Parse(Console.ReadLine()); }
        static long rl() { return long.Parse(Console.ReadLine()); }
        static double rd() { return double.Parse(Console.ReadLine()); }
        static String[] rsa() { return Console.ReadLine().Split(' '); }
        static int[] ria() { return Console.ReadLine().Split(' ').Select(e => int.Parse(e)).ToArray(); }
        static long[] rla() { return Console.ReadLine().Split(' ').Select(e => long.Parse(e)).ToArray(); }
        static double[] rda() { return Console.ReadLine().Split(' ').Select(e => double.Parse(e)).ToArray(); }
    }
}