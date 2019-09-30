using System;

namespace AGC026B
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Solver solver = new Solver();

            int t = int.Parse(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                long[] q = Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse);
                Console.WriteLine(solver.Solve(q[0], q[1], q[2], q[3]) ? "Yes" : "No");
            }
        }
    }

    class Solver
    {
        public bool Solve(long a, long b, long c, long d)
        {
            if (b > d | a < b)
            {
                return false;
            }

            long gcd = Gcd(d % b, b);
           // Console.Write(gcd + " ");
           // Console.WriteLine(b - gcd + a % gcd );
            return b - gcd + a % gcd <= c; 
        }

        public long Gcd(long a, long b)
        {
            if (a < b)
                // ??????????????
                return Gcd(b, a);
            while (b != 0)
            {
                var remainder = a % b;
                a = b;
                b = remainder;
            }

            return a;
        }
    }
}