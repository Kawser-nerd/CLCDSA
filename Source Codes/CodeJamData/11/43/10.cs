using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using System.Numerics;

namespace GCJDevKit.Solvers
{
    class C : AbstractSolver
    {
        protected override void PreSolve()
        {

            for (int i = 2; i <= N; i++)
            {
                if (isPrime(i))
                {
                    primes.Add(i);
                }
            }

            Console.WriteLine("Presort is ready");

            primes.Sort();
            
            table[1] = 0;
            table[2] = 1;
            table[3] = 1;

        }

        int[] table = new int[1001];

        List<long> primes = new List<long>();
        long N = 2000000;

        bool isPrime(int n)
        {
            if (n <= 2) return true;
            for (int i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                    return false;
            }
            return true;
        }

        int solveONe (long n)
        {
            //first up
            int d = 1;
            foreach (var prime in primes)
            {
                if (prime <= n)
                {
                    long p = prime;
                    while (p <= n)
                    {
                        d++;
                        p *= prime;
                    }
                }
            }

            foreach (var prime in primes)
            {
                if (prime <= n) d--;
            }

            return d;
        }

        protected override object Solve(System.IO.StreamReader input)
        {
            long n = NextLong();
            if (n <= 3)
                return table[n];
            else
                return
                    solveONe(n);
        }
    }
}
