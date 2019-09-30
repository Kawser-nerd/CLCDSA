using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC067D
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
        long N;
        long A;
        long B;
        long[] X;

        public void Solve()
        {
            long ans=0;
            for(int i=0;i< N-1; i++)
            {
                ans += Math.Min((X[i+1]-X[i])*A,B);
            }
            Console.WriteLine(ans);
        }

        public Solver()
        {
            long[] NAB = rla();
            N = NAB[0];
            A = NAB[1];
            B = NAB[2];
            X = rla();
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