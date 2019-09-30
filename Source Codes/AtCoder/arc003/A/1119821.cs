using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC003A
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
        string r;
        static Dictionary<char, int> dc = new Dictionary<char, int>() {
            { 'A', 4 },
            { 'B', 3 },
            { 'C', 2 },
            { 'D', 1 },
            { 'F', 0 } };

        public void Solve()
        {
            int sum = 0;
            foreach (char c in r)
            {
                sum += dc[c];
            }
            double ans = (double)sum / N;
            Console.WriteLine(ans);
        }

        public Solver()
        {
            N = ri();
            r = rs();
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